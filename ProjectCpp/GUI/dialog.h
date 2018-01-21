#pragma once
#include <QDialog>
#include <QObject>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QString, QWidget *parent = 0);
    ~Dialog();
	QString info;

private:
    Ui::Dialog *ui;
};


