#include "dfs_algo_widget.h"
#include "ui_dfs_algo_widget.h"

DFSAlgoWidget::DFSAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFSAlgoWidget)
{
    ui->setupUi(this);
}

DFSAlgoWidget::~DFSAlgoWidget()
{
    delete ui;
}
