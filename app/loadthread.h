#ifndef LOADTHREAD_H
#define LOADTHREAD_H

#include "dataloadthread.h"
#include "post.h"
#include <QJsonValue>
#include <QThread>
#include <QVariant>

class LoadThread : public QThread
{
    Q_OBJECT
    Q_PROPERTY(QByteArray data WRITE setData NOTIFY dataChanged)

public:
    void run();
    bool isEndOfFeed();
    LoadThread();
    void setData(QByteArray data);
    QByteArray getData();
    QList<QList<QVariant>> list;

signals:
    void endLoad(QString title, QString avaUrl, QString text, QList<QVariant> images, bool showThisPost);
    void startLoad(QJsonValue object);
    void dataChanged();
    void done();

private slots:
    void load(QJsonValue object);
    void loadData(QString title, QString avaUrl, QString text, QList<QVariant> images, bool showThisPost);

public slots:
    void stop();

private:
    QByteArray data;
    DataLoadThread *thread;
    void timeout(int ms);
    bool endOfFeed = false;
};

#endif // LOADTHREAD_H
