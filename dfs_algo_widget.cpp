#include "dfs_algo_widget.h"
#include "ui_dfs_algo_widget.h"


DFSAlgoWidget::DFSAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFSAlgoWidget)
{
    ui->setupUi(this);

    size_list << "2x2" << "3x3" << "4x4" << "5x5" << "6x6" << "7x7" << "8x8" << "9x9" << "10x10";

    status_bar = new QStatusBar();
    ui->verticalLayout_13->insertWidget(0, status_bar);

    ui->cb_size_selection->addItems(size_list);

    ui->pb_launch->setDisabled(true);


    connect(ui->pb_apply, &QPushButton::clicked, this, &DFSAlgoWidget::onPbApply);
    connect(ui->pb_launch, &QPushButton::clicked, this, &DFSAlgoWidget::onPbLaunch);
}

DFSAlgoWidget::~DFSAlgoWidget()
{
    delete ui;
}


void DFSAlgoWidget::onPbApply()
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



    vertex_done_list.clear();

    qDebug() << "Used в onPbaplly: " << used;

    major_matrix_table = new QTableWidget();
    adjacency_matrix_table = new QTableWidget();

    adjacency_matrix_table->setColumnCount(vertex_count);
    adjacency_matrix_table->setRowCount(vertex_count);

    major_matrix_table->setColumnCount(vertex_count);
    major_matrix_table->setRowCount(vertex_count);

    QStringList list;
    for (uint i = 1; i <= (uint)vertex_count; i ++) {
        list << QString::number(i);
    }
    adjacency_matrix_table->setHorizontalHeaderLabels(list);

    for (uint i = 0; i < (uint)vertex_count; i++) {
        adjacency_matrix_table->setColumnWidth(i, 50);
    }
    for (uint i = 0; i < (uint)vertex_count; i++) {
        adjacency_matrix_table->setRowHeight(i, 50);
    }

    ui->verticalLayout_3->addWidget(adjacency_matrix_table);

}

void DFSAlgoWidget::checkFillArray() {


        major_arr.resize(vertex_count);
        for (uint i = 0; i < (uint)vertex_count; i++) {
            major_arr[i].resize(vertex_count);
        }

        used.resize(vertex_count);
        for (uint i = 0; i < (uint)vertex_count; i++) {
            used[i] = false;
        }


    for (int i = 0; i < adjacency_matrix_table->rowCount(); i++) {
        for (int j = 0; j < adjacency_matrix_table->columnCount(); j++) {

            major_arr[i][j] = adjacency_matrix_table->item(i, j)->text().toInt();
        }
    }

    for (int i = 0; i < adjacency_matrix_table->rowCount(); i++) {
        for (int j = 0; j < adjacency_matrix_table->columnCount(); j++) {

           qDebug() << major_arr[i][j];
        }
    }
    qDebug() << major_arr;
}

void DFSAlgoWidget::dfsAlgo(int v) {

    qDebug() << "Переданная вершина в dfs: " << v;
    used[v] = true;
    vertex_done_list << QString::number(v+1);
    for (int i = 0; i < vertex_count; ++i) {
        if(major_arr[v][i] == 1 && used[i] == false){
            dfsAlgo(i);
        }
    }
}

void DFSAlgoWidget::onPbLaunch()
{

    checkFillArray();

    start_vertex = ui->le_vertex_input->text().toInt();

    qDebug() << "Вершина, передаваемая в dfsAlgo" <<start_vertex;
    dfsAlgo(start_vertex-1);

    major_matrix_table->setVerticalHeaderLabels(vertex_done_list);

    ui->verticalLayout_4->addWidget(major_matrix_table);

}


