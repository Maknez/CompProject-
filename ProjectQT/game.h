#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "icon.h"

class Game : public QGraphicsView
{
    Q_OBJECT

	public:
		explicit Game(QWidget *parent = 0);
		~Game();
	private:

		int height = 525;
		int width = 400;

		bool frameFound = false;

		void game();
		void init();
		void createMenuScene();
		void createGameScene();
		void createFindFrameScene(QString, int);
		void createWinScene();

		QString pathToIcons = "C:/opencv/projectCpp/OtherFiles/memoryGameIcons/";

		Icon *tableOfIcons[12];
		Icon *prevBox;

		QGraphicsScene* menuScene;

		QPushButton *startTheGame;
		QPushButton *setupTheCamera;
		QPushButton *endTheGame;

		QGraphicsScene *gameScene;

		QPushButton *icon_1;
		QPushButton *icon_2;
		QPushButton *icon_3;
		QPushButton *icon_4;
		QPushButton *icon_5;
		QPushButton *icon_6;
		QPushButton *icon_7;
		QPushButton *icon_8;
		QPushButton *icon_9;
		QPushButton *icon_10;
		QPushButton *icon_11;
		QPushButton *icon_12;

		QGraphicsScene *winScene;
		QGraphicsScene *findFrameScene;

		QPushButton *continueBtn;

		void initTheBoxes();
		void randomizeTheCards();
		void uncoverTheCard(Icon *);

		int countOfCards = 0;
		int points = 0;

	private slots:
		void setMenuScene();
		void setGameScene();
		void closeWindow();
		void findFrame();
};

#endif // GAME_H
