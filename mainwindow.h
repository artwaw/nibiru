#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

#include "adddialog.h"
#include "setdialog.h"
#include "splashdlg.h"
#include "adddialoggeomodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
<<<<<<< HEAD
    void zeroConfigDB();
=======
    QSettings settings;
    addDialogGeoModel *geodbmodel;
    QSqlDatabase geodb;
    addDialog *addDialogEvent;
>>>>>>> 64076b79319f01033a67d6a880a128c32e505265

private slots:
    void addNewEvent();
    void settingsClicked();
    void quitClicked();
};

#endif // MAINWINDOW_H
