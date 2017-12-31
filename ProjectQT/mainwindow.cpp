#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QPushButton>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton, SIGNAL(released()), this, SLOT(startGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startGame()
{
	Game game;
	game.setModal(true);
	game.exec();
}
