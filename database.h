<<<<<<< HEAD
﻿#ifndef DATABASE_H
#define DATABASE_H

class QString;

class Database
{
public:
	Database();
	~Database();

    //通过id获取用户名
    static QString getUserNameById(int id);

    //如果有用户，返回他的ID，否则返回-1
    static int getUserIdByAddress(int floor, int unit, int number);

    //通过id获取地址
    static QString getUserAddressById(int userId);

    //水费
    static double getCleanUnitPrice();
    //卫生费
    static double getWaterUnitPrice();

    //收入
    static bool income(double money, QString info);
    //删除收入记录
    static bool delIncome(long long date, QString time);

};

#endif // DATABASE_H
=======
﻿#ifndef DATABASE_H
#define DATABASE_H

class QString;

class Database
{
public:
	Database();
	~Database();

    //通过id获取用户名
    static QString getUserNameById(int id);

    //如果有用户，返回他的ID，否则返回-1
    static int getUserIdByAddress(int floor, int unit, int number);

    //通过id获取地址
    static QString getUserAddressById(int userId);

    //水费
    static double getCleanUnitPrice();
    //卫生费
    static double getWaterUnitPrice();

    //收入
    static bool income(double money, QString info);
    //删除收入记录
    static bool delIncome(long long date, QString time);

};

#endif // DATABASE_H
>>>>>>> origin/master
