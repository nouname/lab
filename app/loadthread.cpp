#include "datareceiver.h"
#include "dataloadthread.h"
#include "loadthread.h"
#include "vk.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariant>
#include <QEventLoop>
#include <QTimer>

static QList<QVariant> images;
static int i = 0;

LoadThread::LoadThread()
{
    connect(this, SIGNAL(startLoad(QJsonValue)), this, SLOT(load(QJsonValue)), Qt::DirectConnection);
}

void LoadThread::setData(QByteArray data)
{
    this->data = data;
}

void LoadThread::run()
{
    QJsonObject root = QJsonDocument::fromJson(data).object();
    if (!root.value("error").isUndefined() || root.value("response").toObject().value("items").toArray().isEmpty()) {
        endOfFeed = true;
        emit done();
        qDebug() << endOfFeed;
        return;
    }

    for (QJsonValue object : root.value("response").toObject().value("items").toArray()) {
        i++;
        qDebug() << i;
        emit startLoad(object);
        timeout(300);
    }
}

bool LoadThread::isEndOfFeed()
{
    return endOfFeed;
}

void LoadThread::load(QJsonValue object)
{
    thread = new DataLoadThread("LoadData", object);
    connect(thread, SIGNAL(loaded(QString, QString, QString, QList<QVariant>, bool)), this, SLOT(loadData(QString, QString, QString, QList<QVariant>, bool)), Qt::DirectConnection);
    thread->start();
}

void LoadThread::loadData(QString title, QString avaUrl, QString text, QList<QVariant> images, bool showThisPost) {
    emit endLoad(title, avaUrl, text, images, showThisPost);
}

void LoadThread::stop()
{
    quit();
    requestInterruption();
    if (isInterruptionRequested()) {
        return;
    }
}

void LoadThread::timeout(int ms)
{
    QTimer *timer = new QTimer();
    QEventLoop loop;
    connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer->start(ms);
    loop.exec();
    loop.deleteLater();
}
