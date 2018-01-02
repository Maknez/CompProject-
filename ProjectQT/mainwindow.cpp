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
	this->frameFound = false;
	connect(ui->pushButton, SIGNAL(released()), this, SLOT(startGame()));
	connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(searchForFrame()));
	connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(options()));
	connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startGame()
{
	if (this->frameFound) {
		Game game;
		game.setModal(true);
		game.exec();
	} else {
		Dialog *page = new Dialog("Skalibruj ramke");
		page->setModal(true);
		page->exec();
	}
}

void MainWindow::searchForFrame()
{
	// wywolanie funkcji do odnalezienia ramki ktora zwraca true/false
	this->frameFound = true;
	Dialog *page = new Dialog("Powodzenie");
	page->setModal(true);
	page->exec();
}

void MainWindow::options() {
	// TODO nowe okno gdzie bedzie mozna przekalibrowac zakresy lapanych kolorow
}

void MainWindow::exit() {
	this->exit();
}
