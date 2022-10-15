#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bitcoinmonitor.h"

#include <QMainWindow>
#include <QChartView>
#include <QChart>
#include <QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onReceiveUpdateBitCoinUpdate(double value);

private:
    void initBitcoinMonitor();

    void updateHigherBitcoinPrice(double value);
    void updateLowerBitcoinPrice(double value);
private:
    Ui::MainWindow *ui;

    BitCoinMonitor *m_monitor;


    double m_higherValue=0;
    double m_lowerValue=999999;
};
#endif // MAINWINDOW_H
