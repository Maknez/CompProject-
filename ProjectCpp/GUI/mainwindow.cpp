#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include <QPushButton>
#include "dialog.h"
#include "CV.h"
MainWindow::MainWindow() {};
MainWindow::MainWindow(CV *computerVision, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	this->computerVission = computerVision;
	ui->setupUi(this);
	this->frameFound = true;
	connect(ui->pushButton, SIGNAL(released()), this, SLOT(startGame()));
	connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(searchForFrame()));
	connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(options()));
	connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(exit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startGame() {
	//Bylo 	if (this->frameFound) ale zwraca zawsze false 
	if (!this->frameFound) {
		Game game(computerVission);
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
	this->frameFound = computerVission->CVFrame();
	
	//this->frameFound = true;
	//Funkcja CVFRame() zwraca zawsze false dlatego w startGame() zmienilismy 	if (!this->frameFound)
	Dialog *page = new Dialog("Kalibracja zakonczona powodzeniem");
	page->setModal(true);
	page->exec();
}

void MainWindow::options() {
	// TODO nowe okno gdzie bedzie mozna przekalibrowac zakresy lapanych kolorow
}

void MainWindow::exit() {
	this->close();
}
