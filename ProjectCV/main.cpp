#include "game.h"
#include <QApplication>
CV *computerVision;
Game *game;

int main(int argc, char *argv[]) {
	computerVision = new CV();
    QApplication a(argc, argv);
	
	game = new Game(computerVision);
	game->show();

    return a.exec();
}
