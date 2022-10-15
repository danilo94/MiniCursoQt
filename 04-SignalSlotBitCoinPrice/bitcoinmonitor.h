#ifndef BITCOINMONITOR_H
#define BITCOINMONITOR_H

#include <QObject>
#include <QTimer>
#include <QNetworkAccessManager>


class BitCoinMonitor : public QObject
{
    Q_OBJECT
public:
    explicit BitCoinMonitor(QObject *parent = nullptr);

signals:
    void updateBitcoinPrice(double bitcoinPrice);

private slots:
    void requestBitCoinUpdate();
    void requestFinished(QNetworkReply *reply);

private:
    void initNetWorkManager();
    void initTimer();
    void getBitCoinPrice();

    double getBitCoinPriceFromJson(QString jsonSerialized);

private:
   QNetworkAccessManager *m_manager;
   QTimer *m_timer;
   const QString m_api = "http://api.coindesk.com/v1/bpi/currentprice/BTC.json";

};

#endif // BITCOINMONITOR_H
