#include "mainwindow.h"
#include <QDateTime>
#include <QGridLayout>
#include <QLayout>
#include <QImage>
#include <QPainter>
#include <QSettings>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Load svg
    Image = new QSvgWidget(":/WanaCrypt0r.svg");
    DiscountProgress = new QSvgWidget(":/progress.svg");
    MoneyLostProgress = new QSvgWidget(":/progress.svg");
    BTCIcon = new QSvgWidget(":/bitcoinAccept.svg");
    // UI
    Discount = new QFrame;
    PaymentRaised = new QLabel;
    PaymentRaised->setStyleSheet("color: yellow");
    PaymentRaised->setText("Payment will be raised on:");
    QDateTime Toworrow = QDateTime::currentDateTime().addDays(1);
    DiscountTimeLeft = new QLabel;
    DiscountTimeLeft->setStyleSheet("color: white");
    DiscountTimeLeft->setText(Toworrow.toString("m/d/yyyy hh:mm:ss") + "\nTime Left");
    DiscountTime = new QLCDNumber(Discount);
    DiscountTime->setDigitCount(9);
    DiscountTime->display("24:00:00");
    DiscountProgress = new QSvgWidget(":/progress.svg");
    MoneyLost = new QFrame;
    YourFilesLost = new QLabel;
    YourFilesLost->setStyleSheet("color: yellow");
    YourFilesLost->setText("Your files will be lost on:");
    QDateTime Days = QDateTime::currentDateTime().addDays(3);
    MoneyLostTimeLeft = new QLabel;
    MoneyLostTimeLeft->setStyleSheet("color: white");
    MoneyLostTimeLeft->setText(Days.toString("m/d/yyyy hh:mm:ss") + "\nTime Left");
    MoneyLostTime = new QLCDNumber(MoneyLost);
    MoneyLostTime->setDigitCount(9);
    MoneyLostTime->display("72:00:00");
    MoneyLostProgress = new QSvgWidget(":/progress.svg");
    MoneyLostProgress->setMaximumSize(210, 80);
    Oops = new QLabel;
    Oops->setStyleSheet("color: white; font-weight: bold");
    Oops->setText("Oops, Your files have been encrypted!");
    Send = new QLabel;
    Send->setText("Send $300 worth of bitcoin to this address:");
    Language = new QComboBox;
    Language->setStyleSheet("background: white");
    Language->addItem("Chinses");
    Language->addItem("English");
    Text = new QTextEdit;
    Text->setReadOnly(true);
    Text->setStyleSheet("background: white");
    Text->setText("");
    BTCAddress = new QLabel;
    BTCAddress->setText("");
    Copy = new QPushButton;
    Copy->setText("Copy");
    CheckPayment = new QPushButton;
    CheckPayment->setText("Check Payment");
    Decrypt = new QPushButton;
    Decrypt->setText("Decrypt");
    AboutBTC = new QLabel;
    AboutBTC->setText("<a href='#' style='color: white'>About bitcoin</a>");
    HowToBuyBTC = new QLabel;
    HowToBuyBTC->setText("<a href='#' style='color: white'>How to buy bitcoin?</a>");
    ContactUs = new QLabel;
    ContactUs->setText("<strong><a href='#' style='color: white'>Contcat Us</a></strong>");
    // Layout
    QGridLayout *DiscountLayout = new QGridLayout;
    DiscountLayout->addWidget(PaymentRaised, 0, 1);
    DiscountLayout->addWidget(DiscountTimeLeft, 1, 1);
    DiscountLayout->addWidget(DiscountTime, 2, 1);
    DiscountLayout->addWidget(DiscountProgress, 1, 2);
    Discount->setLayout(DiscountLayout);
    QGridLayout *MoneyLostLayout = new QGridLayout;
    MoneyLostLayout->addWidget(YourFilesLost, 0, 1);
    MoneyLostLayout->addWidget(MoneyLostTimeLeft, 1, 1);
    MoneyLostLayout->addWidget(MoneyLostTime, 2, 1);
    MoneyLostLayout->addWidget(MoneyLostProgress, 1, 2);
    MoneyLost->setLayout(MoneyLostLayout);
    QVBoxLayout *LinkLayout = new QVBoxLayout;
    LinkLayout->addWidget(AboutBTC);
    LinkLayout->addWidget(HowToBuyBTC);
    LinkLayout->addWidget(ContactUs);
    QVBoxLayout *LeftLayout = new QVBoxLayout;
    LeftLayout->addWidget(Image);
    LeftLayout->addWidget(Discount);
    LeftLayout->addWidget(MoneyLost);
    LeftLayout->addLayout(LinkLayout);
    QHBoxLayout *TopLayout = new QHBoxLayout;
    TopLayout->addWidget(Oops);
    TopLayout->addWidget(Language);
    QGridLayout *BottomLayout = new QGridLayout;
    BottomLayout->addWidget(BTCIcon, 0, 1);
    BottomLayout->addWidget(Send, 0, 2);
    BottomLayout->addWidget(BTCAddress, 1, 2);
    BottomLayout->addWidget(CheckPayment, 2, 1);
    BottomLayout->addWidget(Decrypt, 2, 2);
    QVBoxLayout *RightLayout = new QVBoxLayout;
    RightLayout->addLayout(TopLayout);
    RightLayout->addWidget(Text);
    RightLayout->addLayout(BottomLayout);
    QHBoxLayout *MainLayout = new QHBoxLayout;
    MainLayout->addLayout(LeftLayout);
    MainLayout->addLayout(RightLayout);
    QWidget *MainWidget = new QWidget;
    MainWidget->setLayout(MainLayout);
    // Window settings
    setWindowTitle("Wanna Decrypt0r 3.0");
    setStyleSheet("background: #A20000");
    setMinimumSize(640, 480);
    setCentralWidget(MainWidget);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint&  ~Qt::WindowMinimizeButtonHint);
    // Stat timer
    Timer = new QTimer;
    // Connect singals to slots
    connect(Timer, SIGNAL(timeout()), this, SLOT(ShowTime()));
    Timer->start(1000);
    ShowTime();
}

void MainWindow::Resize(QResizeEvent *event)
{

}

void MainWindow::ShowTime()
{
    QTime Time = QTime::fromString(QString::number(DiscountTime->value())).addSecs(1);  // +1s
    QString Now = Time.toString("hh:mm:ss");
    DiscountTime->display(Now);
    Time = QTime::fromString(QString::number(MoneyLostTime->value())).addMSecs(-1);
    Now = Time.toString("hh:mm:ss");
    MoneyLostTime->display(Now);
}
