#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QString>
#include <QDate>
#include <QSqlRecord>

class DataBase
{
 public:

    static bool dataBaseOpen(QString name);
    static QSqlRecord getRecord(int equipId);
    static int getEqupmentListCount();

    DataBase() = delete;
    DataBase(const DataBase&) = delete;
    DataBase & operator =(const DataBase&) = delete;

 private:
    static void buildBase();
    static void insertTypeEquipment(int typeNumber, QString typeName);
    static void insertInEquipmentList(int typeNumber, int id, QString name, QDate date, bool isActive, const QString& note);
    static void insertBaseEquipmentsList();
    static void insertBaseTypesEquipment();
    static void createEquipmentView();

};



#endif // DATABASEINTERFACE_H
