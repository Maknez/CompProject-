#include "game.h"
#include "ui_game.h"
#include "dialog.h"
#include "settings.h"
#include <QPushButton>
#include <Box.h>

int countOfCards = 0;
int points = 0;
int tab[12];
QString pathToIcons = "/Users/michalparysz/Desktop/projectCpp/OtherFiles/memoryGameIcons/";

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
	game();
}

Box *prevBox;

Game::~Game()
{
    delete ui;
}
void Game::game() {
	initTheBoxes();
	randomizeTheCards();

}

void Game::initTheBoxes() {
	Game *game;
	QPushButton *tableOfButtons[12] = {
		game->ui->pushButton,
		game->ui->pushButton_2,
		game->ui->pushButton_3,
		game->ui->pushButton_4,
		game->ui->pushButton_5,
		game->ui->pushButton_6,
		game->ui->pushButton_7,
		game->ui->pushButton_8,
		game->ui->pushButton_9,
		game->ui->pushButton_10,
		game->ui->pushButton_11,
		game->ui->pushButton_12
	};

	for (int i = 0; i < 12; i++) {
		game->tableOfBoxes[i] = new Box(tableOfButtons[i]);
	}
}
void Game::randomizeTheCards() {
	for (int i = 0; i<12; i++) {
		tab[i] = NULL;
	}
	Settings setting;
	Game *game;
	for (int i = 0; i < 12; i++) {
		game->tableOfBoxes[i]->setImage(setting.random(i) + ".gif");
	}
}

void Game::uncoverTheCard(Box *box) { // to do
	Game *game;
	if (box->getImage() != " " && !box->getCover) {
		if (countOfCards < 2) {
			box->getButton()->setStyleSheet("background-image:url(" + pathToIcons + box->getImage() + ")");
			countOfCards++;
			if (countOfCards == 1) {
				game->prevBox = box;
			}
			if (countOfCards == 2) {
				if (box->getImage() != game->prevBox->getImage()) {
					game->prevBox->getButton()->setStyleSheet("background-image:url('')");
					box->getButton()->setStyleSheet("background-image:url('')");
				}
				else if (box->getButton() != game->prevBox->getButton()) {
					points++;
					game->prevBox->setCover(true);
					box->setCover(true);
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
		box->getButton()->setStyleSheet("background-image:url('')");
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

