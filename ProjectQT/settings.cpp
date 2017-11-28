#include "settings.h"
#include "mainwindow.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    for(int i = 0; i < 12; i++) {
        QString file = QString::number(i+1) + ".wav";
        ui->comboBox->addItem(file);
        ui->comboBox_2->addItem(file);
        ui->comboBox_3->addItem(file);
        ui->comboBox_4->addItem(file);
        ui->comboBox_5->addItem(file);
        ui->comboBox_6->addItem(file);
        ui->comboBox_7->addItem(file);
        ui->comboBox_8->addItem(file);
        ui->comboBox_9->addItem(file);
        ui->comboBox_10->addItem(file);
        ui->comboBox_11->addItem(file);
        ui->comboBox_12->addItem(file);
    }
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    MainWindow w;
    w.setButton1(ui->comboBox->currentText());
    w.setButton2(ui->comboBox_2->currentText());
    w.setButton3(ui->comboBox_3->currentText());
    w.setButton4(ui->comboBox_4->currentText());
    w.setButton5(ui->comboBox_5->currentText());
    w.setButton6(ui->comboBox_6->currentText());
    w.setButton7(ui->comboBox_7->currentText());
    w.setButton8(ui->comboBox_8->currentText());
    w.setButton9(ui->comboBox_9->currentText());
    w.setButton10(ui->comboBox_10->currentText());
    w.setButton11(ui->comboBox_11->currentText());
    w.setButton12(ui->comboBox_12->currentText());
    this->close();
}
