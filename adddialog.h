#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QObject>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSettings>

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
    QSqlTableModel *model;
    QSettings settings;
};

#endif // ADDDIALOG_H
