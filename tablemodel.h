﻿#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include "abstractpage.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum ShowMode{
        DeleteUserMode,     //删除用户
        ManageMetersMode,   //管理水表
        RecordMode          //记录水表
    };
public:
    explicit TableModel(QObject *parent = 0);
    ~TableModel();

    //行数
	int rowCount(const QModelIndex &parent) const;
    //列数
	int columnCount(const QModelIndex &parent) const;
    //获取表格数据
    QVariant data(const QModelIndex &index, int role) const;
    //获取表头数据
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //获取表格标记
    Qt::ItemFlags flags(const QModelIndex &index) const;
    //设置表格单个元素数据
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    //设置显示模式
    void setShowMode(const ShowMode& mode);

    //用户点击查询按钮
    void query(int queryMask, int year, int floor, int unit, int number, const QString &name);

public slots:
    //处理表点击事件
    void onTableItemClicked(const QModelIndex &index);

private:
    //当前页面
    AbstractPage* currentPage;

    DeleteUserPage* deleteUserPage;
    ManageMeterPage* manageMeterPage;
    RecordPage* recordPage;

    //展示风格
    ShowMode showMode;

};

#endif // TABLEMODEL_H
