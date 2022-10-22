#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lowerValue->setStyleSheet("color : white;");
    ui->higherValue->setStyleSheet("color: white;");
    this->setStyleSheet("background: #1e243a;");
    initBitcoinMonitor();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReceiveUpdateBitCoinUpdate(double value)
{
    updateHigherBitcoinPrice(value);
    updateLowerBitcoinPrice(value);
}

void MainWindow::initBitcoinMonitor()
{
    m_monitor = new BitCoinMonitor();
    connect(m_monitor,&BitCoinMonitor::updateBitcoinPrice,this,&MainWindow::onReceiveUpdateBitCoinUpdate);
}

void MainWindow::updateHigherBitcoinPrice(double value)
{
    if (m_higherValue < value ){
        m_higherValue = value;
        QString price = QString("<h1>$%1</h1>").arg(value);
        ui->higherValue->setText(price);
    }


}

void MainWindow::updateLowerBitcoinPrice(double value)
{
    if (m_lowerValue > value){
        m_lowerValue = value;
        QString price = QString("<h1>$%1</h1>").arg(m_lowerValue);
        ui->lowerValue->setText(price);
    }

}

