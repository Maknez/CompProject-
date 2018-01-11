#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QObject>

#include "../CV/CV.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
	bool frameFound;
	Ui::MainWindow *ui;

private slots:
	void startGame();
	void searchForFrame();
	void options();
	void exit();

private:
	CV computerVision;
};


