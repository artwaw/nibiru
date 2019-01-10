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
    QSortFilterProxyModel *pmodel;
    QSettings settings;

private slots:
    void setBoxHint(QString what);
<<<<<<< HEAD
    void okBtnClicked();
=======
    void acceptCLicked();
    void cancelClicked();
>>>>>>> 64076b79319f01033a67d6a880a128c32e505265
};

#endif // ADDDIALOG_H
