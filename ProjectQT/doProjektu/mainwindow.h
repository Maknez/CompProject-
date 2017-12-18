#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void clearCards();
    void setButton1(QString);
    void setButton2(QString);
    void setButton3(QString);
    void setButton4(QString);
    void setButton5(QString);
    void setButton6(QString);
    void setButton7(QString);
    void setButton8(QString);
    void setButton9(QString);
    void setButton10(QString);
    void setButton11(QString);
    void setButton12(QString);
    static QString image;
    static QString image2;
    static QString image3;
    static QString image4;
    static QString image5;
    static QString image6;
    static QString image7;
    static QString image8;
    static QString image9;
    static QString image10;
    static QString image11;
    static QString image12;
    static QPushButton *prev;
    static QString prevImage;

private slots:
    void uncoverTheCard(QPushButton *, QString);
    /*void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();*/
    void on_pushButton_13_clicked();
    void push_1();
    void push_2();
    void push_3();
    void push_4();
    void push_5();
    void push_6();
    void push_7();
    void push_8();
    void push_9();
    void push_10();
    void push_11();
    void push_12();
    //void on_pushButton_14_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
