#include "game.h"
#include "ui_game.h"
#include "settings.h"
#include "dialog.h"
#include "stdlib.h"
#include <iostream>

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
	this->pathToIcons = "/Users/parys/Desktop/gui/Images/";
	this->countOfCards = 0;
	this->points = 0;
    ui->setupUi(this);
	game();
}

Game::~Game()
{
    delete ui;
}
void Game::game() {
	initTheBoxes();
	randomizeTheCards();
	// rozgrywka
	do {
		int number = (rand() % static_cast<int>(12));
		uncoverTheCard(this->tableOfBoxes[number]);
	} while (this->points != 6);

	// for(int i = 0; i < 12; i++)
		// this->tableOfBoxes[i]->getButton()->setStyleSheet("background-image:url(" + this->pathToIcons + this->tableOfBoxes[i]->getImage() + ")");
}

void Game::initTheBoxes() {
	QPushButton *tableOfButtons[12] = {
		ui->pushButton,
		ui->pushButton_2,
		ui->pushButton_3,
		ui->pushButton_4,
		ui->pushButton_5,
		ui->pushButton_6,
		ui->pushButton_7,
		ui->pushButton_8,
		ui->pushButton_9,
		ui->pushButton_10,
		ui->pushButton_11,
		ui->pushButton_12
	};

	for (int i = 0; i < 12; i++) {
		this->tableOfBoxes[i] = new Box(tableOfButtons[i]);
	}
}

void Game::randomizeTheCards() {
	Settings setting;
	for (int i = 0; i < 12; i++) {
		this->tableOfBoxes[i]->setImage(setting.random(i) + ".gif");
	}
}

void Game::uncoverTheCard(Box *box) { 
	if (!(box->getCover())) {
		if (countOfCards < 2) {
			box->getButton()->setStyleSheet("background-image:url(" + this->pathToIcons + box->getImage() + ")");
			countOfCards++;
			if (countOfCards == 1) {
				this->prevBox = box;
			}
			if (countOfCards == 2) {
				if (box->getImage() != this->prevBox->getImage()) {
					this->prevBox->getButton()->setStyleSheet("background-image:url('')");
					box->getButton()->setStyleSheet("background-image:url('')");
					this->prevBox->setCover(false);
					box->setCover(false);
				}
				else if (box->getButton() != this->prevBox->getButton()) {
					this->points++;
					this->prevBox->setCover(true);
					box->setCover(true);
					if (points == 6) {
						Dialog *page = new Dialog("Zwyciestwo");
						page->setModal(true);
						page->exec();
					}
				}
				countOfCards = 0;
			}
		}
	}
}



