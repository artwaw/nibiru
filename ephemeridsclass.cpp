#include "ephemeridsclass.h"

ephemeridsClass::ephemeridsClass(QObject *parent) : QObject(parent)
{
    zodiac[0]=tr("Mercury"); zodiac[1]=tr("Venus"); zodiac[2]=tr("Mars"); zodiac[3]=tr("Jupiter"); zodiac[4]=tr("Saturn"); zodiac[5]=tr("Uranus"); zodiac[6]=tr("Neptune");
    zodiac[7]=tr("Pluto"); zodiac[8]=tr("Sun");
}
