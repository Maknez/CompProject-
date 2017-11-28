#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
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
    static QString button1;
    static QString button2;
    static QString button3;
    static QString button4;
    static QString button5;
    static QString button6;
    static QString button7;
    static QString button8;
    static QString button9;
    static QString button10;
    static QString button11;
    static QString button12;

private slots:
    void playSound(QString);
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();
    void on_toolButton_5_clicked();
    void on_toolButton_6_clicked();
    void on_toolButton_7_clicked();
    void on_toolButton_8_clicked();
    void on_toolButton_9_clicked();
    void on_toolButton_10_clicked();
    void on_toolButton_11_clicked();
    void on_toolButton_12_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
