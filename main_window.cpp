#include "main_window.h"
#include "ui_main_window.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dfs_widget = new DFSAlgoWidget();
    warshall_widget = new WarshallAlgoWidget();

    ui->verticalLayout_12->addWidget(dfs_widget);
    ui->verticalLayout_2->addWidget(warshall_widget);


}





MainWindow::~MainWindow()
{

    delete ui;
}

