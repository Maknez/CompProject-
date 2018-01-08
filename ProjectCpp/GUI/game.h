#ifndef GAME_H
#define GAME_H
#include <QObject>
#include <QDialog>
#include "box.h"

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
	Box *tableOfBoxes[12];
	int countOfCards;
	int points;
	QString pathToIcons;
	Box *prevBox;
	void initTheBoxes();
	void randomizeTheCards();
	void uncoverTheCard(Box *);
private:
};

#endif // GAME_H
