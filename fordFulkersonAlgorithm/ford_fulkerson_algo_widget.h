#ifndef FORD_FULKERSON_ALGO_WIDGET_H
#define FORD_FULKERSON_ALGO_WIDGET_H

#include <cmath>

#include <QWidget>
#include <QTableWidget>
#include <QDebug>

namespace Ui {
class FordFulkersonAlgoWidget;
}

class FordFulkersonAlgoWidget : public QWidget
{
    Q_OBJECT

public slots:
    void onPbApply();
    void onPbLaunch();

public:
    explicit FordFulkersonAlgoWidget(QWidget *parent = nullptr);
    ~FordFulkersonAlgoWidget();

    QVector<QVector<int>> major_arr;
    QStringList size_list;
    QStringList vertex_done_list;

    QTableWidget *adjacency_matrix_table;
    QTableWidget *major_matrix_table;

    int vertex_count;
    int start_vertex;
    int end_vertex;
    QVector<char> visited;

//    int capacity[INT_MAX], onEnd[INT_MAX], nextEdge[INT_MAX], edgeCount;
//    int firstEdge[INT_MAX];

    void checkFillArray();
//    int findFlow(int u, int flow);

private:
    Ui::FordFulkersonAlgoWidget *ui;
};

#endif // FORD_FULKERSON_ALGO_WIDGET_H
