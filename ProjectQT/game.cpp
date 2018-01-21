#include "game.h"
#include "settings.h"
#include "stdlib.h"
#include <QGraphicsTextItem>
#include <windows.h>
#pragma comment(lib, "Winmm.lib")

Game::Game(QWidget *parent) : QGraphicsView(parent)
{
	QWidget::setWindowTitle("Memory Game");
	init();
	setScene(menuScene);
}

Game::~Game(){}
void Game::init() {
	createMenuScene();
	createGameScene();
	createWinScene();
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
		this->tableOfIcons[i]->setButton(new QPushButton(""));
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
	QGraphicsTextItem *text = new QGraphicsTextItem("Your Won");
	text->setPos(110, 150);
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

void Game::findFrame() {
	frameFound = true; ///////////////////////////////////////////////////////////////
	if(frameFound)
		createFindFrameScene("Found", 135);
	else
		createFindFrameScene("Not Found", 100);
}

void Game::setMenuScene() {
	setScene(menuScene);
}

void Game::setGameScene() {
	if(frameFound) {
		setScene(gameScene);
		game();
	}
	else {
		createFindFrameScene("Setup Camera", 70);
	}
}

void Game::game() { /////////////////////////////////////////////////////
	randomizeTheCards();
	do {
		int number = (rand() % static_cast<int>(12));
		uncoverTheCard(this->tableOfIcons[number]); 
	} while (this->points != 6);

}

void Game::initTheBoxes() {
	QPushButton *tableOfButtons[12] = {
		this->icon_1,
		this->icon_2,
		this->icon_3,
		this->icon_4,
		this->icon_5,
		this->icon_6,
		this->icon_7,
		this->icon_8,
		this->icon_9,
		this->icon_10,
		this->icon_11,
		this->icon_12
	};

	for (int i = 0; i < 12; i++) {
		this->tableOfIcons[i] = new Icon(tableOfButtons[i]);
	} 
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
				if (box->getImage() != this->prevBox->getImage()) {
					this->prevBox->getButton()->setStyleSheet("background-image:url('')");
					box->getButton()->setStyleSheet("background-image:url('')");
					this->prevBox->setCover(false);
					box->setCover(false);
					PlaySound(TEXT("C:/opencv/projectCpp/OtherFiles/testSounds/failure.wav"), NULL, SND_FILENAME);
				}
				else if (box->getButton() != this->prevBox->getButton()) {
					this->points++;
					this->prevBox->setCover(true);
					PlaySound(TEXT("C:/opencv/projectCpp/OtherFiles/testSounds/success.wav"), NULL, SND_FILENAME);
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



