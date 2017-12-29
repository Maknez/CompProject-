#include "game.h"
#include "ui_game.h"
#include "dialog.h"
#include "settings.h"
#include <QPushButton>

int countOfCards = 0;
int points = 0;
QString pathToIcons = "/Users/michalparysz/Desktop/projectCpp/OtherFiles/memoryGameIcons/";

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

void Game::uncoverTheCard(QPushButton *button, QString image) {
	if (image != " ") {
		if (countOfCards < 2) {
			button->setStyleSheet("background-image:url(" + pathToIcons + image + ")");
			countOfCards++;
			if (countOfCards == 1) {
				prevImage = image;
				prev = button;
			}
			if (countOfCards == 2) {
				if (image != prevImage) {
					prev->setStyleSheet("background-image:url('')");
					button->setStyleSheet("background-image:url('')");
				}
				else if (button != prev) {
					points++;
					if (points == 6) {
						clearCards();
						Dialog page;
						page.setModal(true);
						page.exec();
					}
				}
				countOfCards = 0;
			}
		}
	}
	else {
		button->setStyleSheet("background-image:url('')");
	}
}

void Game::clearCards() {
	uncoverTheCard(ui->pushButton, " ");
	uncoverTheCard(ui->pushButton_2, " ");
	uncoverTheCard(ui->pushButton_3, " ");
	uncoverTheCard(ui->pushButton_4, " ");
	uncoverTheCard(ui->pushButton_5, " ");
	uncoverTheCard(ui->pushButton_6, " ");
	uncoverTheCard(ui->pushButton_7, " ");
	uncoverTheCard(ui->pushButton_8, " ");
	uncoverTheCard(ui->pushButton_9, " ");
	uncoverTheCard(ui->pushButton_10, " ");
	uncoverTheCard(ui->pushButton_11, " ");
	uncoverTheCard(ui->pushButton_12, " ");
}

void Game::on_pushButton_13_clicked()
{
	clearCards();
	countOfCards = 0;
	Settings page;
	page.setModal(true);
	page.exec();
}
