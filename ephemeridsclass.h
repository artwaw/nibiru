#ifndef EPHEMERIDSCLASS_H
#define EPHEMERIDSCLASS_H

#include <QObject>
#include <QMap>
#include <QDateTime>
#include <QtMath>
#include <QDate>

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
    void setDT(QString when);

signals:

public slots:

private:
    QMap<qint32, QString> zodiac;
    QMap<qint32,qreal> zdata;
    qreal blong, blat;
    QDateTime stamp;
    qreal bodyData[8][6]; //first: mercury, venus, mars, jupiter, saturn, uranus, neptune, pluto; second: a, e, i, ω, Ω, M0

    QString computeForBody(const int body);
    qreal meanAnomaly(const int body);
};

#endif // EPHEMERIDSCLASS_H
