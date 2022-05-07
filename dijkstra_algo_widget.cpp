#include "dijkstra_algo_widget.h"
#include "ui_dijkstra_algo_widget.h"


DijkstraAlgoWidget::DijkstraAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DijkstraAlgoWidget)
{
    ui->setupUi(this);

    size_list << "2x2" << "3x3" << "4x4" << "5x5" << "6x6" << "7x7" << "8x8" << "9x9" << "10x10";

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

void DijkstraAlgoWidget::onPbLaunch()
{
    QMap<QString, QMap<QString, int>> graph;
    QMap<QString, QString> distance;
    QMap<QString, QString> parents;

    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;

    qDebug() << graph["start"].keys();



    ui->verticalLayout_4->addWidget(major_matrix_table);
}
