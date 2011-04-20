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

    mergeSort(0, n);

    for (int i = 0; i < n; i ++)
    {
        std::vector<int> arr;
        arr.push_back(a[i]);
        scene->addItem(new Vertex(QPointF(i * 50, 0), arr));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mergeSort(int i, int j)
{
    if (i + 1 == j) // size = 1
    {
    }
    else // size > 1
    {
        int mid = (i + j) / 2;
        mergeSort(i, mid);
        mergeSort(mid, j);

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
