#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "incometablemodel.h"
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>
#include "database.h"

IncomeTableModel::IncomeTableModel()
{
    header<<"时间"<<"    金额    "<<"备注";
}

int IncomeTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    return data.size();
}

int IncomeTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return header.size();
}

QVariant IncomeTableModel::tableData(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
        return data.at(index.row()).at(index.column());
    else
        return QVariant();
}

double IncomeTableModel::update(long long julian)
{
    allIncome = 0;
    beginResetModel();
    data.clear();
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT time,money,info FROM income WHERE date=?");
    query.bindValue(0, julian);
    query.exec();
    QDate date = QDate::fromJulianDay(julian);
    QString strDate = QString("%1-%2-%3 ").arg(date.year()).arg(date.month()).arg(date.day());
    while(query.next()){
        QStringList row;
        row<<strDate + query.value(0).toString();
        row<<QString::number(query.value(1).toDouble(), 'f', 1);
        row<<query.value(2).toString();
        row<<QString::number(julian);   //date
        row<<query.value(0).toString(); //time
        data.append(row);
        allIncome += query.value(1).toString().toDouble();
    }
    endResetModel();
    return allIncome;
}

QVariant IncomeTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole){
        if(orientation == Qt::Horizontal)
            return header.at(section);
        else
            return section + 1;
    }
    return QVariant();
}

bool IncomeTableModel::onTableItemClicked(const QModelIndex &index)
{
    int res = QMessageBox::warning(0, "警告", QString("您确定要删除此记录？\n时间：%1\n金额：%2\n备注：%3")
                                   .arg(data.at(index.row()).at(0))
                                   .arg(data.at(index.row()).at(1))
                                   .arg(data.at(index.row()).at(2)),
                                   QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes){
        Database::delIncome(data.at(index.row()).at(3).toLongLong(), data.at(index.row()).at(4));
        allIncome -= data.at(index.row()).at(1).toDouble();
        emit onIncomeChanged(allIncome);
        beginResetModel();
        data.removeAt(index.row());
        endResetModel();
        return true;
    }else
        return false;
}
