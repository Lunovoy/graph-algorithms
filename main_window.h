#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "QDebug"
#include "QStatusBar"
#include "QString"
#include "QVector"
#include "QString"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void onPbApply1();
    void onPbLaunch1();


public:

    QVector<QVector<int>> major_arr;
    QVector<QVector<int>> minor_arr;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    QStatusBar *status_bar;
    QStringList size_list;
    QTableWidget *adjacency_matrix_table;
    QTableWidget *major_matrix_table;
    QTableWidget *minor_matrix_table;
    void checkFillArray();
    void warshallAlgo();
    void setResultMatrixTable();
private:
};
#endif // MAIN_WINDOW_H
