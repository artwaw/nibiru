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
    QString moon();

    void setGeo(QString along, QString alat);
    void setDT(QString when);

signals:

public slots:

private:
    QMap<qint32, QString> zodiac;
    QMap<qint32,qreal> zdata;
    qreal blong, blat;
    QDateTime stamp;
    qreal dT;
    /* The primary orbital elements are here denoted as:
    N = longitude of the ascending node
    i = inclination to the ecliptic (plane of the Earth's orbit)
    w = argument of perihelion
    a = semi-major axis, or mean distance from Sun
    e = eccentricity (0=circle, 0-1=ellipse, 1=parabola)
    M = mean anomaly (0 at perihelion; increases uniformly with time)
Related orbital elements are:
    w1 = N + w   = longitude of perihelion
    L  = M + w1  = mean longitude
    q  = a*(1-e) = perihelion distance
    Q  = a*(1+e) = aphelion distance
    P  = a ^ 1.5 = orbital period (years if a is in AU, astronomical units)
    T  = Epoch_of_M - (M(deg)/360_deg) / P  = time of perihelion
    v  = true anomaly (angle between position and perihelion)
    E  = eccentric anomaly */
    qreal bodyAData[10][2]; //first: mercury, venus, mars, jupiter, saturn, uranus, neptune, pluto, sun, moon; second: a component data
    qreal bodyMData[10][2]; //Anomaly componenet data per body (const part, power base)
    qreal bodyWData[10][2]; //argument of peryhelion componenet data per body
    qreal bodyNData[10][2]; //N component data
    qreal bodyIData[10][2]; //inclination component data
    qreal bodyEData[10][2]; //eccentricity component data
    qreal ecl[2]; //obliquity of the ecliptic, tilt of the Earth's axis rotation

    QString computeForBody(const int body);
    qreal meanAnomaly(const int body);
    qreal trueAnomaly(const int Body, qreal meanA);

    //methods return computed components using the tables above
    qreal GetAComp(qint32 body);
    qreal GetMComp(qint32 body);
    qreal GetWComp(qint32 body);
    qreal GetNComp(qint32 body);
    qreal GetIComp(qint32 body);
    qreal GetEComp(qint32 body);

    //return value sanitisation
    qreal satRA(qreal value);
    qreal satAN(qreal value);
};

#endif // EPHEMERIDSCLASS_H
