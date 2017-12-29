#ifndef GAME_H
#define GAME_H

#include <QDialog>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
	void clearCards();
	static QPushButton *prev;
	static QString prevImage;
	void on_pushButton_13_clicked();
	void uncoverTheCard(QPushButton *, QString);

private:
    Ui::Game *ui;
};

#endif // GAME_H
