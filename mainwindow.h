#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

namespace Ui {
    class MainWindow;
}

class Vertex;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mergeSort(int i, int j, Vertex *vertex);
    Vertex *createSubarrayVertex(int i, int j, qreal yPos);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int n;
    int *a;
};

#endif // MAINWINDOW_H
