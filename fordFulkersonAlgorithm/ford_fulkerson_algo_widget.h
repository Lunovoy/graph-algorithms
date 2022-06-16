#ifndef FORD_FULKERSON_ALGO_WIDGET_H
#define FORD_FULKERSON_ALGO_WIDGET_H

#include <cmath>
#include <limits.h>
#include <queue>
#include <string.h>

#include <QWidget>
#include <QTableWidget>
#include <QDebug>

const int MAX_E = (int) 1e6;
const int MAX_V = (int) 1e3;
const int INF   = (int) 1e9;

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
    QVector<QVector<int>> minor_arr;

    int fordFulkerson(int s, int t);
    bool bfs(int s, int t, int parent[]);


//    int bfs(int v,int *parent);
//    int max_flow();



    QStringList size_list;
    QStringList vertex_done_list;

    QTableWidget *adjacency_matrix_table;
    QTableWidget *major_matrix_table;

    int vertex_count;
    int start_vertex;
    int end_vertex;

//    int capacity[INT_MAX], onEnd[INT_MAX], nextEdge[INT_MAX], edgeCount;
//    int firstEdge[INT_MAX];

    void checkFillArray();
    int findFlow(int u, int flow);

private:
    Ui::FordFulkersonAlgoWidget *ui;
};

#endif // FORD_FULKERSON_ALGO_WIDGET_H
