#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto graphics_scene = new QGraphicsScene(this);
    ui->boardView->setScene(graphics_scene);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            graphics_scene->addRect(QRectF(i * 64.0f, j * 64.0f, (i+1) * 64.0f, (j + 1) * 64.0f), QPen(), QBrush((i+j) % 2 == 0 ? QColor(68, 37, 33) : QColor(231, 198, 114)));

    game.SetupBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

