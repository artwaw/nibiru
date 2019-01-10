#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(settings.value("geoFile",QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)+"/geo.db").toString());
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
    ui->citySearch->setText(settings.value("lastCity","").toString());
    connect(ui->citySearch,&QLineEdit::textChanged,this,&addDialog::setBoxHint);
    connect(ui->okBtn,&QPushButton::clicked,this,&addDialog::acceptCLicked);
    connect(ui->cancelBtn,&QPushButton::clicked,this,&addDialog::cancelClicked);
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
    ui->cityList->selectRow(0);
}

void addDialog::acceptCLicked() {
    if (ui->cityList->selectionModel()->hasSelection()) {
        //check for data
        if (ui->nameEdit->text().isEmpty()||ui->surnameEdit->text().isEmpty()||!ui->cityList->selectionModel()->hasSelection()||ui->eventBox->currentIndex()<0) {
            QMessageBox::warning(this,"Not enough data","Name, surname, city and event type are mandatory!");
            return;
        };
        //remember last city
        settings.setValue("lastCity",ui->cityList->selectionModel()->currentIndex().siblingAtColumn(3).data());
        accept();
    } else {
        QMessageBox::warning(this,"Required data missing","Location needs to be selected in order to proceed");
    };
}

void addDialog::cancelClicked() {
    reject();
}

void addDialog::setModel(QSqlTableModel *mdl) {
    pmodel = new QSortFilterProxyModel(this);
    pmodel->setSourceModel(mdl);
    pmodel->setHeaderData(1,Qt::Horizontal,"Continent",Qt::DisplayRole);
    pmodel->setHeaderData(2,Qt::Horizontal,"Country",Qt::DisplayRole);
    pmodel->setHeaderData(3,Qt::Horizontal,"City",Qt::DisplayRole);
    pmodel->setHeaderData(4,Qt::Horizontal,"Postcode",Qt::DisplayRole);
    pmodel->setFilterKeyColumn(3);
    ui->cityList->setModel(pmodel);
    ui->cityList->hideColumn(0);
    ui->cityList->hideColumn(5);
    ui->cityList->hideColumn(6);
    ui->cityList->horizontalHeader()->stretchLastSection();
    ui->cityList->resizeRowsToContents();
    ui->cityList->resizeColumnsToContents();
    ui->cityList->setSortingEnabled(true);
    connect(ui->citySearch,&QLineEdit::textChanged,this,&addDialog::setBoxHint);
}
