#include "ephemeridsclass.h"

ephemeridsClass::ephemeridsClass(QObject *parent) : QObject(parent)
{
    zodiac[0]=tr("Mercury"); zodiac[1]=tr("Venus"); zodiac[2]=tr("Mars"); zodiac[3]=tr("Jupiter"); zodiac[4]=tr("Saturn"); zodiac[5]=tr("Uranus"); zodiac[6]=tr("Neptune");
    zodiac[7]=tr("Pluto"); zodiac[8]=tr("Sun"); zodiac[9]=tr("Moon");

    bodyMData[0][0]=168.6562; bodyMData[0][1]=4.0923344368;
    bodyMData[1][0]=48.0052;  bodyMData[1][1]=1.6021302244;
    bodyMData[2][0]=18.6021;  bodyMData[2][1]=0.5240207766;
    bodyMData[3][0]=19.8950;  bodyMData[3][1]=0.0830853001;
    bodyMData[4][0]=316.9670; bodyMData[4][1]=0.0334442282;
    bodyMData[5][0]=142.5905; bodyMData[5][1]=0.011725806;
    bodyMData[6][0]=260.2471; bodyMData[6][1]=0.005995147;
    bodyMData[7][0]=14.882;
    bodyMData[8][0]=356.0470; bodyMData[8][1]=0.9856002585;
    bodyMData[9][0]=115.3654; bodyMData[9][1]=13.0649929509;

    bodyAData[0][0]=0.387098; bodyAData[0][1]=0;
    bodyAData[1][0]=0.723330; bodyAData[1][1]=0;
    bodyAData[2][0]=1.523688; bodyAData[2][1]=0;
    bodyAData[3][0]=5.20256;  bodyAData[3][1]=0;
    bodyAData[4][0]=9.55475;  bodyAData[4][1]=0;
    bodyAData[5][0]=19.18171; bodyAData[5][1]=-qPow(1.55,-8);
    bodyAData[6][0]=30.05826; bodyAData[6][1]=qPow(3.313,-8);
    bodyAData[7][0]=39.543;
    bodyAData[8][0]=1;        bodyMData[8][1]=0;
    bodyAData[9][0]=60.2666;  bodyMData[9][1]=0;

    bodyNData[0][0]=48.3313;  bodyNData[0][1]=qPow(3.24587,-5);
    bodyNData[1][0]=76.6799;  bodyNData[1][1]=qPow(2.46590,-5);
    bodyNData[2][0]=49.5574;  bodyNData[2][1]=qPow(2.11081,-5);
    bodyNData[3][0]=100.4542; bodyNData[3][1]=qPow(2.76854,-5);
    bodyNData[4][0]=113.6634; bodyNData[4][1]=qPow(2.38980,-5);
    bodyNData[5][0]=74.0005;  bodyNData[5][1]=qPow(1.3978,-5);
    bodyNData[6][0]=131.7806; bodyNData[6][1]=qPow(3.0173,-5);
    bodyNData[7][0]=110.307;  bodyNData[7][1]=0;
    bodyNData[8][0]=0;        bodyNData[8][1]=0;
    bodyNData[9][0]=125.1228; bodyNData[9][1]=-0.0529538083;

    bodyIData[0][0]=7.0047;   bodyIData[0][1]=qPow(5,-8);
    bodyIData[1][0]=3.3946;   bodyIData[1][1]=qPow(2.7,-8);
    bodyIData[2][0]=1.8497;   bodyIData[2][1]=-qPow(1.78,-8);
    bodyIData[3][0]=1.3030;   bodyIData[3][1]=-qPow(1.557,-7);
    bodyIData[4][0]=2.4886;   bodyIData[4][1]=-qPow(1.081,-7);
    bodyIData[5][0]=0.7733;   bodyIData[5][1]=-qPow(1.9,-8);
    bodyIData[6][0]=1.7700;   bodyIData[6][1]=-qPow(2.55,-7);
    bodyIData[7][0]=0;        bodyIData[7][1]=0;
    bodyIData[8][0]=0;        bodyIData[8][1]=0;
    bodyIData[9][0]=5.1454;   bodyIData[9][1]=0;

    bodyWData[0][0]=29.1241;  bodyWData[0][1]=qPow(1.01444,-5);
    bodyWData[1][0]=54.8910;  bodyWData[1][1]=qPow(1.38374,-5);
    bodyWData[2][0]=286.5016; bodyWData[2][1]=qPow(2.92961,-5);
    bodyWData[3][0]=273.8777; bodyWData[3][1]=qPow(1.64505,-5);
    bodyWData[4][0]=339.3939; bodyWData[4][1]=qPow(2.97661,-5);
    bodyWData[5][0]=96.6612;  bodyWData[5][1]=qPow(3.0565,-5);
    bodyWData[6][0]=272.8461; bodyWData[6][1]=-qPow(6.027,-6);
    bodyWData[7][0]=0;        bodyWData[7][1]=0;
    bodyWData[8][0]=282.9404; bodyWData[8][1]=qPow(4.70935,-5);
    bodyWData[9][0]=318.0634; bodyWData[9][1]=0.1643573223;

    bodyEData[0][0]=0.205635; bodyEData[0][1]=qPow(5.59,-10);
    bodyEData[1][0]=0.006773; bodyEData[1][1]=-qPow(1.302,-9);
    bodyEData[2][0]=0.093405; bodyEData[2][1]=qPow(2.516,-9);
    bodyEData[3][0]=0.048498; bodyEData[3][1]=qPow(4.469,-9);
    bodyEData[4][0]=0.055546; bodyEData[4][1]=-qPow(9.499,-9);
    bodyEData[5][1]=0.047318; bodyEData[5][1]=qPow(7.45,-9);
    bodyEData[6][0]=0.008606; bodyEData[6][1]=qPow(2.15,-9);
    bodyEData[7][0]=0;        bodyEData[7][1]=0;
    bodyEData[8][0]=0.016709; bodyEData[8][1]=-qPow(1.151,-9);
    bodyEData[9][0]=0.054900; bodyEData[9][1]=0;

    ecl[0]=23.4393; ecl[1]=-qPow(3.563,-7);
}

