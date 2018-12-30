#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "adddialog.h"
#include "setdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void addNewEvent();
    void settingsClicked();
    void quitClicked();
};

#endif // MAINWINDOW_H
