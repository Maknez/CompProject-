#include "game.h"
#include "settings.h"
#include "stdlib.h"
#include <QGraphicsTextItem>
#include <QAbstractButton>
#include <QApplication>
#include <QWidget>
#include <QTime>
#include <QObject>

Game::Game(CV *computerVision, QWidget *parent) : QGraphicsView(parent)
{	
	this->computerVission = computerVision;
	QWidget::setWindowTitle("Memory Game");
	QGraphicsView::FullViewportUpdate;
	init();
}

Game::~Game(){}

void Game::init() {
	createMenuScene();
	createGameScene();
	createWinScene();
	setScene(menuScene);
}
void Game::createMenuScene() {
	menuScene = new QGraphicsScene();
	menuScene->setSceneRect(0, 0, this->width, this->height);

	this->startTheGame = new QPushButton("Start");
	this->startTheGame->move(0, 0);
	this->startTheGame->resize(400, 175);
	this->setupTheCamera = new QPushButton("Setup Camera");
	this->setupTheCamera->move(0, 175);
	this->setupTheCamera->resize(400, 175);
	this->endTheGame = new QPushButton("End");
	this->endTheGame->move(0, 350);
	this->endTheGame->resize(400, 175);

	connect(this->startTheGame, SIGNAL(clicked()), this, SLOT(setGameScene()));
	connect(this->setupTheCamera, SIGNAL(clicked()), this, SLOT(findFrame()));
	connect(this->endTheGame, SIGNAL(clicked()), this, SLOT(closeWindow()));

	menuScene->addWidget(this->startTheGame);
	menuScene->addWidget(this->setupTheCamera);
	menuScene->addWidget(this->endTheGame);
}

void Game::createGameScene() {
	initTheBoxes();
	gameScene = new QGraphicsScene(); 
	gameScene->setSceneRect(0, 0, this->width, this->height);

	int y = 0;
	int x = 0;
	int addX = 0;
	int addY = 25;

	for (int i = 0; i < 12; i++) {
		if (x % 3 == 0) {
			addY = (y * 125) + 25;
			addX = 25;
			y++;
			x = 0;
		} else {
			addX = (x * 125) + 25;
			if (x == 1)
				addX = (x * 125) + 25;
		}
		this->tableOfIcons[i]->getButton()->move(addX, addY);
		this->tableOfIcons[i]->getButton()->resize(100, 100);
		x++;
		gameScene->addWidget(this->tableOfIcons[i]->getButton());
	}
}

void Game::createWinScene() {
	winScene = new QGraphicsScene();
	winScene->setSceneRect(0, 0, this->width, this->height);
	QGraphicsTextItem *text = new QGraphicsTextItem("You Won");
	text->setPos(112, 150);
	QFont stringFont("arial", 30);
	text->setFont(stringFont);

	this->endTheGame = new QPushButton("Close");
	this->endTheGame->move(0, 350);
	this->endTheGame->resize(400, 175);

	connect(this->endTheGame, SIGNAL(clicked()), this, SLOT(closeWindow()));

	winScene->addWidget(this->endTheGame);
	winScene->addItem(text);
}

void Game::createFindFrameScene(QString info, int y) {
	findFrameScene = new QGraphicsScene();
	findFrameScene->setSceneRect(0, 0, this->width, this->height);
	QGraphicsTextItem *text = new QGraphicsTextItem(info);
	text->setPos(y, 150);
	QFont stringFont("arial", 30);
	text->setFont(stringFont);

	this->continueBtn = new QPushButton("Close");
	this->continueBtn->move(0, 350);
	this->continueBtn->resize(400, 175);

	connect(this->continueBtn, SIGNAL(clicked()), this, SLOT(setMenuScene()));

	findFrameScene->addWidget(this->continueBtn);
	findFrameScene->addItem(text);
	setScene(findFrameScene);
}

void Game::closeWindow() {
	this->close();
}
/************************************************************************/
void Game::findFrame() {
	// computerVission->openCam();
	// frameFound = computerVission->CVFrame();
	frameFound = false;
	if(!frameFound)
		createFindFrameScene("Found", 135);
	else
		createFindFrameScene("Not Found", 100);
}

void Game::setMenuScene() {
	setScene(menuScene);
}

void Game::setGameScene() {
	if(!frameFound) {
		setScene(gameScene);
		game();
	}
	else {
		createFindFrameScene("Setup Camera", 70);
	}
}

