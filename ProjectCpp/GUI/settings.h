#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

//Krzyczy ponizszy include nie mam pojecia dlaczego. po wykomentowaniu program odpala sie tak czy siak :d
//#include <mainwindow.h>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
