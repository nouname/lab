#ifndef WEB_H
#define WEB_H

#include <QObject>

class Web : public QObject
{
    Q_OBJECT
public:
    explicit Web(QObject *parent = nullptr);

signals:

public slots:
};

#endif // WEB_H
