#include "abstractpage.h"
#include "tablemodel.h"
#include "database.h"
#include "paydialog.h"
#include <QModelIndex>
#include <QVariant>
#include <QSqlQuery>
#include <QMessageBox>
#include <QHash>
#include <QInputDialog>
#include <QDate>

AbstractPage::AbstractPage()
{}

AbstractPage::~AbstractPage()
{}

inline QStringList AbstractPage::getHeaderData() const
{ return headerData; }

QVariant AbstractPage::getTableData(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(role == Qt::TextAlignmentRole){
        return Qt::AlignCenter;
    }else if(role == Qt::DisplayRole){
        return tableData.at(index.row()).at(index.column());
    }
    return QVariant();
}

inline int AbstractPage::row() const
{ return tableData.size(); }

inline int AbstractPage::col() const
{ return headerData.size(); }

inline Qt::ItemFlags AbstractPage::flags(const QModelIndex& /*index*/) const
{ return Qt::ItemIsEnabled; }

bool AbstractPage::setData(const QModelIndex& /*index*/, const QVariant& /*value*/, int /*role*/)
{ return false; }

bool AbstractPage::onTableItemClicked(const QModelIndex& /*index*/)
{ return false; }

/**
 * 删除用户页面
 */
bool DeleteUserPage::onTableItemClicked(const QModelIndex &index)
{
    if(index.column() == col() - 1){
        if(QMessageBox::warning(0, "警告", QString("您确定要删除用户 “%1” ？")
                                .arg(Database::getUserNameById(tableData.at(index.row()).last().toInt())),
                                QMessageBox::Yes|QMessageBox::No, QMessageBox::No) == QMessageBox::Yes){
            delUserById(tableData.at(index.row()).last().toInt());
            tableData.removeAt(index.row());
            return true;
        }
    }
    return false;
}

void DeleteUserPage::update(int queryMask, int year, int floor, int unit, int number, const QString &name)
{
    queryYear = year;
    headerData.clear();
    headerData<<"用户名"<<"楼栋"<<"单元"<<"门牌号"<<"操作（危险）";

    tableData.clear();
    QSqlQuery query(QSqlDatabase::database());

    //构建sql语句
    QString sql("SELECT * FROM user");
    if(queryMask & QueryByAddress){
        sql.append(" WHERE floor=? AND unit=? AND (number=? OR number1=?)");
    }
    if(queryMask & QueryByName){
        sql.append(" WHERE user_name=?");
    }
    sql.append(" ORDER BY user.floor,user.unit,user.number");
    query.prepare(sql);

    //绑定参数
    if(queryMask & QueryByAddress){
        query.bindValue(0, floor);
        query.bindValue(1, unit);
        query.bindValue(2, number);
        query.bindValue(3, number);
    }
    if(queryMask & QueryByName){
        query.bindValue(0, name);
    }

    //执行sql语句
    query.exec();
    while(query.next()){
        QStringList row;
        row.append(query.value(1).toString());
        if(query.value(2).toInt() == 0){
            row<<"商户"<<""<<"";
        }else{
            row.append(query.value(2).toString());
            row.append(query.value(3).toString());
            if(query.value(5).toInt() != -1){
                row.append(query.value(4).toString() + "," + query.value(5).toString());
            }else{
                row.append(query.value(4).toString());
            }
        }
        row.append("删除");
        row.append(query.value(0).toString());
        tableData.append(row);
    }
}

Qt::ItemFlags DeleteUserPage::flags(const QModelIndex &index) const
{
    return AbstractPage::flags(index);
}

QVariant DeleteUserPage::getTableData(const QModelIndex &index, int role) const
{
    if(role == Qt::TextColorRole && index.column() == col() - 1){
        return QColor(255, 0, 0);
    }else{
        return AbstractPage::getTableData(index, role);
    }
}

