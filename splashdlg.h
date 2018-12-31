#ifndef SPLASHDLG_H
#define SPLASHDLG_H

#include <QDialog>

namespace Ui {
class splashDlg;
}

class splashDlg : public QDialog
{
    Q_OBJECT

public:
    explicit splashDlg(QWidget *parent = nullptr);
    ~splashDlg();

    void setLabel(QString text);
    void setProgressBar(int value);

private:
    Ui::splashDlg *ui;
};

#endif // SPLASHDLG_H
