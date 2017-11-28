#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include "settings.h"
// #include <windows.h>
// #pragma comment(lib, "Winmm.lib")

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button1 = "1.wav";
    button2 = "2.wav";
    button3 = "3.wav";
    button4 = "4.wav";
    button5 = "5.wav";
    button6 = "6.wav";
    button7 = "7.wav";
    button8 = "8.wav";
    button9 = "9.wav";
    button10 = "10.wav";
    button11 = "11.wav";
    button12 = "12.wav";
}
QString MainWindow::button1;
QString MainWindow::button2;
QString MainWindow::button3;
QString MainWindow::button4;
QString MainWindow::button5;
QString MainWindow::button6;
QString MainWindow::button7;
QString MainWindow::button8;
QString MainWindow::button9;
QString MainWindow::button10;
QString MainWindow::button11;
QString MainWindow::button12;

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::playSound(QString path) {

    // MAC OS X -> /Users/michalparysz/Desktop/build-flashfinder-Desktop_Qt_5_9_2_clang_64bit-Debug/flashfinder.app/Contents/MacOS
    //path.prepend("java Sound ");

    //const char * command = path.toLocal8Bit().data();

    // WINDOWS -> C:/opencv/ProjectAppsBinaries/testSounds/3.wav
    //PlaySound(TEXT("C:/opencv/ProjectAppsBinaries/testSounds/" + command), NULL, SND_ASYNC);

    //system(command);
}
void MainWindow::setButton1(QString path) {
    this->button1 = path;
}
void MainWindow::setButton2(QString path) {
    this->button2 = path;
}
void MainWindow::setButton3(QString path) {
    this->button3 = path;
}
void MainWindow::setButton4(QString path) {
    this->button4 = path;
}
void MainWindow::setButton5(QString path) {
    this->button5 = path;
}
void MainWindow::setButton6(QString path) {
    this->button6 = path;
}
void MainWindow::setButton7(QString path) {
    this->button7 = path;
}
void MainWindow::setButton8(QString path) {
    this->button8 = path;
}
void MainWindow::setButton9(QString path) {
    this->button9 = path;
}
void MainWindow::setButton10(QString path) {
    this->button10 = path;
}
void MainWindow::setButton11(QString path) {
    this->button11 = path;
}
void MainWindow::setButton12(QString path) {
    this->button12 = path;
}
void MainWindow::on_toolButton_clicked()
{
    //system("pwd");
    playSound(button1);
}

void MainWindow::on_toolButton_2_clicked()
{
    playSound(button2);
}

void MainWindow::on_toolButton_3_clicked()
{
    playSound(button3);
}
void MainWindow::on_toolButton_4_clicked()
{
    playSound(button4);
}
void MainWindow::on_toolButton_5_clicked()
{
    playSound(button5);
}
void MainWindow::on_toolButton_6_clicked()
{
    playSound(button6);
}
void MainWindow::on_toolButton_7_clicked()
{
    playSound(button7);
}
void MainWindow::on_toolButton_8_clicked()
{
    playSound(button8);
}
void MainWindow::on_toolButton_9_clicked()
{
    playSound(button9);
}
void MainWindow::on_toolButton_10_clicked()
{
    playSound(button10);
}
void MainWindow::on_toolButton_11_clicked()
{
    playSound(button11);
}
void MainWindow::on_toolButton_12_clicked()
{
    playSound(button12);
}

void MainWindow::on_pushButton_clicked()
{
    Settings page;
    page.setModal(true);
    page.exec();
}

