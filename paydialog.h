<<<<<<< HEAD
﻿#ifndef PAYDIALOG_H
#define PAYDIALOG_H

#include <QDialog>
#include <QAbstractTableModel>
#include <QStringList>

namespace Ui {
class PayDialog;
}

class PayTableModel;

class PayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PayDialog(QWidget *parent = 0);
    ~PayDialog();

    //设置用户
    void setUser(int userId);

private slots:
    void on_btnboxPay_accepted();

private:
    Ui::PayDialog *ui;

    PayTableModel *payTableModel;
};

/**
 * 缴费窗口的表格Model
 * 继承于QAbstractTableModel
 */
class QPrinter;
class PayTableModel : public QAbstractTableModel{
    Q_OBJECT

public:
    PayTableModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant tableData(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void setUser(int userId);

    //人民币转为大写
    QString upperMoney(qreal money);

public slots:
    void printPreview(QPrinter* printer);

private:
    QList<QStringList> datas;
    QStringList headers;

    int userId;
};

#endif // PAYDIALOG_H
=======
﻿#ifndef PAYDIALOG_H
#define PAYDIALOG_H

#include <QDialog>
#include <QAbstractTableModel>
#include <QStringList>

namespace Ui {
class PayDialog;
}

class PayTableModel;

class PayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PayDialog(QWidget *parent = 0);
    ~PayDialog();

    //设置用户
    void setUser(int userId);

private slots:
    void on_btnboxPay_accepted();

private:
    Ui::PayDialog *ui;

    PayTableModel *payTableModel;
};

/**
 * 缴费窗口的表格Model
 * 继承于QAbstractTableModel
 */
class QPrinter;
class PayTableModel : public QAbstractTableModel{
    Q_OBJECT

public:
    PayTableModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void setUser(int userId);

    //人民币转为大写
    QString upperMoney(qreal money);

public slots:
    void printPreview(QPrinter* printer);

private:
    QList<QStringList> datas;
    QStringList headers;

    int userId;
};

#endif // PAYDIALOG_H
>>>>>>> origin/master
