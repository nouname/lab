#include "postloader.h"
#include "globals.h"
#include "vk.h"
#include "datareceiver.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>

static int offset = 0;

PostLoader::PostLoader(QObject *parent) : QObject (parent)
{
    getPosts(offset);
}

Post *PostLoader::getData()
{
    return data;
}

void PostLoader::setData(Post* data)
{
    this->data = data;
}

void PostLoader::getPosts(int offset)
{    
    VK vk;
    DataReceiver receiver;
    receiver.setUrl("https://api.vk.com/method/newsfeed.get?filters=post&count=100&start_from=" + QString::number(offset) + "&access_token=" + vk.getTokenFromFile()->getValue() + "&v=5.52");
    QByteArray data = receiver.getData();
    thread = new LoadThread();
    thread->setData(data);
    connect(thread, SIGNAL(endLoad(QString, QString, QString, QList<QVariant>, bool)), this, SLOT(loaded(QString, QString, QString, QList<QVariant>, bool)));
    connect(thread, SIGNAL(finished()), this, SLOT(loadMore()));
    connect(this, SIGNAL(done()), thread, SLOT(stop()));
    connect(&vk, SIGNAL(done()), thread, SLOT(stop()));
    thread->start();
}

void PostLoader::timeout(int ms)
{
    QTimer *timer = new QTimer();
    QEventLoop loop;
    connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer->start(ms);
    loop.exec();
    loop.deleteLater();
}

void PostLoader::loadMore()
{
    emit done();
    offset += 100;
    getPosts(offset);
    timeout(3000);
}

void PostLoader::loaded(QString title, QString avaUrl, QString text, QList<QVariant> images, bool showThisPost)
{
    Post* post = new Post(nullptr);
    post->setTitle(title);
    post->setAva(avaUrl);
    post->setText(text);
    post->setImages(images);
    post->showThisPost = showThisPost;
    setData(post);
    emit dataChanged();
}
