#include "ephemeridsclass.h"

ephemeridsClass::ephemeridsClass(QObject *parent) : QObject(parent)
{
    zodiac[0]=tr("Mercury"); zodiac[1]=tr("Venus"); zodiac[2]=tr("Mars"); zodiac[3]=tr("Jupiter"); zodiac[4]=tr("Saturn"); zodiac[5]=tr("Uranus"); zodiac[6]=tr("Neptune");
    zodiac[7]=tr("Pluto"); zodiac[8]=tr("Sun");
    bodyData[0][0]=0.38710;  bodyData[0][1]=0.20563; bodyData[0][2]=7.005;  bodyData[0][3]=29.125;  bodyData[0][4]=48.331;  bodyData[0][5]=174.795;
    bodyData[1][0]=0.72333;  bodyData[1][1]=0.00677; bodyData[1][2]=3.395;  bodyData[1][3]=54.884;  bodyData[1][4]=76.680;  bodyData[1][5]=50.416;
    bodyData[2][0]=1.52368;  bodyData[2][1]=0.09340; bodyData[2][2]=1.850;  bodyData[2][3]=286.502; bodyData[2][4]=49.558;  bodyData[2][5]=19.373;
    bodyData[3][0]=5.20260;  bodyData[3][1]=0.04849; bodyData[3][2]=1.303;  bodyData[3][3]=273.867; bodyData[3][4]=100.464; bodyData[3][5]=20.020;
    bodyData[4][0]=9.55491;  bodyData[4][1]=0.05551; bodyData[4][2]=2.489;  bodyData[4][3]=339.391; bodyData[4][4]=113.666; bodyData[4][5]=317.021;
    bodyData[5][0]=19.21845; bodyData[5][1]=0.04630; bodyData[5][2]=0.773;  bodyData[5][3]=98.999;  bodyData[5][4]=74.006;  bodyData[5][5]=141.050;
    bodyData[6][0]=30.11039; bodyData[6][1]=0.00899; bodyData[6][2]=1.770;  bodyData[6][3]=276.340; bodyData[6][4]=131.784; bodyData[6][5]=256.225;
    bodyData[7][0]=39.543;   bodyData[7][1]=0.2490;  bodyData[7][2]=17.140; bodyData[7][3]=113.768; bodyData[7][4]=110.307; bodyData[7][5]=14.882;
}

void ephemeridsClass::setGeo(QString along, QString alat) {
    blong = along.toDouble(); blat = alat.toDouble();
}

void ephemeridsClass::setDT(QString when) {
    stamp = QDateTime::fromString(when);
}

QString ephemeridsClass::computeForBody(int body) {
    int result=0;
    result = qRound(meanAnomaly(body));
    return zodiac[result];
}

qreal ephemeridsClass::meanAnomaly(const int body) {
    qint64 deltaT;
    QDateTime year0(QDate::fromJulianDay(2451545),QTime::fromString("00:00:00"));
    deltaT = stamp.daysTo(year0);
    return bodyData[body][5] + (0.9856076686/(qPow(bodyData[body][0],3/2))*deltaT);
}