void ephemeridsClass::setGeo(QString along, QString alat) {
    blong = along.toDouble(); blat = alat.toDouble();
}

void ephemeridsClass::setDT(QString when) {
    stamp = QDateTime::fromString(when);
    QDateTime year0(QDate::fromJulianDay(2451545),QTime::fromString("00:00:00"));
    stamp = stamp.toUTC();
    dT = stamp.daysTo(year0)+((stamp.toUTC().time().hour()*60+stamp.time().minute())/1440);
}

QString ephemeridsClass::computeForBody(int body) {
    int result=0;
    result = qRound(meanAnomaly(body));
    return zodiac[result];
}

qreal ephemeridsClass::meanAnomaly(const int body) {
    //return bodyAData[body][5] + (0.9856076686/(qPow(bodyAData[body][0],3/2))*deltaT);
    return body;
}

qreal ephemeridsClass::trueAnomaly(const int Body, qreal meanA) {
Q_UNUSED(Body)
Q_UNUSED(meanA)
    return 0;
}

qreal ephemeridsClass::GetAComp(qint32 body) {
    return bodyAData[body][0]+bodyAData[body][1]*dT;
}

qreal ephemeridsClass::GetMComp(qint32 body) {
    return bodyMData[body][0]+bodyMData[body][1]*dT;
}

qreal ephemeridsClass::GetNComp(qint32 body) {
    return bodyNData[body][0]+bodyNData[body][1]*dT;
}

qreal ephemeridsClass::GetIComp(qint32 body) {
    return bodyIData[body][0]+bodyIData[body][1]*dT;
}

qreal ephemeridsClass::GetWComp(qint32 body) {
    return bodyWData[body][0]+bodyWData[body][1]*dT;
}

qreal ephemeridsClass::GetEComp(qint32 body) {
    return bodyEData[body][0]+bodyEData[body][1]*dT;
}

qreal ephemeridsClass::satAN(qreal value) {
    if (value<0) {
        value +=360;
        if  (value<0) {
            satAN(value);
        }
    }
    return value;
}

qreal ephemeridsClass::satRA(qreal value) {

}
