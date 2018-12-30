#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(settings.value("geoFile",QApplication::arguments().at(0)).toString());
    if (!db.open()) {
        QMessageBox::critical(this,"Geo db open error",db.lastError().text()+settings.value("geoFile").toString());
        return;
    };
    model = new QSqlTableModel(this,db);
    model->setTable("geodata");
    model->select();
    ui->locationBox->setModel(model);
    ui->locationBox->setModelColumn(3);
}

addDialog::~addDialog()
{
    if (db.isOpen()) {
        db.close();
    };
    delete ui;
}
