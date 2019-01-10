#ifndef EVENTVIEWMODELCLASS_H
#define EVENTVIEWMODELCLASS_H

#include <QObject>
#include <QSqlTableModel>
#include <QVariant>

class eventViewModelClass : public QSqlTableModel
{
public:
    eventViewModelClass(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase()) : QSqlTableModel(parent,db) {}
    bool select() override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // EVENTVIEWMODELCLASS_H
