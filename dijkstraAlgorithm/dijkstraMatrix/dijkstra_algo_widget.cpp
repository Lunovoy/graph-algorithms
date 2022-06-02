#include "dijkstra_algo_widget.h"
#include "ui_dijkstra_algo_widget.h"


DijkstraAlgoWidget::DijkstraAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DijkstraAlgoWidget)
{
    ui->setupUi(this);

    size_list << "2x2" << "3x3" << "4x4" << "5x5" << "6x6" << "7x7" << "8x8" << "9x9" << "10x10";

    visual_dijkstra_widget = new VisualDijkstra();
    ui->verticalLayout_7->addWidget(visual_dijkstra_widget);

    status_bar = new QStatusBar();
    ui->verticalLayout_13->insertWidget(0, status_bar);

    ui->cb_size_selection->addItems(size_list);

    ui->pb_launch->setDisabled(true);

    connect(ui->pb_apply, &QPushButton::clicked, this, &DijkstraAlgoWidget::onPbApply);
    connect(ui->pb_launch, &QPushButton::clicked, this, &DijkstraAlgoWidget::onPbLaunch);
}

DijkstraAlgoWidget::~DijkstraAlgoWidget()
{
    delete ui;
}



void DijkstraAlgoWidget::onPbApply()
{
    start_vertex = ui->le_vertex_input->text().toInt();
    qDebug() << "Вершина, взятая из поля в onPbApply" << start_vertex;

    vertex_count = ui->cb_size_selection->currentIndex() + 2;

    if (start_vertex) {
        ui->pb_launch->setDisabled(false);
    }

    QList<QWidget *> widgets_left = ui->scrollAreaWidgetContents_3->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly);

    qDebug() << widgets_left;


    foreach(QWidget * child, widgets_left){
        qDebug() << "Удаление матрицы смежности";
        child->deleteLater();
    }


    QList<QWidget *> widgets_right = ui->scrollAreaWidgetContents_4->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly);

    qDebug() << widgets_right;

    foreach(QWidget * child, widgets_right){
        qDebug() << "Удаление результата";
        child->deleteLater();
    }


    major_matrix_table = new QTableWidget();
    adjacency_matrix_table = new QTableWidget();

    adjacency_matrix_table->setColumnCount(vertex_count);
    adjacency_matrix_table->setRowCount(vertex_count);

    major_matrix_table->setColumnCount(1);
    major_matrix_table->setRowCount(vertex_count);
    major_matrix_table->setHorizontalHeaderLabels(QStringList("Расстояние"));

    QStringList list;
    for (uint i = 1; i <= vertex_count; i ++) {
        list << QString::number(i);
    }
    adjacency_matrix_table->setHorizontalHeaderLabels(list);

    for (uint i = 0; i < vertex_count; i++) {
        adjacency_matrix_table->setColumnWidth(i, 50);
    }
    for (uint i = 0; i < vertex_count; i++) {
        adjacency_matrix_table->setRowHeight(i, 50);
    }

    ui->verticalLayout_3->addWidget(adjacency_matrix_table);
}

void DijkstraAlgoWidget::checkFillArray()
{

    for (uint i = 0; i < vertex_count; i ++) {
        for (uint j = 0; j < vertex_count; j ++) {
            if(!adjacency_matrix_table->item(i, j)){
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setText("inf");
                adjacency_matrix_table->setItem(i, j, item);
            }
            else if (adjacency_matrix_table->item(i, j)->text().isEmpty()){
                adjacency_matrix_table->item(i, j)->setText("inf");
            }
        }
    }

    min_distance.resize(vertex_count);

    major_arr.resize(vertex_count);
    for (uint i = 0; i < (uint)vertex_count; i++) {
        major_arr[i].resize(vertex_count);
    }

    used.resize(vertex_count);
    for (uint i = 0; i < (uint)vertex_count; i++) {
        used[i] = false;
    }


    for (uint i = 0; i < vertex_count; i++) {
        for (uint j = 0; j < vertex_count; j++) {
            if(adjacency_matrix_table->item(i, j)->text() == "inf") {
                major_arr[i][j] = INT_MAX;
            } else {
                major_arr[i][j] = adjacency_matrix_table->item(i, j)->text().toInt();
            }
        }
    }

    qDebug() << "Major_arr из checkFill" << major_arr;

}

void DijkstraAlgoWidget::dijkstraAlgo()
{



    for(uint i = 0; i < vertex_count; i++) {
        min_distance[i] = major_arr[start_vertex][i];
        used[i] = false;
    }

    min_distance[start_vertex]=0;
    int index = 0, u = 0;
    for (uint i = 0; i < vertex_count; i++) {
        int min=INT_MAX;

        for (uint j = 0; j < vertex_count; j++) {
            if (!used[j] && min_distance[j] < min) {
                min=min_distance[j];
                index=j;
            }
        }
        u=index;
        used[u]=true;
        for(uint j = 0; j < vertex_count; j++) {
            if (!used[j] && major_arr[u][j]!=INT_MAX && min_distance[u]!=INT_MAX && (min_distance[u]+major_arr[u][j]<min_distance[j])) {

                        min_distance[j]=min_distance[u]+major_arr[u][j];

            }
        }
    }
}

void DijkstraAlgoWidget::onPbLaunch()
{

    checkFillArray();

    --start_vertex;

    dijkstraAlgo();

    for (uint i = 0; i < vertex_count; i++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::number(min_distance[i]));
        item->setTextAlignment(Qt::AlignCenter);
        major_matrix_table->setItem(i, 0, item);
    }

    ui->verticalLayout_4->addWidget(major_matrix_table);
}

