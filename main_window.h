#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "dfs_algo_widget.h"
#include "warshall_algo_widget.h"
#include "dijkstra_algo_widget.h"
#include "ford_fulkerson_algo_widget.h"

#include <QMainWindow>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    DFSAlgoWidget *dfs_widget;
    WarshallAlgoWidget *warshall_widget;
    DijkstraAlgoWidget *dijkstra_widget;
    FordFulkersonAlgoWidget *ford_fulkerson_widget;



    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

private:
};
#endif // MAIN_WINDOW_H
