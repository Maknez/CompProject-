#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "Box.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
	~Game();
	void game();
	Ui::Game *ui;
	/*Box box_1;
	Box box_2;
	Box box_3;
	Box box_4;
	Box box_5;
	Box box_6;
	Box box_7;
	Box box_8;
	Box box_9;
	Box box_10;
	Box box_11;
	Box box_12;*/
	Box *tableOfBoxes[12];
	int countOfCards;
	int points;
	QString pathToIcons;
	Box *prevBox;
	void initTheBoxes();
	// void clearCards();
	//void randomizeTheCards(Logic&);
	//void uncoverTheCard(Logic&, Box *);
private:
};

#endif // GAME_H
