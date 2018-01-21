#include "mainwindow.h"
#include <QApplication>
CV *computerVision;

int main(int argc, char *argv[]) {
	computerVision = new CV();
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow(computerVision);
    w->show();

    return a.exec();
}
