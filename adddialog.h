#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QObject>
#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSettings>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QRegExp>
#include <QStandardPaths>
#include <QSqlError>

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
    void setModel(QSqlTableModel *mdl);

private:
    Ui::addDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSortFilterProxyModel *pmodel;
    QSettings settings;

private slots:
    void setBoxHint(QString what);
    void acceptCLicked();
    void cancelClicked();
};

#endif // ADDDIALOG_H
