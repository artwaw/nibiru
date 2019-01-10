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
        QMessageBox::critical(splash,"Can't open geo database","The geo.db file set in settings cannot be opened. Please reinstall the software.");
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
    splash->hide();
    delete splash;
    show();
}

MainWindow::~MainWindow()
{
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
