#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QObject>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSettings>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QRegExp>

#include "adddialoggeomodel.h"

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr);
    ~addDialog();

private:
    Ui::addDialog *ui;
    QSqlDatabase db;
    addDialogGeoModel *model;
    QSortFilterProxyModel *pmodel;
    QSettings settings;

private slots:
    void setBoxHint(QString what);
    void acceptCLicked();
    void cancelClicked();
};

#endif // ADDDIALOG_H
