#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settings.h"
#include <QMainWindow>
#include <QComboBox>
#include <QFrame>
#include <QImage>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QResizeEvent>
#include <QSvgRenderer>
#include <QSvgWidget>
#include <QTextEdit>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    QSvgRenderer *Renderer;

private:
    QTimer *Timer;
    // UI
    QComboBox *Language;
    QSvgWidget *Image;
    QFrame *Discount;
    QFrame *MoneyLost;
    QLabel *DiscountTimeLeft;
    QLabel *MoneyLostTimeLeft;
    QLCDNumber *DiscountTime;
    QLCDNumber *MoneyLostTime;
    QSvgWidget *DiscountProgress;
    QSvgWidget *MoneyLostProgress;
    QLabel *Oops;
    QLabel *PaymentRaised;
    QLabel *YourFilesLost;
    QLabel *AboutBTC;
    QLabel *HowToBuyBTC;
    QLabel *ContactUs;\
    QLabel *Send;
    QLabel *BTCAddress;
    QTextEdit *Text;
    QSvgWidget *BTCIcon;
    QPushButton *Copy;
    QPushButton *CheckPayment;
    QPushButton *Decrypt;

private slots:
    void Resize(QResizeEvent *event);
    void ShowTime();

};

#endif // MAINWINDOW_H
