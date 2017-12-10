#include "settings.h"
#include "mainwindow.h"
#include "ui_settings.h"
#include "stdlib.h"
#include <iostream>
int tab[12];
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    //for(int i = 0; i < 6; i++) {
    //  QString file = QString::number(i+1) + ".wav";
    //}
}

Settings::~Settings()
{
    delete ui;
}
bool Settings::validation(int number) {
    int hits = 0;
    for(int i = 0; i < 12; i++) {
        if(tab[i] == number) {
            hits++;
        }
    }
    if(hits == 2) {
        return false;
    }
    return true;
}
QString Settings::random(int iterator) {
    int number;
    do {
        number = 1 + (rand() % static_cast<int>(6));
    } while(!validation(number));
    tab[iterator] = number;
    return toString(number);
}

QString Settings::toString(int number) {
    return QString::number(number);
}

void Settings::on_pushButton_clicked()
{
    MainWindow w;
    w.setButton1(random(0));
    w.setButton2(random(1));
    w.setButton3(random(2));
    w.setButton4(random(3));
    w.setButton5(random(4));
    w.setButton6(random(5));
    w.setButton7(random(6));
    w.setButton8(random(7));
    w.setButton9(random(8));
    w.setButton10(random(9));
    w.setButton11(random(10));
    w.setButton12(random(11));
    this->close();
}
