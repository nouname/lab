#ifndef DataLoadThread_H
#define DataLoadThread_H

#include <QJsonValue>
#include <QThread>
#include <QVariant>

class DataLoadThread : public QThread
{
    Q_OBJECT

public:
    explicit DataLoadThread(QString s, QJsonValue object);
    void run();

public slots:
    void stop();

signals:
    void loaded(QString title, QString avaUrl, QString text, QList<QVariant> images, bool showThisPost);
    void done();

private:
    QString name;
    QJsonValue object;
    QList<QVariant> images;
    QString title, avaUrl, text;
    bool showThisPost = true;
    void timeout(int ms);
};

#endif // DataLoadThread_H
