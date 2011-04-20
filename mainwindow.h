#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mergeSort(int i, int j);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int n;
    int *a;
};

#endif // MAINWINDOW_H
