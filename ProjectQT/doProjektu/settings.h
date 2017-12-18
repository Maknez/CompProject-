#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    bool validation(int);
    QString random(int iterator);
    QString toString(int);
    ~Settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
