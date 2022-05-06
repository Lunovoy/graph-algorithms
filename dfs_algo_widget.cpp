#include "dfs_algo_widget.h"
#include "ui_dfs_algo_widget.h"


DFSAlgoWidget::DFSAlgoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DFSAlgoWidget)
{
    ui->setupUi(this);

    size_list << "2x2" << "3x3" << "4x4" << "5x5" << "6x6" << "7x7" << "8x8" << "9x9" << "10x10";

    status_bar = new QStatusBar();
    ui->verticalLayout_13->insertWidget(0, status_bar);

    ui->cb_size_selection->addItems(size_list);

    ui->pb_launch->setDisabled(true);

    connect(ui->pb_apply, &QPushButton::clicked, this, &DFSAlgoWidget::onPbApply);
    connect(ui->pb_launch, &QPushButton::clicked, this, &DFSAlgoWidget::onPbLaunch);
}

DFSAlgoWidget::~DFSAlgoWidget()
{
    delete ui;
}


void DFSAlgoWidget::onPbApply()
{
    start_vertex = ui->le_vertex_input->text().toInt();
    qDebug() << start_vertex;

    if (start_vertex) {
        ui->pb_launch->setDisabled(false);
    }
}

void DFSAlgoWidget::onPbLaunch()
{

}
