#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    system("pwd");
    system("java Sound beep.wav");
}

void MainWindow::on_toolButton_2_clicked()
{
    system("java Sound beep2.wav");
}

void MainWindow::on_toolButton_3_clicked()
{
    system("java Sound beep3.wav");
}

void MainWindow::on_toolButton_6_clicked()
{
    system("java Sound beep4.wav");
}

void MainWindow::on_toolButton_4_clicked()
{
    system("say H");
}

void MainWindow::on_toolButton_5_clicked()
{
    system("say E");
}

void MainWindow::on_toolButton_9_clicked()
{
    system("say L");
}

void MainWindow::on_toolButton_7_clicked()
{
    system("say L");
}

void MainWindow::on_toolButton_8_clicked()
{
    system("say O");
}

void MainWindow::on_toolButton_10_clicked()
{
    system("say U");
}

void MainWindow::on_toolButton_11_clicked()
{
    system("say A");
}

void MainWindow::on_toolButton_12_clicked()
{
    system("say P");
}