void Game::delay()
{
	QTime dieTime = QTime::currentTime().addSecs(1);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}
/************************************************************************/
void Game::game() { 
	randomizeTheCards();
	/* computerVission->openCam();
	Mat imgReaded;
	do {
		computerVission->vCapture.read(imgReaded);
		int number = computerVission->CVFlash(imgReaded);
		//cout << number;
		if (number != -1) {
			this->tableOfIcons[number]->emitClick();
		}
	} while (points != 6);
	cvDestroyWindow("Original");
	cvDestroyWindow("FlashView");
	computerVission->vCapture.release();*/
}

void Game::initTheBoxes() {
	QPushButton *tableOfButtons[12] = {
		this->icon_1 = new QPushButton(""),
		this->icon_2 = new QPushButton(""),
		this->icon_3 = new QPushButton(""),
		this->icon_4 = new QPushButton(""),
		this->icon_5 = new QPushButton(""),
		this->icon_6 = new QPushButton(""),
		this->icon_7 = new QPushButton(""),
		this->icon_8 = new QPushButton(""),
		this->icon_9 = new QPushButton(""),
		this->icon_10 = new QPushButton(""),
		this->icon_11 = new QPushButton(""),
		this->icon_12 = new QPushButton("")
	};

	for (int i = 0; i < 12; i++) {
		this->tableOfIcons[i] = new Icon(tableOfButtons[i]);
		this->tableOfIcons[i]->getButton();
	} 

	connect(this->tableOfIcons[0]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_1()));
	connect(this->tableOfIcons[1]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_2()));
	connect(this->tableOfIcons[2]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_3()));
	connect(this->tableOfIcons[3]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_4()));
	connect(this->tableOfIcons[4]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_5()));
	connect(this->tableOfIcons[5]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_6()));
	connect(this->tableOfIcons[6]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_7()));
	connect(this->tableOfIcons[7]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_8()));
	connect(this->tableOfIcons[8]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_9()));
	connect(this->tableOfIcons[9]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_10()));
	connect(this->tableOfIcons[10]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_11()));
	connect(this->tableOfIcons[11]->getButton(), SIGNAL(clicked()), this, SLOT(clicked_icon_12()));
}

void Game::randomizeTheCards() {
	Settings setting;
	for (int i = 0; i < 12; i++) {
		this->tableOfIcons[i]->setImage(setting.random(i) + ".gif");
	}
}
void Game::uncoverTheCard(Icon *box) {
	if (!(box->getCover())) {
		if (countOfCards < 2) {
			box->getButton()->setStyleSheet("background-image:url(" + this->pathToIcons + box->getImage() + ")");
			countOfCards++;
			if (countOfCards == 1) {
				this->prevBox = box;
			}
			if (countOfCards == 2) {
				stopEvents = true;
				delay();
				stopEvents = false;
				if (box->getImage() != this->prevBox->getImage()) {
					this->prevBox->getButton()->setStyleSheet("background-image:url('')");
					box->getButton()->setStyleSheet("background-image:url('')");
					this->prevBox->setCover(false);
					box->setCover(false);
					// PlaySound(TEXT("C:/opencv/projectCppSources/OtherFiles/testSounds/failure.wav"), NULL, SND_ASYNC);
				}
				else if (box->getButton() != this->prevBox->getButton()) {
					this->points++;
					this->prevBox->setCover(true);
					// PlaySound(TEXT("C:/opencv/projectCpp/OtherFilesSources/testSounds/success.wav"), NULL, SND_ASYNC);
					box->setCover(true);
					if (points == 6) {
						setScene(winScene);
					}
				}
				countOfCards = 0;
			}
		}
	}
}

void Game::clicked_icon_1() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[0]);
	}
}

void Game::clicked_icon_2() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[1]);
	}
}
void Game::clicked_icon_3() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[2]);
	}
}

void Game::clicked_icon_4() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[3]);
	}
}

void Game::clicked_icon_5() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[4]);
	}
}

void Game::clicked_icon_6() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[5]);
	}
}

void Game::clicked_icon_7() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[6]);
	}
}

void Game::clicked_icon_8() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[7]);
	}
}

void Game::clicked_icon_9() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[8]);
	}
}

void Game::clicked_icon_10() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[9]);
	}
}

void Game::clicked_icon_11() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[10]);
	}
}

void Game::clicked_icon_12() {
	if (!stopEvents) {
		uncoverTheCard(this->tableOfIcons[11]);
	}
}




