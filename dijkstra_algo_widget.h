#ifndef DIJKSTRA_ALGO_WIDGET_H
#define DIJKSTRA_ALGO_WIDGET_H

#include <QWidget>
#include <QStatusBar>
#include <QDebug>
#include <QTableWidget>
#include <QMap>


namespace Ui {
class DijkstraAlgoWidget;
}

class DijkstraAlgoWidget : public QWidget
{
    Q_OBJECT

public slots:
    void onPbApply();
    void onPbLaunch();

public:
    explicit DijkstraAlgoWidget(QWidget *parent = nullptr);
    ~DijkstraAlgoWidget();

    QVector<QVector<int>> major_arr;
    QStatusBar *status_bar;
    QStringList size_list;
    QVector<char> used;
    QVector<int> distance;

    QTableWidget *adjacency_matrix_table;
    QTableWidget *major_matrix_table;

    int vertex_count;
    int start_vertex;

    void checkFillArray();
    void dijkstraAlgo();

private:
    Ui::DijkstraAlgoWidget *ui;
};

#endif // DIJKSTRA_ALGO_WIDGET_H
