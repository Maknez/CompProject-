#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include "settings.h"
#include "dialog.h"
#include <QPushButton>
//#include <unistd.h>
// #include <windows.h>
// #pragma comment(lib, "Winmm.lib")

// ŚCIEŻKA DO IKON ZMIENIĆ JEŚLI NA WINDZIE
QString pathToIcons = "C:/opencv/ProjectAppsSources/OtherFiles/memoryGameIcons/";

int countOfCards = 0;
int points = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image = "1.gif";
    image2 = "2.gif";
    image3 = "3.gif";
    image4 = "4.gif";
    image5 = "5.gif";
    image6 = "6.gif";
    image7 = "1.gif";
    image8 = "2.gif";
    image9 = "3.gif";
    image10 = "4.gif";
    image11 = "5.gif";
    image12 = "6.gif";
}
QString MainWindow::image;
QString MainWindow::image2;
QString MainWindow::image3;
QString MainWindow::image4;
QString MainWindow::image5;
QString MainWindow::image6;
QString MainWindow::image7;
QString MainWindow::image8;
QString MainWindow::image9;
QString MainWindow::image10;
QString MainWindow::image11;
QString MainWindow::image12;

QPushButton *MainWindow::prev;
QString MainWindow::prevImage;


//PlaySound(TEXT("C:/opencv/..pathtotrack.."), NULL, SND_ASYNC); to do

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::uncoverTheCard(QPushButton *button, QString image) {
    if(image != " ") {
        if(countOfCards < 2) {
            button->setStyleSheet("background-image:url(" + pathToIcons + image + ")");
            countOfCards++;
            if(countOfCards == 1) {
                prevImage = image;
                prev = button;
            }
            if(countOfCards == 2) {
                if(image != prevImage) {
                    // for(long i = 0; i < 200000000; i++);
                    // usleep(1000000);
                    prev->setStyleSheet("background-image:url('')");
                    button->setStyleSheet("background-image:url('')");
                } else if (button != prev){
                    points++;
                    if(points == 6) {
                        clearCards();
                        Dialog page;
                        page.setModal(true);
                        page.exec();
                    }
                }
                countOfCards = 0;
            }
        }
    } else {
        button->setStyleSheet("background-image:url('')");
    }
}

void MainWindow::clearCards() {
    uncoverTheCard(ui->pushButton, " ");
    uncoverTheCard(ui->pushButton_2, " ");
    uncoverTheCard(ui->pushButton_3, " ");
    uncoverTheCard(ui->pushButton_4, " ");
    uncoverTheCard(ui->pushButton_5, " ");
    uncoverTheCard(ui->pushButton_6, " ");
    uncoverTheCard(ui->pushButton_7, " ");
    uncoverTheCard(ui->pushButton_8, " ");
    uncoverTheCard(ui->pushButton_9, " ");
    uncoverTheCard(ui->pushButton_10, " ");
    uncoverTheCard(ui->pushButton_11, " ");
    uncoverTheCard(ui->pushButton_12, " ");
}

void MainWindow::setButton1(QString path) {
    this->image = path;
}
void MainWindow::setButton2(QString path) {
    this->image2 = path;
}
void MainWindow::setButton3(QString path) {
    this->image3 = path;
}
void MainWindow::setButton4(QString path) {
    this->image4 = path;
}
void MainWindow::setButton5(QString path) {
    this->image5 = path;
}
void MainWindow::setButton6(QString path) {
    this->image6 = path;
}
void MainWindow::setButton7(QString path) {
    this->image7 = path;
}
void MainWindow::setButton8(QString path) {
    this->image8 = path;
}
void MainWindow::setButton9(QString path) {
    this->image9 = path;
}
void MainWindow::setButton10(QString path) {
    this->image10 = path;
}
void MainWindow::setButton11(QString path) {
    this->image11 = path;
}
void MainWindow::setButton12(QString path) {
    this->image12 = path;
}

// funkcje do podlaczenia ktore trzeba wywolac w glownym projekcie po wykryciu blysku
void MainWindow::push_1() {
    uncoverTheCard(ui->pushButton, image);
}
void MainWindow::push_2() {
    uncoverTheCard(ui->pushButton_2, image2);
}
void MainWindow::push_3() {
    uncoverTheCard(ui->pushButton_3, image3);
}
void MainWindow::push_4() {
    uncoverTheCard(ui->pushButton_4, image4);
}
void MainWindow::push_5() {
    uncoverTheCard(ui->pushButton_5, image5);
}
void MainWindow::push_6() {
    uncoverTheCard(ui->pushButton_6, image6);
}
void MainWindow::push_7() {
    uncoverTheCard(ui->pushButton_7, image7);
}
void MainWindow::push_8() {
    uncoverTheCard(ui->pushButton_8, image8);
}
void MainWindow::push_9() {
    uncoverTheCard(ui->pushButton_9, image9);
}
void MainWindow::push_10() {
    uncoverTheCard(ui->pushButton_10, image10);
}
void MainWindow::push_11() {
    uncoverTheCard(ui->pushButton_11, image11);
}
void MainWindow::push_12() {
    uncoverTheCard(ui->pushButton_12, image12);
}
//////////////////
/// funkcje wywolywane po kliknieciu przycisku, do testow tylko
///
/*
void MainWindow::on_pushButton_clicked()
{
    uncoverTheCard(ui->pushButton, image);
}
void MainWindow::on_pushButton_2_clicked()
{
    uncoverTheCard(ui->pushButton_2, image2);
}
void MainWindow::on_pushButton_3_clicked()
{
    uncoverTheCard(ui->pushButton_3, image3);
}
void MainWindow::on_pushButton_4_clicked()
{
    uncoverTheCard(ui->pushButton_4, image4);
}
void MainWindow::on_pushButton_5_clicked()
{
    uncoverTheCard(ui->pushButton_5, image5);
}
void MainWindow::on_pushButton_6_clicked()
{
    uncoverTheCard(ui->pushButton_6, image6);
}
void MainWindow::on_pushButton_7_clicked()
{
    uncoverTheCard(ui->pushButton_7, image7);
}
void MainWindow::on_pushButton_8_clicked()
{
    uncoverTheCard(ui->pushButton_8, image8);
}
void MainWindow::on_pushButton_9_clicked()
{
    uncoverTheCard(ui->pushButton_9, image9);
}
void MainWindow::on_pushButton_10_clicked()
{
    uncoverTheCard(ui->pushButton_10, image10);
}
void MainWindow::on_pushButton_11_clicked()
{
    uncoverTheCard(ui->pushButton_11, image11);
}
void MainWindow::on_pushButton_12_clicked()
{
    uncoverTheCard(ui->pushButton_12, image12);
}*/

// Przycisk do nowego okna w ktorym mamy mozliwosc rozpoczecia gry od nowa
void MainWindow::on_pushButton_13_clicked()
{
    clearCards();
    countOfCards = 0;
    Settings page;
    page.setModal(true);
    page.exec();
}
// przycisk do kalibracjo obrazu
// void MainWindow::on_pushButton_14_clicked()
//{
 // trzeba sciagnac funkcje z glownego projektu ktora bedzie wywolywana po nacisnieciu przycisku
//}
