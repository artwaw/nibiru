#include "splashdlg.h"
#include "ui_splashdlg.h"

splashDlg::splashDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::splashDlg)
{
    ui->setupUi(this);
}

splashDlg::~splashDlg()
{
    delete ui;
}

void splashDlg::setLabel(QString text) {
    ui->label->setText(text);
}

void splashDlg::setProgressBar(int value) {
    ui->progressBar->setValue(value);
}
