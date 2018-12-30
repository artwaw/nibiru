#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setApplicationVersion("0.1");
    QCoreApplication::setOrganizationName("TrollNet");
    QCoreApplication::setOrganizationDomain("trollnet.com.pl");
    QCoreApplication::setApplicationName("Nibiru");
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    MainWindow w;
    w.setAttribute(Qt::WA_AlwaysShowToolTips);
    w.show();

    return a.exec();
}
