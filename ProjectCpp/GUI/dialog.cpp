#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QString info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
	this->info = info;
    ui->setupUi(this);
    ui->label->setText(this->info);
}

Dialog::~Dialog()
{
    delete ui;
}
