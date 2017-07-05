#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include<QString>
#include<QDate>
#include <QSqlRecord>

namespace DataBase
{

void buildBase();
void insertTypeEquipment(int typeNumber, QString typeName);
void insertInEquipmentList(int typeNumber, int id, QString name, QDate date, bool isActive, const QString& note);
void insertBaseEquipmentsList();
void insertBaseTypesEquipment();
bool dataBaseOpen();
QSqlRecord getRecord(int equipId);
int getEqupmentListCount();
}



#endif // DATABASEINTERFACE_H
