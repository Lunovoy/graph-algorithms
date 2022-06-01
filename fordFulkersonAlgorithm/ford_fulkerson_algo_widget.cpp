#include "ford_fulkerson_algo_widget.h"
#include "ui_ford_fulkerson_algo_widget.h"

FordFulkersonAlgoWidget::FordFulkersonAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FordFulkersonAlgoWidget)
{
    ui->setupUi(this);

    size_list << "2x2" << "3x3" << "4x4" << "5x5" << "6x6" << "7x7" << "8x8" << "9x9" << "10x10";


    ui->cb_size_selection->addItems(size_list);

    ui->pb_launch->setDisabled(true);


    connect(ui->pb_apply, &QPushButton::clicked, this, &FordFulkersonAlgoWidget::onPbApply);
    connect(ui->pb_launch, &QPushButton::clicked, this, &FordFulkersonAlgoWidget::onPbLaunch);
}


FordFulkersonAlgoWidget::~FordFulkersonAlgoWidget()
{
    delete ui;
}

void FordFulkersonAlgoWidget::onPbApply()
{
    start_vertex = ui->le_vertex_start->text().toInt();
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

    qDebug() << "Used в onPbaplly: " << visited;

    adjacency_matrix_table = new QTableWidget();

    adjacency_matrix_table->setColumnCount(vertex_count);
    adjacency_matrix_table->setRowCount(vertex_count);

    QStringList hlist;
    hlist << "Порядок обхода";

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

void FordFulkersonAlgoWidget::checkFillArray() {


        major_arr.resize(vertex_count);
        for (uint i = 0; i < (uint)vertex_count; i++) {
            major_arr[i].resize(vertex_count);
        }

        visited.resize(vertex_count);
        for (uint i = 0; i < (uint)vertex_count; i++) {
            visited[i] = false;
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

void FordFulkersonAlgoWidget::onPbLaunch()
{

    checkFillArray();

    start_vertex = ui->le_vertex_start->text().toInt() - 1;

    qDebug() << "Вершина, передаваемая в FordFulkersonAlgo" <<start_vertex;

    end_vertex = ui->le_vertex_end->text().toInt() - 1;
    qDebug() << "Вершина, передаваемая в FordFulkersonAlgo" <<end_vertex;


        // Нахождение максимального потока
//        int maxFlow = 0;
//        int iterationResult = 0;
//        while ((iterationResult = findFlow(start_vertex, INT_MAX)) > 0) {
//            fill(visited, visited + MAX_V, false);
//            maxFlow += iterationResult;
//        }
//        // Выводим максимальный поток
//        qDebug() << "Макс поток: " << maxFlow;


//    ui->verticalLayout_4->addWidget(major_matrix_table);

}


//int FordFulkersonAlgoWidget::findFlow(int u, int flow) {
//    if (u == end_vertex) return flow; // возвращяем полученный минимум на пути
//    visited[u] = true;
//    for (int edge = firstEdge[u]; edge != -1; edge = nextEdge[edge]) {
//        int to = onEnd[edge];
//        if (!visited[to] && capacity[edge] > 0) {
//            int minResult = findFlow(to, min(flow, capacity[edge])); // ищем поток в поддереве
//            if (minResult > 0) {                    // если нашли
//                capacity[edge]      -= minResult;   // у прямых ребер вычетаем поток
//                capacity[edge ^ 1]  += minResult;   // к обратным прибавляем
//                return minResult;
//            }
//        }
//    }
//    return 0; // если не нашли поток из этой вершины вернем 0
//}


