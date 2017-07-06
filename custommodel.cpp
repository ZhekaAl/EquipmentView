#include "custommodel.h"
#include "databaseinterface.h"

#include <QSqlRecord>

CustomModel::CustomModel()
{
    headers<< "Идентификатор записи"
           << "Тип "
           << "Наименование"
           << "Дата ввода в эксплуатацию"
           << "Активное"
           << "Примечание ";
}


QVariant CustomModel::headerData(int section,
                                 Qt::Orientation  orientation ,
                                 int role) const
{
    if (role == Qt::DisplayRole
            && section < headers.size()
            && orientation == Qt::Orientation::Horizontal)
        return headers.at(section);

    return QVariant();
}
int CustomModel::rowCount(const QModelIndex &/*parent*/) const
{
    return DataBase::getEqupmentListCount();
}
int CustomModel::columnCount(const QModelIndex &/*parent*/) const
{
    return headers.size();
}
QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    int row = index.row();
    QSqlRecord record = DataBase::getRecord(row);
    switch(index.column())
    {
        case 0: return record.value("equipid");
        case 1: return record.value("typename");
        case 2: return record.value("equipname");
        case 3: return record.value("date");
        case 4: return record.value("isactive");
        case 5: return record.value("note");
        default: return QVariant();
    }

}
QModelIndex CustomModel::index(int row, int column, const QModelIndex &) const
{
    return createIndex(row,column);
}

QModelIndex CustomModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}