bool DeleteUserPage::delUserById(int userId)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("DELETE FROM user WHERE user_id=?");
    query.bindValue(0, userId);
    query.exec();

    query.clear();
    query.prepare(QString("DELETE FROM y%1 WHERE user_id=?").arg(QDate::currentDate().year()));
    query.bindValue(0, userId);
    query.exec();
    return true;
}

/**
 * 管理水表页面
 */
Qt::ItemFlags ManageMeterPage::flags(const QModelIndex &index) const
{
    if(index.column() > 1){
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }else{
        return AbstractPage::flags(index);
    }
}

bool ManageMeterPage::onTableItemClicked(const QModelIndex &index)
{
    if(index.column() > 1){
        QStringList items;
        items<<"无"<<"厨房"<<"卫生间";
        bool ok;
        QString item = QInputDialog::getItem(0, "设置水表名", "请选择或填写水表名称", items, 1, true, &ok);
        if(ok && !item.isEmpty()){
            QSqlQuery query(QSqlDatabase::database());
            query.prepare(QString("SELECT * FROM y%1 WHERE user_id=? AND meter_id=?").arg(queryYear));
            query.bindValue(0, tableData.at(index.row()).last());
            query.bindValue(1, index.column() - 1);
            query.exec();
            bool meterExist = query.first();
            query.clear();
            if(item == "无"){
                if(meterExist){
                    query.prepare(QString("DELETE FROM y%1 WHERE user_id=? AND meter_id=?").arg(queryYear));
                    query.bindValue(0, tableData.at(index.row()).last());
                    query.bindValue(1, index.column() - 1);
                    if(query.exec()){
                        QStringList list = tableData.at(index.row());
                        list.replace(index.column(), "");
                        tableData.replace(index.row(), list);
                        return true;
                    }
                }
            }else{
                if(meterExist){
                    QString sql = QString("UPDATE y%1 SET meter_name=? WHERE user_id=? AND meter_id=?")
                            .arg(queryYear);
                    query.prepare(sql);
                    query.bindValue(0, item);
                    query.bindValue(1, tableData.at(index.row()).last());
                    query.bindValue(2, index.column() - 1);
                }else{
                    QString sql = QString("INSERT INTO y%1 VALUES(?,?,?,0,0,0,0,0)")
                            .arg(queryYear);
                    query.prepare(sql);
                    query.bindValue(0, tableData.at(index.row()).last());
                    query.bindValue(1, index.column() - 1);
                    query.bindValue(2, item);
                }
                if(query.exec()){
                    QStringList list = tableData.at(index.row());
                    list.replace(index.column(), item);
                    tableData.replace(index.row(), list);
                    return true;
                }
            }
        }
    }
    return false;
}

void ManageMeterPage::update(int queryMask, int year, int floor, int unit, int number, const QString &name)
{
    queryYear = year;
    headerData.clear();
    headerData<<"户主"<<"地址"<<"表1"<<"表2"<<"表3"<<"表4";

    tableData.clear();
    QSqlQuery query(QSqlDatabase::database());

    //构建sql语句
    QString sql("SELECT * FROM user");
    if(queryMask & QueryByAddress){
        sql.append(" WHERE floor=? AND unit=? AND (number=? OR number1=?)");
    }
    if(queryMask & QueryByName){
        sql.append(" WHERE user_name=?");
    }
    sql.append(" ORDER BY user.floor,user.unit,user.number");
    query.prepare(sql);

    //绑定参数
    if(queryMask & QueryByAddress){
        query.bindValue(0, floor);
        query.bindValue(1, unit);
        query.bindValue(2, number);
        query.bindValue(3, number);
    }
    if(queryMask & QueryByName){
        query.bindValue(0, name);
    }

    //执行sql语句
    query.exec();
    QSqlQuery subQuery(QSqlDatabase::database());
    while(query.next()){
        int userId = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString address;
        if(query.value(2).toInt() == 0){
            address = "商户";
        }else{
            address = QString("%1-%2-%3")
                    .arg(query.value(2).toInt())
                    .arg(query.value(3).toInt())
                    .arg(query.value(4).toInt());
        }

        QStringList row;
        row<<name<<address;
        subQuery.clear();
        subQuery.prepare(QString("SELECT meter_id,meter_name FROM y%1 WHERE user_id=?").arg(queryYear));
        subQuery.bindValue(0, userId);
        subQuery.exec();
        QString meters[4];
        while(subQuery.next()){
            if(subQuery.value(0) > 0){
                meters[subQuery.value(0).toInt() - 1] = subQuery.value(1).toString();
            }
        }
        for(int i = 0; i < 4; i++) row.append(meters[i]);
        row.append(QString::number(userId));
        tableData.append(row);
    }
}

