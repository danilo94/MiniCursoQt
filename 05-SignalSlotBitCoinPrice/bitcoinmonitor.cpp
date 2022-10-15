#include "bitcoinmonitor.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>

BitCoinMonitor::BitCoinMonitor(QObject *parent)
    : QObject{parent}
{
    initNetWorkManager();
    initTimer();
}

void BitCoinMonitor::requestBitCoinUpdate()
{
    getBitCoinPrice();
}

void BitCoinMonitor::requestFinished(QNetworkReply *reply)
{
    QString answer = reply->readAll();
    double bitcoinValue =  getBitCoinPriceFromJson(answer);
    emit updateBitcoinPrice(bitcoinValue);

}

void BitCoinMonitor::initNetWorkManager()
{
    m_manager = new QNetworkAccessManager(this);
    this->connect(m_manager,&QNetworkAccessManager::finished,this,&BitCoinMonitor::requestFinished);
}

void BitCoinMonitor::initTimer()
{
    m_timer = new QTimer(this);
    m_timer->setInterval(3000);
    this->connect(m_timer,&QTimer::timeout,this,&BitCoinMonitor::requestBitCoinUpdate);
    m_timer->start();
}

void BitCoinMonitor::getBitCoinPrice()
{
    m_manager->get(QNetworkRequest(QUrl(m_api)));
}

double BitCoinMonitor::getBitCoinPriceFromJson(QString jsonSerialized)
{
    double bitcoinPrice = 0;
    QJsonDocument doc = QJsonDocument::fromJson(jsonSerialized.toUtf8());
    QJsonObject obj = doc.object();
    QJsonObject bpi = obj["bpi"].toObject();
    QJsonObject usd = bpi["USD"].toObject();
    bitcoinPrice = usd["rate_float"].toDouble();
    return bitcoinPrice;
}
