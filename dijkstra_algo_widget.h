#ifndef DIJKSTRA_ALGO_WIDGET_H
#define DIJKSTRA_ALGO_WIDGET_H

#include <math.h>

#include <QWidget>
#include <QStatusBar>
#include <QDebug>
#include <QTableWidget>
#include <QMap>
#include <QColor>



namespace Ui {
class DijkstraAlgoWidget;
}

class DijkstraAlgoWidget : public QWidget
{
    Q_OBJECT

public slots:
    void onPbApply();
    void onPbLaunch();
    void obPbCreateField();
    void MyEventHandler();

public:
    explicit DijkstraAlgoWidget(QWidget *parent = nullptr);
    ~DijkstraAlgoWidget();

    QVector<QVector<int>> major_arr;
    QStatusBar *status_bar;
    QStringList size_list;
    QVector<char> used;
    QVector<int> min_distance;

    QTableWidget *adjacency_matrix_table;
    QTableWidget *major_matrix_table;
    QTableWidget *play_field;

    QColor *green;
    QColor *black;
    QColor *red;

    uint vertex_count;
    uint start_vertex;

    void checkFillArray();
    void dijkstraAlgo();
    void setupPlayField();

private:
    Ui::DijkstraAlgoWidget *ui;
};

#endif // DIJKSTRA_ALGO_WIDGET_H
