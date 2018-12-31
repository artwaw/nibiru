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
    QSettings settings;
    addDialogGeoModel *geodbmodel;
    QSqlDatabase geodb;

private slots:
    void addNewEvent();
    void settingsClicked();
    void quitClicked();
};

#endif // MAINWINDOW_H
