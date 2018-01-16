#pragma once
#include <QObject>
#include <QDialog>
#include "box.h"
#include "CV.h"
namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(CV *computerVision, QWidget *parent = 0);
	~Game();
	void game();
	Ui::Game *ui;
	Box *tableOfBoxes[12];
	int countOfCards;
	int points;
	CV *computerVission;
	QString pathToIcons;
	Box *prevBox;
	void initTheBoxes();
	void randomizeTheCards();
	void uncoverTheCard(Box *);
private:
};


