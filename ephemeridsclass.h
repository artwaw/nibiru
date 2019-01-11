#ifndef EPHEMERIDSCLASS_H
#define EPHEMERIDSCLASS_H

#include <QObject>
#include <QMap>

class ephemeridsClass : public QObject
{
    Q_OBJECT
public:
    explicit ephemeridsClass(QObject *parent = nullptr);
    QString mercury();
    QString venus();
    QString mars();
    QString jupiter();
    QString saturn();
    QString uranus();
    QString neptune();
    QString pluto();
    QString sun();

    void setGeo(QString along, QString alat);

signals:

public slots:

private:
    QMap<int, QString> zodiac;
};

#endif // EPHEMERIDSCLASS_H
