#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QObject>

#include "CV.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(CV *computerVision, QWidget *parent = 0);
	MainWindow();
    ~MainWindow();
	bool frameFound;
	Ui::MainWindow *ui;
	CV *computerVission;
private slots:
	void startGame();
	void searchForFrame();
	void options();
	void exit();

private:
};


