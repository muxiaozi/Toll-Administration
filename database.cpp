<<<<<<< HEAD
﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "database.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDate>
#include <QTime>

Database::Database()
{}

Database::~Database()
{}

QString Database::getUserNameById(int id)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT user_name FROM user WHERE user_id=?");
    query.bindValue(0, id);
    query.exec();
    if(query.first()){
        return query.value(0).toString();
    }
    return QString();
}

int Database::getUserIdByAddress(int floor, int unit, int number)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT user_id FROM user WHERE floor=? AND unit=? AND (number=? OR number1=?)");
    query.bindValue(0, floor);
    query.bindValue(1, unit);
    query.bindValue(2, number);
    query.bindValue(3, number);
    query.exec();
    if(query.first()){
        return query.value(0).toInt();
    }
    return -1;
}

QString Database::getUserAddressById(int userId)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT floor,unit,number,number1 FROM user WHERE user_id=?");
    query.bindValue(0, userId);
    query.exec();
    if(query.first()){
        if(query.value(0).toInt() == 0){
            return "商户";
        }else{
            bool hasTwoAddr = query.value(3).toInt() != -1;
            QString addr = QString("%1-%2-%3")
                    .arg(query.value(0).toString())
                    .arg(query.value(1).toString())
                    .arg(query.value(2).toString());
            if(hasTwoAddr) addr.append(",").append(query.value(3).toString());
            return addr;
        }
    }
    return QString();
}

double Database::getCleanUnitPrice()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT value FROM config WHERE key='clean_unit_price'");
    if(query.first()){
        return query.value(0).toDouble();
    }
    return 0.0f;
}

double Database::getWaterUnitPrice()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT value FROM config WHERE key='water_unit_price'");
    if(query.first()){
        return query.value(0).toDouble();
    }
    return 0.0f;
}

bool Database::income(double money, QString info)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO income(date,time,money,info) VALUES(?,?,?,?)");
    query.bindValue(0, QDate::currentDate().toJulianDay());
    query.bindValue(1, QTime::currentTime().toString());
    query.bindValue(2, money);
    query.bindValue(3, info);
    return query.exec();
}

bool Database::delIncome(long long date, QString time)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM income WHERE date=? AND time=?");
    query.bindValue(0, date);
    query.bindValue(1, time);
    return query.exec();
}


=======
﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "database.h"
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QDate>
#include <QTime>

Database::Database()
{}

Database::~Database()
{}

QString Database::getUserNameById(int id)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT user_name FROM user WHERE user_id=?");
    query.bindValue(0, id);
    query.exec();
    if(query.first()){
        return query.value(0).toString();
    }
    return QString();
}

int Database::getUserIdByAddress(int floor, int unit, int number)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT user_id FROM user WHERE floor=? AND unit=? AND (number=? OR number1=?)");
    query.bindValue(0, floor);
    query.bindValue(1, unit);
    query.bindValue(2, number);
    query.bindValue(3, number);
    query.exec();
    if(query.first()){
        return query.value(0).toInt();
    }
    return -1;
}

QString Database::getUserAddressById(int userId)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT floor,unit,number,number1 FROM user WHERE user_id=?");
    query.bindValue(0, userId);
    query.exec();
    if(query.first()){
        if(query.value(0).toInt() == 0){
            return "商户";
        }else{
            bool hasTwoAddr = query.value(3).toInt() != -1;
            QString addr = QString("%1-%2-%3")
                    .arg(query.value(0).toString())
                    .arg(query.value(1).toString())
                    .arg(query.value(2).toString());
            if(hasTwoAddr) addr.append(",").append(query.value(3).toString());
            return addr;
        }
    }
    return QString();
}

double Database::getCleanUnitPrice()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT value FROM config WHERE key='clean_unit_price'");
    if(query.first()){
        return query.value(0).toDouble();
    }
    return 0.0f;
}

double Database::getWaterUnitPrice()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT value FROM config WHERE key='water_unit_price'");
    if(query.first()){
        return query.value(0).toDouble();
    }
    return 0.0f;
}

bool Database::income(double money, QString info)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO income(date,time,money,info) VALUES(?,?,?,?)");
    query.bindValue(0, QDate::currentDate().toJulianDay());
    query.bindValue(1, QTime::currentTime().toString());
    query.bindValue(2, money);
    query.bindValue(3, info);
    return query.exec();
}

bool Database::delIncome(long long date, QString time)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM income WHERE date=? AND time=?");
    query.bindValue(0, date);
    query.bindValue(1, time);
    return query.exec();
}


>>>>>>> origin/master
