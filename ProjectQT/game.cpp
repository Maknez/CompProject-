#include "game.h"
#include "ui_game.h"
#include "logic.h"

Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{

    ui->setupUi(this);
	game();
}

Game::~Game()
{
    delete ui;
}
void Game::game() {
	initTheBoxes();
	//randomizeTheCards(play);
	//uncoverTheCard(play, play.box_1);
	//uncoverTheCard(play, play.box_2);
	//uncoverTheCard(play, play.box_1);
	//uncoverTheCard(play, play.box_2);


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


	//}
}



