#ifndef ABSTRACTPAGE_H
#define ABSTRACTPAGE_H

#include <qnamespace.h>
#include <QStringList>

class QVariant;
class QModelIndex;
class TableModel;

class AbstractPage
{
public:
    enum QueryMask{
        QueryAll = 0,       //忽略任何查询条件
        QueryPay = 1,       //查询缴过费的
        QueryNotPay = 2,    //查询没有缴费的
        QueryByAddress = 4, //按地址查询
        QueryByName = 8     //按姓名查询
    };

public:
    AbstractPage();
    virtual ~AbstractPage();

    //获取表头数据
    virtual QStringList getHeaderData() const;
    //获取表格数据
    virtual QVariant getTableData(const QModelIndex &index, int role) const;
    //获取表格行数
    virtual int row() const;
    //获取表格列数
    virtual int col() const;
    //获取表格格式
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    //用户设置数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    //表格被点击，如果内容有变动，返回true，否则返回false
    virtual bool onTableItemClicked(const QModelIndex& index);

    //更新数据内容
    virtual void update(int queryMask, int year, int floor, int unit, int number, const QString &name) = 0;

protected:
    QStringList headerData;
    QList<QStringList> tableData;
    TableModel* tableModel;
    int queryYear;
};

//销户页面
class DeleteUserPage : public AbstractPage{

public:
    bool onTableItemClicked(const QModelIndex &index);
    void update(int queryMask, int year, int floor, int unit, int number, const QString &name);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant getTableData(const QModelIndex &index, int role) const;

    bool delUserById(int userId);
};

//管理水表页面
class ManageMeterPage : public AbstractPage{

public:
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool onTableItemClicked(const QModelIndex &index);
    void update(int queryMask, int year, int floor, int unit, int number, const QString &name);
};

//记录水表页面
class PayDialog;
class RecordPage : public AbstractPage{

public:
    RecordPage();
    ~RecordPage();

    void update(int queryMask, int year, int floor, int unit, int number, const QString &name);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool onTableItemClicked(const QModelIndex &index);
    QVariant getTableData(const QModelIndex &index, int role) const;
private:
    PayDialog *payDialog;
};

#endif // ABSTRACTPAGE_H
