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
    pmodel = new QSortFilterProxyModel(this);
    pmodel->setSourceModel(model);
    pmodel->setHeaderData(1,Qt::Horizontal,"Continent",Qt::DisplayRole);
    pmodel->setHeaderData(2,Qt::Horizontal,"Country",Qt::DisplayRole);
    pmodel->setHeaderData(3,Qt::Horizontal,"City",Qt::DisplayRole);
    pmodel->setHeaderData(4,Qt::Horizontal,"Postcode",Qt::DisplayRole);
    ui->cityList->setModel(pmodel);
    ui->cityList->hideColumn(0);
    ui->cityList->hideColumn(5);
    ui->cityList->hideColumn(6);
    connect(ui->citySearch,&QLineEdit::textChanged,this,&addDialog::setBoxHint);

}

addDialog::~addDialog()
{
    if (db.isOpen()) {
        db.close();
    };
    delete ui;
}

void addDialog::setBoxHint(QString what){
    QRegExp regExp(what,Qt::CaseInsensitive,QRegExp::FixedString);
    pmodel->setFilterRegExp(regExp);
}
