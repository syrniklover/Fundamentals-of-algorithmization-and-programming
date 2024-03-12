#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(350, 750);
    ui->graphicsView->setAlignment(Qt::AlignBottom);
    setFixedSize( 600, 800 );

    //Пиплы
    rectangle =     new Rectangle;
    elevator =      new Elevator;
    personRed =     new People(1, Qt::red, "Red");
    personGreen =   new People(2, Qt::green, "Green");
    personBlue =    new People(3, Qt::blue, "Blue");

    //Добавляем на сцену дичь
    scene->addItem(personRed);
    scene->addItem(personGreen);
    scene->addItem(personBlue);
    scene->addItem(rectangle);
    scene->addItem(elevator);
    scene->addLine(0, -250, 350, -250);
    scene->addLine(0, 0, 350, 0);
    rectangle->setZValue(-1);
    elevator->setZValue(100);

    //Коннектим кнопки
    connect(ui->Floor1, &QPushButton::clicked, this, &MainWindow::handleFloor1Clicked);
    connect(ui->Floor2, &QPushButton::clicked, this, &MainWindow::handleFloor2Clicked);
    connect(ui->Floor3, &QPushButton::clicked, this, &MainWindow::handleFloor3Clicked);

    connect(ui->buttonRed, &QPushButton::clicked, this, &MainWindow::handleRedClicked);
    connect(ui->buttonGreen, &QPushButton::clicked, this, &MainWindow::handleGreenClicked);
    connect(ui->buttonBlue, &QPushButton::clicked, this, &MainWindow::handleBlueClicked);

    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleFloor1Clicked()
{
    rectangle->setFloor(1);
    elevator->setFloor(1);
    personRed->setFloor(1);
    personGreen->setFloor(1);
    personBlue->setFloor(1);
}

void MainWindow::handleFloor2Clicked()
{
    rectangle->setFloor(2);
    elevator->setFloor(2);
    personRed->setFloor(2);
    personGreen->setFloor(2);
    personBlue->setFloor(2);
}

void MainWindow::handleFloor3Clicked()
{
    rectangle->setFloor(3);
    elevator->setFloor(3);
    personRed->setFloor(3);
    personGreen->setFloor(3);
    personBlue->setFloor(3);
}

void MainWindow::handleRedClicked()
{
    if(rectangle->floor == personRed->getFloor())
        personRed->enter();
}

void MainWindow::handleGreenClicked()
{
    if(rectangle->floor == personGreen->getFloor())
        personGreen->enter();
}

void MainWindow::handleBlueClicked()
{
    if(rectangle->floor == personBlue->getFloor())
        personBlue->enter();
}

