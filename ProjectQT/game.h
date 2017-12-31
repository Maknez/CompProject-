#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <Box.h>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

	Box *prevBox;
	Box *tableOfBoxes[12];

	void game();
	void initTheBoxes();
	void clearCards();
	void randomizeTheCards();
	void uncoverTheCard(Box *);

	Ui::Game *ui;
private:
};

#endif // GAME_H
