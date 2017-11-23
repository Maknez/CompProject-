#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <windows.h>

//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")


using namespace std;
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

void MainWindow::on_toolButton_1_clicked()
{
	PlaySound(TEXT("c.wav"), NULL, SND_ASYNC);
 }

void MainWindow::on_toolButton_2_clicked()
{
	PlaySound(TEXT("cis.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_3_clicked()
{
	PlaySound(TEXT("d.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_4_clicked()
{
	PlaySound(TEXT("dis.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_5_clicked()
{
	PlaySound(TEXT("e.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_6_clicked()
{
	PlaySound(TEXT("f.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_7_clicked()
{
 	PlaySound(TEXT("fis.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_8_clicked()
{
 	PlaySound(TEXT("g.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_9_clicked()
{
 	PlaySound(TEXT("gis.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_10_clicked()
{
 	PlaySound(TEXT("a.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_11_clicked()
{
 	PlaySound(TEXT("ais.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_12_clicked()
{
 	PlaySound(TEXT("h.wav"), NULL, SND_ASYNC);
}

void MainWindow::on_toolButton_13_clicked()
{
	PlaySound(TEXT("c2.wav"), NULL, SND_ASYNC);
}
