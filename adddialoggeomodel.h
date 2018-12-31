#ifndef ADDDIALOGGEOMODEL_H
#define ADDDIALOGGEOMODEL_H

#include <QObject>
#include <QSqlTableModel>

class addDialogGeoModel : public QSqlTableModel
{
public:
    addDialogGeoModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase()) : QSqlTableModel(parent,db) {}
    bool select();
};

#endif // ADDDIALOGGEOMODEL_H
