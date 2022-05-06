#ifndef DFS_ALGO_WIDGET_H
#define DFS_ALGO_WIDGET_H

#include <QWidget>
#include <QStatusBar>
#include <QDebug>


namespace Ui {
class DFSAlgoWidget;
}

class DFSAlgoWidget : public QWidget
{
    Q_OBJECT

public slots:
    void onPbApply();
    void onPbLaunch();

public:
    explicit DFSAlgoWidget(QWidget *parent = nullptr);
    ~DFSAlgoWidget();

    QStatusBar *status_bar;
    QStringList size_list;

    int start_vertex;

private:
    Ui::DFSAlgoWidget *ui;
};

#endif // DFS_ALGO_WIDGET_H
