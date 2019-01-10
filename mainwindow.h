#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QSqlQuery>

#include "adddialog.h"
#include "setdialog.h"
#include "splashdlg.h"
#include "adddialoggeomodel.h"
#include "eventviewmodelclass.h"

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
    void zeroConfigDB();
    QSettings settings;
    addDialogGeoModel *geodbmodel;
    QSqlDatabase geodb, eventdb;
    eventViewModelClass *emodel;
    QSortFilterProxyModel *eproxy;
    addDialog *addDialogEvent;

private slots:
    void addNewEvent();
    void settingsClicked();
    void quitClicked();
};

#endif // MAINWINDOW_H