/**
 * 记录水表页面
 */
RecordPage::RecordPage()
{
    payDialog = new PayDialog;
}

RecordPage::~RecordPage()
{
    delete payDialog;
}

void RecordPage::update(int queryMask, int year, int floor, int unit, int number, const QString &name)
{
    queryYear = year;
    headerData.clear();
    headerData<<"户主"<<"地址"<<"项目"<<"1 - 3"<<"4 - 6"<<"7 - 9"<<"10 - 12"<<"操作";

    tableData.clear();

    //构建sql语句
    QSqlQuery query(QSqlDatabase::database());
    QString sql = QString("SELECT user.user_id,user.user_name,user.floor,user.unit,user.number,y%1.meter_id,"
                          "y%1.meter_name,y%1.quarter1,y%1.quarter2,y%1.quarter3,y%1.quarter4,y%1.pay_record FROM user"
                          " INNER JOIN y%1 ON user.user_id=y%1.user_id").arg(year);
    if(queryMask & QueryByAddress){
        sql.append(" WHERE user.floor=? AND user.unit=? AND (user.number=? OR user.number1=?)");
    }
    if(queryMask & QueryByName){
        sql.append(" WHERE user.user_name=?");
    }

    sql.append(" ORDER BY user.floor,user.unit,user.number");
    query.prepare(sql);

    //绑定参数
    if(queryMask & QueryByAddress){
        query.bindValue(0, floor);
        query.bindValue(1, unit);
        query.bindValue(2, number);
        query.bindValue(3, number);
    }
    if(queryMask & QueryByName){
        query.bindValue(0, name);
    }

    //执行sql语句
    query.exec();
    while(query.next()){
        QStringList row;
        row.append(query.value(1).toString()); //户主 0
        if(query.value(2).toInt() == 0){
            row.append("商户");
        }else{
            row.append(QString("%1-%2-%3")
                       .arg(query.value(2).toString())
                       .arg(query.value(3).toString())
                       .arg(query.value(4).toString())); //地址 1
        }
        row.append(query.value(6).toString() + "（" + query.value(11).toString() + "）"); //表名 2
        if(query.value(5).toInt() == 0){
            row<<""<<""<<""<<"";
        }else{
            row.append(query.value(7).toString()); //一季度 3
            row.append(query.value(8).toString()); //二季度 4
            row.append(query.value(9).toString()); //三季度 5
            row.append(query.value(10).toString()); //四季度 6
        }
        row.append(QDate::currentDate().year() == queryYear ? "缴费" : ""); //7
        row.append(query.value(0).toString()); //user_id 8
        row.append(query.value(5).toString()); //meter_id 9
        row.append(query.value(11).toString()); //pay_record 10
        tableData.append(row);
    }
}

Qt::ItemFlags RecordPage::flags(const QModelIndex &index) const
{
    if(index.column() > 2 && index.column() < 7){
        if(tableData.at(index.row()).at(9).toInt() == 0) //卫生费不应该有数据
            return Qt::NoItemFlags;
        else
            return Qt::ItemIsEnabled | Qt::ItemIsEditable;
    }else{
        return AbstractPage::flags(index);
    }
}

