#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>

namespace Ui {
class setDialog;
}

class setDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setDialog(QWidget *parent = nullptr);
    ~setDialog();

private:
    Ui::setDialog *ui;
    QSettings settings;

private slots:
    void okBtnClicked();
    void cancelBtnClicked();
    void geoBrowseBtnClicked();
    void dbBrowseBtnClicked();
};

#endif // SETDIALOG_H
