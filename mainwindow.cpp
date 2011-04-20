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

        std::vector<int> arr;
        arr.push_back(a[i]);
        scene->addItem(new Vertex(QPointF(i * 50, 0), arr));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
