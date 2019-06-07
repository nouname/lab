#include "dataloadthread.h"
#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include <QEventLoop>
#include "datareceiver.h"
#include "globals.h"
#include "vk.h"

DataLoadThread::DataLoadThread(QString s, QJsonValue object) : name(s)
{
    this->object = object;
}

void DataLoadThread::run()
{
    VK vk;
    int sourceId = object.toObject().value("source_id").toInt();
    sourceId = -sourceId;
    showThisPost = true;

    DataReceiver receiver;
    receiver.setUrl("https://api.vk.com/method/groups.getById?group_id=" + QVariant(sourceId).toString() + "&access_token=" + vk.getTokenFromFile()->getValue() + "&v=5.92");

    QByteArray groupData = receiver.getData();
    QJsonObject source = QJsonDocument::fromJson(groupData).object();

    title = source.value("response").toArray().at(0).toObject().value("name").toString();
    avaUrl = source.value("response").toArray().at(0).toObject().value("photo_50").toString();

    text = object.toObject().value("text").toString();
    images.clear();

    for(QJsonValue contents : object.toObject().value("attachments").toArray())
    {
        if (contents.toObject().value("type").toString() != "photo") {
            showThisPost = false;
            break;
        }
        if (!contents.toObject().value("photo").isUndefined()) {
            QJsonValue url, value;
            QString result;
            for (int i = 0; !(value = contents.toObject().value("photo").toObject().value("photo_" + PHOTO_SIZES[i])).isUndefined() && i < PHOTO_SIZES.length(); i++)
                url = value;

            result = url.toString();
            int w = 700;
            double h = contents.toObject().value("photo").toObject().value("height").toInt() * w /
                    contents.toObject().value("photo").toObject().value("width").toInt();

            result += "*" + QString::number(h);
            images.append(result);
        }
    }
    emit loaded(title, avaUrl, text, images, showThisPost);
}

void DataLoadThread::stop()
{
    emit done();
    quit();
    requestInterruption();
    if (isInterruptionRequested()) {
        return;
    }
}


