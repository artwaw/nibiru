#include "adddialoggeomodel.h"

bool addDialogGeoModel::select() {
     bool status = QSqlTableModel::select();
      if (!status)
          return status;
      while (canFetchMore()) {
          fetchMore();
      };
      return status;
}
