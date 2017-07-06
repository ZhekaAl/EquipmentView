#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QSqlQuery>

class CustomModel : public QAbstractItemModel
{
public:
    explicit CustomModel();
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section,
                        Qt::Orientation /* orientation */,
                        int role) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
private:
    QStringList headers;

};

#endif // CUSTOMMODEL_H
