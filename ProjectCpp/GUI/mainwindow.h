#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
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
};

#endif // MAINWINDOW_H
