#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "icon.h"
#include "CV.h"
class Game : public QGraphicsView
{
    Q_OBJECT

	public:
		explicit Game(CV *computerVision, QWidget *parent = 0);
		~Game();
		void init();
		void delay();
	private:
		QWidget *parent;

		int height = 525;
		int width = 400;
		CV *computerVission;
		bool frameFound = 1;

		void game();
		void createMenuScene();
		void createGameScene();
		void createFindFrameScene(QString, int);
		void createWinScene();

		QString pathToIcons = "C:/opencv/ProjectAppsSources/OtherFiles/memoryGameIcons/";

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
		void uncoverTheCard(Icon*);

		int countOfCards = 0;
		int points = 0;

	private slots:
		void setMenuScene();
		void setGameScene();
		void closeWindow();
		void findFrame();

		// Icons
		void clicked_icon_1();
		void clicked_icon_2();
		void clicked_icon_3();
		void clicked_icon_4();
		void clicked_icon_5();
		void clicked_icon_6();
		void clicked_icon_7();
		void clicked_icon_8();
		void clicked_icon_9();
		void clicked_icon_10();
		void clicked_icon_11();
		void clicked_icon_12();
};

#endif // GAME_H
