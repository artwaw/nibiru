#include "eventviewmodelclass.h"

bool eventViewModelClass::select() {
    bool status = QSqlTableModel::select();
     if (!status)
         return status;
     while (canFetchMore()) {
         fetchMore();
     };
     return status;
}

QVariant eventViewModelClass::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return {QVariant()};
    if (role==Qt::DisplayRole) {
        //
    };
    if (role == Qt::TextAlignmentRole ) {
       if (index.column() == 1) {
          return QVariant(Qt::AlignLeft);
       };
       return QVariant(Qt::AlignCenter | Qt::AlignVCenter);
    };
    return QSqlTableModel::data(index,role);
}
