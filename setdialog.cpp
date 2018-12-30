#include "setdialog.h"
#include "ui_setdialog.h"

setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    ui->setupUi(this);
    ui->geoLocationEdit->setText(settings.value("geoFile",QApplication::arguments().at(0)).toString());
    connect(ui->geoBrowseBtn,&QPushButton::clicked,this,&setDialog::geoBrowseBtnClicked);
    connect(ui->okBtn,&QPushButton::clicked,this,&setDialog::okBtnClicked);
    connect(ui->cancelBtn,&QPushButton::clicked,this,&setDialog::cancelBtnClicked);
}

setDialog::~setDialog()
{
    delete ui;
}

void setDialog::okBtnClicked() {
    QFile test(ui->geoLocationEdit->text());
    if (test.exists()) {
        settings.setValue("geoFile",ui->geoLocationEdit->text());
        accept();
    } else {
        QMessageBox::warning(this,"File not found","Can't find selected file!");
    };
}

void setDialog::cancelBtnClicked() {
    reject();
}

void setDialog::geoBrowseBtnClicked() {
    ui->geoLocationEdit->setText(QFileDialog::getOpenFileName(this,"Select geo database file"));
}
