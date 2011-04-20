#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vertex.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600, 600);
    scene = new QGraphicsScene();
    ui->graphicsView->setRenderHints(QPainter::Antialiasing);
    ui->graphicsView->setScene(scene);

    n = 11;
    a = new int[n];
    for (int i = 0; i < n; i ++)
    {
        a[i] = (i * 3 + 2) % n + 1;
    }

    createSubarrayVertex(0, n, 0);
    mergeSort(0, n, NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mergeSort(int i, int j, Vertex *parent = NULL)
{
    Vertex *vertex = createSubarrayVertex(i, j, parent ? parent->yPos() + 70 : 0);
    if (parent)
        scene->addLine(QLineF(parent->bottomPoint(), vertex->topPoint()));

    if (i + 1 < j) // size > 1
    {
        int mid = (i + j) / 2;
        mergeSort(i, mid, vertex);
        mergeSort(mid, j, vertex);

        int *new_a = new int [j - i];
        int next1 = i; // next element in the first part of array
        int next2 = mid; // next element in the second part of array
        for (int k = 0; k < j - i; k ++)
        {
            if (next1 >= mid) // no elements left in the first part
            {
                new_a[k] = a[next2];
                next2 ++;
            }
            else if (next2 >= j)
            {
                new_a[k] = a[next1];
                next1 ++;
            }
            else if (a[next1] < a[next2])
            {
                new_a[k] = a[next1];
                next1 ++;
            }
            else // a[next1] >= a[next2]
            {
                new_a[k] = a[next2];
                next2 ++;
            }
        }

        for (int k = 0; k < j - i; k ++)
            a[i + k] = new_a[k];

        delete [] new_a;
    }
}

Vertex *MainWindow::createSubarrayVertex(int i, int j, qreal yPos)
{
    std::vector<int> arr;
    for (int k = i; k < j; k ++)
        arr.push_back(a[k]);

    Vertex *res = new Vertex(QPointF((i + j) * 25, yPos), arr);
    scene->addItem(res);
    return res;
}
