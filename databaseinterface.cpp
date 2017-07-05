#include "databaseinterface.h"
#include <QtSql>

namespace DataBase
{
void buildBase()
{
    QSqlQuery q;
    q.clear();
    q.prepare("CREATE TABLE Types_Equipment (typeid INTEGER PRIMARY KEY  NOT NULL , typename VARCHAR[50] NOT NULL  UNIQUE )");
    q.exec();

    q.clear();
    q.prepare("CREATE TABLE List_Equipment (typeid INTEGER NOT NULL REFERENCES Types_Equipment ON DELETE CASCADE ON UPDATE CASCADE, equipid INTEGER PRIMARY KEY , equipname VARCHAR[50], date DATE, isactive BOOLEAN,   note TEXT)");
    q.exec();

}


void insertTypeEquipment(int typeNumber, QString typeName)
{
    QSqlQuery q;
    q.clear();
    QString s1,s2,s3,s4,s5;
    s1= "INSERT INTO 'Types_Equipment' (";
    s2= "'typeid', 'typename'";
    QStringList l = s2.split(",");
    for(int i=0;i<l.size()-1;i++)
        s4.append("?,");
    s4.append("?");

    s3=") VALUES(";
    s5=");";
    /* bool prep= */q.prepare(s1+s2+s3+s4+s5);
    q.addBindValue(typeNumber);
    q.addBindValue(typeName);
    /*prep=*/q.exec();
}

void insertInEquipmentList(int typeNumber, int id, QString name, QDate date, bool isActive, const QString& note)
{
    QSqlQuery q;
    q.clear();
    QString s1,s2,s3,s4,s5;
    s1= "INSERT INTO 'List_Equipment' (";
    s2= "'typeid', 'equipid', 'equipname', 'date', 'isactive', 'note'";
    QStringList l = s2.split(",");
    for(int i=0;i<l.size()-1;i++)
        s4.append("?,");
    s4.append("?");

    s3=") VALUES(";
    s5=");";
    /*bool prep=*/ q.prepare(s1+s2+s3+s4+s5);
    q.addBindValue(typeNumber);
    q.addBindValue(id);
    q.addBindValue(name);
    q.addBindValue(date);
    q.addBindValue(isActive);
    q.addBindValue(note);
    /*prep=*/q.exec();
}

void insertBaseEquipmentsList()
{

    QDate date = QDate::currentDate();
    QString name("Камаз № ");
    QString note("Описание Описание Описание Описание Описание");
    for(int i = 0; i< 100; ++i)
    {
      insertInEquipmentList(i%6, i, name + QString().setNum(i), date.addDays(i), i%2, note);
    }

}



void insertBaseTypesEquipment()
{
   insertTypeEquipment(0,"Не определено") ;
   insertTypeEquipment(1,"Наземное") ;
   insertTypeEquipment(2,"Летательный аппарат") ;
   insertTypeEquipment(3,"Спутник") ;
   insertTypeEquipment(4,"Антенна") ;
   insertTypeEquipment(5,"Мобильная установка") ;
}


void createEquipmentView()
{
    QSqlQuery query;

    QString queryString = "CREATE VIEW Equipmentview AS SELECT  equipid, equipname,typename ,date, isactive, note FROM List_Equipment  JOIN Types_Equipment ON(Types_Equipment.typeid = List_Equipment.typeid)";
    /*bool p= */query.prepare(queryString);
    /*p=*/ query.exec();


}

bool dataBaseOpen()
{
    bool emptyBase = true;

    QString dataBaseName("equipment.sqlite");


    QFile f(dataBaseName);
    if(f.exists())
        emptyBase=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dataBaseName);

    if(!db.open())
    {
        qDebug()<<"CatalogManager: dbOpen FALSE";
        return false;
    }


    if(emptyBase == true)
    {
        buildBase();
        insertBaseTypesEquipment();
        insertBaseEquipmentsList();
        createEquipmentView();
    }


    QSqlQuery q;
    q.exec("PRAGMA foreign_keys = ON");
//    if(!db.transaction())
//        qDebug()<<"dbOpen db.transaction() FALSE";

    return true;

}

QSqlRecord getRecord(int equipId)
{
    QSqlQuery query;
    /*bool p=*/ query.prepare("SELECT * FROM Equipmentview WHERE equipid=?");
    query.addBindValue(equipId);
    query.exec();
    query.first();
    return query.record();
}

int getEqupmentListCount()
{

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Equipmentview");
    query.exec();
    query.first();


    int count = query.record().value(0).toInt();
    return count;

}

}
