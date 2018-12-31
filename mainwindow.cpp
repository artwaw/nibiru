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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewEvent() {
    QFile test(settings.value("geoFile").toString());
    if (!test.exists()) {
        QMessageBox::warning(this,"File not found","The geo.db file has not been found! Please provide correct settings in the settings panel.");
        return;
    };
    addDialog *addDialogEvent = new addDialog(this);
    addDialogEvent->exec();
    delete addDialogEvent;
}

void MainWindow::settingsClicked() {
    setDialog *sets = new setDialog(this);
    sets->exec();
    delete sets;
}
void MainWindow::quitClicked() {
    this->close();
}