bool RecordPage::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole && !value.toString().isEmpty()){
        bool ok;
        int v = value.toInt(&ok);
        if(ok){
            QString sql = QString("UPDATE y%1 SET quarter%2=? WHERE user_id=? AND meter_id=?")
                    .arg(queryYear).arg(index.column() - 2);
            QSqlQuery query(QSqlDatabase::database());
            query.prepare(sql);
            query.bindValue(0, v);
            query.bindValue(1, tableData.at(index.row()).at(col()));
            query.bindValue(2, tableData.at(index.row()).at(col()+1));

            if(query.exec()){
                tableData[index.row()][index.column()] = value.toString();
                return true;
            }
        }
    }
    return false;
}

bool RecordPage::onTableItemClicked(const QModelIndex &index)
{
    if(index.column() == 2){ //设置水表底数
        bool ok;
        int res = QInputDialog::getInt(0, "设置底数", QString("为%1的%2设置底数")
                                       .arg(tableData.at(index.row()).at(0))
                                       .arg(tableData.at(index.row()).at(2)),
                                       tableData.at(index.row()).at(10).toInt(), 0, 99999, 1, &ok);
        if(ok){
            QSqlQuery query(QSqlDatabase::database());
            query.prepare(QString("UPDATE y%1 SET pay_record=? WHERE user_id=? AND meter_id=?").arg(queryYear));
            query.bindValue(0, res);
            query.bindValue(1, tableData.at(index.row()).at(8));
            query.bindValue(2, tableData.at(index.row()).at(9));
            query.exec();
            tableData[index.row()][10] = QString::number(res);
            return true;
        }
    }else if(index.column() == 7 && tableData.at(index.row()).at(index.column()) == "缴费"){//缴费
        int userId = tableData.at(index.row()).at(col()).toInt();
        payDialog->setUser(userId);
        if(payDialog->exec() == QDialog::Accepted){ //缴费成功
            //更新数据库
            QSqlQuery query(QSqlDatabase::database());
            query.prepare(QString("UPDATE y%1 SET pay_record=max(quarter1,quarter2,quarter3,quarter4)"
                                  " WHERE user_id=?").arg(queryYear));
            query.bindValue(0, userId);
            query.exec();

            query.prepare(QString("UPDATE y%1 SET pay_record=0 WHERE user_id=? AND meter_id=0").arg(queryYear));
            query.bindValue(0, userId);
            query.exec();

            //更新显示
            for(int i = index.row() - 3; i < index.row() + 3; i++){
                if(i >= 0 && i < tableData.size() && tableData.at(i).at(8).toInt() == userId){

                    if(tableData.at(i).at(9).toInt() == 0){ //卫生费
                        tableData[i][10] = "0";
                    }else{
                        int max = tableData.at(i).at(3).toInt();
                        if(max < tableData.at(i).at(4).toInt())
                            max = tableData.at(i).at(4).toInt();
                        if(max < tableData.at(i).at(5).toInt())
                            max = tableData.at(i).at(5).toInt();
                        if(max < tableData.at(i).at(6).toInt())
                            max = tableData.at(i).at(6).toInt();
                        tableData[i][10] = QString::number(max);
                    }
                }
            }
            return true;
        }
    }
    return false;
}

QVariant RecordPage::getTableData(const QModelIndex &index, int role) const
{
    if(role == Qt::BackgroundColorRole && index.column() > 2 && index.column() < 7){
        if(tableData.at(index.row()).at(index.column()).toInt() > tableData.at(index.row()).last().toInt()){
            return QColor(255, 100, 100);
        }
        if(tableData.at(index.row()).at(9).toInt() == 0 && tableData.at(index.row()).last().toInt() > 0){
            return QColor(255, 100, 100);
        }
    }else if(role == Qt::TextColorRole && index.column() == col() - 1){
        return QColor(0, 0, 255);
    }else if(role == Qt::TextAlignmentRole && index.column() == 2){
        return Qt::AlignLeft;
    }
    return AbstractPage::getTableData(index, role);
}
