#include "setdialog.h"
#include "ui_setdialog.h"

setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    ui->setupUi(this);
    ui->geoLocationEdit->setText(settings.value("geoFile",QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/geo.db").toString());
    ui->dbLocationEdit->setText(settings.value("dbFile",QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/nibiru.db").toString());
    connect(ui->geoBrowseBtn,&QPushButton::clicked,this,&setDialog::geoBrowseBtnClicked);
    connect(ui->okBtn,&QPushButton::clicked,this,&setDialog::okBtnClicked);
    connect(ui->cancelBtn,&QPushButton::clicked,this,&setDialog::cancelBtnClicked);
    connect(ui->dbBrowseBtn,&QPushButton::clicked,this,&setDialog::dbBrowseBtnClicked);
}

setDialog::~setDialog()
{
    delete ui;
}

void setDialog::okBtnClicked() {
    QFile test(ui->geoLocationEdit->text());
    QFile test2(ui->dbLocationEdit->text());
    if (test.exists()&test2.exists()) {
        settings.setValue("geoFile",ui->geoLocationEdit->text());
        settings.setValue("dbFile",ui->dbLocationEdit->text());
        accept();
    } else {
        QMessageBox::warning(this,"File not found","Can't find or access selected file(s)!");
    };
}

void setDialog::cancelBtnClicked() {
    reject();
}

void setDialog::geoBrowseBtnClicked() {
    ui->geoLocationEdit->setText(QFileDialog::getOpenFileName(this,"Select geo database file"));
}

void setDialog::dbBrowseBtnClicked() {
    ui->dbLocationEdit->setText(QFileDialog::getOpenFileName(this,"Select database file"));
}
