#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAdd,&QAction::triggered,this,&MainWindow::addNewEvent);
    connect(ui->actionSettings,&QAction::triggered,this,&MainWindow::settingsClicked);
    connect(ui->actionQuit,&QAction::triggered,this,&MainWindow::quitClicked);
    splashDlg *splash = new splashDlg(Q_NULLPTR);
    splash->show();
    while (!splash->isVisible()) {};
    splash->setLabel("Loading settings...");
    //global setting loaded here
    splash->setLabel("Loading geo database. This might take a while...");
    //loading geodb data here
    splash->setProgressBar(33);
    geodb = QSqlDatabase::addDatabase("QSQLITE","geodb");
    geodb.setDatabaseName(settings.value("geoFile").toString());
    if (!geodb.open()) {
        QMessageBox::critical(splash,"Can't open geo database","The geo.db file set in settings cannot be opened. Please reinstall the software or select different file.");
        splash->hide();
        delete splash;
        close();
        return;
    };
    geodbmodel = new addDialogGeoModel(Q_NULLPTR,geodb);
    geodbmodel->setTable("geodata");
    geodbmodel->select();
    addDialogEvent = new addDialog(this);
    addDialogEvent->setModel(geodbmodel);
    splash->setLabel("Loading other data...");
    splash->setProgressBar(66);
    splash->setLabel("Loading archive data...");
    eventdb = QSqlDatabase::addDatabase("QSQLITE","edb");
    eventdb.setDatabaseName(settings.value("dbFile").toString());
    if (!eventdb.open()) {
        QMessageBox::critical(splash,"Can't open event database","The database file set in settings cannot be opened. Please choose different database.");
        splash->hide();
        delete splash;
        close();
        return;
    };
    QSqlQuery query(eventdb);
    query.exec("SELECT count(*) FROM sqlite_master WHERE type = 'table' AND name = 'edata';");
    query.next();
    if (query.value(0).toInt()<=0) {
        zeroConfigDB();
    };
    emodel = new eventViewModelClass(Q_NULLPTR,eventdb);
    emodel->setTable("edata");
    emodel->select();
    eproxy = new QSortFilterProxyModel(this);
    eproxy->setSourceModel(emodel);
    eproxy->setHeaderData(1,Qt::Horizontal,"Name");
    eproxy->setHeaderData(2,Qt::Horizontal,"Surname");
    eproxy->setHeaderData(3,Qt::Horizontal,"Sex");
    eproxy->setHeaderData(4,Qt::Horizontal,"Location");
    eproxy->setHeaderData(7,Qt::Horizontal,"Event type");
    eproxy->setHeaderData(8,Qt::Horizontal,"Natal");
    eproxy->setHeaderData(9,Qt::Horizontal,"Event");
    eproxy->setHeaderData(10,Qt::Horizontal,"Comparative");
    eproxy->setHeaderData(11,Qt::Horizontal,"Modified on");
    eproxy->setHeaderData(12,Qt::Horizontal,"Added on");
    ui->eventListView->setModel(eproxy);
    ui->eventListView->hideColumn(0);
    ui->eventListView->hideColumn(5);
    ui->eventListView->hideColumn(6);
    ui->eventListView->resizeColumnsToContents();
    ui->eventListView->horizontalHeader()->restoreState(settings.value("headerState").toByteArray());
    ui->eventListView->setSortingEnabled(true);
    //ui->eventListView->horizontalHeader()->setSectionResizeMode();
    resize(settings.value("width").toInt(),settings.value("height").toInt());
    move(settings.value("pos").toPoint());
    splash->hide();
    delete splash;
    show();
} //imie, nazwisko, płeć, miasto, rodzaj zdarzenia, natalny, zdarzeniowy, porównawczy

MainWindow::~MainWindow()
{
    settings.setValue("pos",pos());
    settings.setValue("height",height());
    settings.setValue("width",width());
    settings.beginGroup("eventView");
    settings.setValue("headerState",ui->eventListView->horizontalHeader()->saveState());
    delete ui;
}

void MainWindow::addNewEvent() {
    addDialogEvent->exec();
}

void MainWindow::settingsClicked() {
    setDialog *sets = new setDialog(this);
    sets->exec();
    delete sets;
}
void MainWindow::quitClicked() {
    this->close();
}

void MainWindow::zeroConfigDB() {
    QSqlQuery query(eventdb);
    query.exec("create table edata(index integer primary key, imie text, nazwisko text, sex integer, city text, longitute text, latitude text, event type integer not null, natal integer, event integer, compare integer, modified text, added text);");
    if (query.lastError().type()!=QSqlError::NoError) {
        QMessageBox::critical(this,"Error creating data","Program encoutered error while creating default data structres. Sql db evendb error: "+query.lastError().text());
        geodb.close();
        this->close();
        return;
    };
    query.exec("create table events(index integer primary key, type text");
}
