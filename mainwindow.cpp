﻿#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "tablemodel.h"
#include "abstractpage.h"
#include "incometablemodel.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QDate>
#include <QTime>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();

    //初始化控件
    QStringList years;
    for(int i = 2017; i <= QDate::currentDate().year(); i++) years.append(QString::number(i));
    QStringList floors;
    for(int i = 1; i <= 15; i++) floors.append(QString::number(i));
    QStringList units;
    for(int i = 1; i <= 8; i++) units.append(QString::number(i));
    QStringList numbers;
    for(int i = 1; i <= 20; i++) numbers.append(QString::number(i));
    ui->cbAddUserFloor->addItems(floors);
    ui->cbAddUserUnit->addItems(units);
    ui->cbAddUserNumber1->addItems(numbers);
    ui->cbAddUserNumber2->addItems(numbers);
    ui->cbQueryYear->addItems(years);
    ui->cbQueryYear->setCurrentIndex(years.size() - 1);
    ui->cbQueryFloor->addItem("商户");
    ui->cbQueryFloor->addItems(floors);
    ui->cbQueryUnit->addItems(units);
    ui->cbQueryNumber->addItems(numbers);

    //初始化表格模块
    tableModel = new TableModel(this);
    ui->tabQuery->setModel(tableModel);
    ui->tabQuery->verticalHeader()->setHidden(true);
    ui->tabQuery->setAlternatingRowColors(true);
    ui->tabQuery->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    incomeTableModel = new IncomeTableModel(this);
    ui->tabIncome->setModel(incomeTableModel);
    //ui->tabIncome->verticalHeader()->setHidden(true);
    ui->tabIncome->setAlternatingRowColors(true);
    ui->tabIncome->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tabIncome->horizontalHeader()->setStretchLastSection(true);

    connect(ui->tabQuery, SIGNAL(clicked(QModelIndex)),
            tableModel, SLOT(onTableItemClicked(QModelIndex)));
    connect(ui->tabIncome, SIGNAL(activated(QModelIndex)),
            incomeTableModel, SLOT(onTableItemClicked(QModelIndex)));
    connect(incomeTableModel, SIGNAL(onIncomeChanged(double)), this, SLOT(onIncomeChanged(double)));
    connect(ui->rbQueryByAddress, SIGNAL(toggled(bool)), this, SLOT(queryByAddress(bool)));
    connect(ui->rbAddUserNormal, SIGNAL(toggled(bool)), this, SLOT(addNormalUser(bool)));

    ui->pages->setCurrentIndex(PageType::WELCOME);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableModel;
}

bool MainWindow::addUser(QString name, int floor, int unit, int number, int number1)
{
    //添加用户
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO user(user_name,floor,unit,number,number1) VALUES(?,?,?,?,?)");
    query.bindValue(0, name);
    query.bindValue(1, floor);
    query.bindValue(2, unit);
    query.bindValue(3, number);
    query.bindValue(4, number1);
    query.exec();

    //创建卫生费
    createCleanMeter(query.lastInsertId().toInt());
    return true;
}

bool MainWindow::updateUser(int userId, QString name, int floor, int unit, int number, int number1)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE user SET user_name=?,floor=?,unit=?,number=?,number1=? WHERE user_id=?");
    query.bindValue(0, name);
    query.bindValue(1, floor);
    query.bindValue(2, unit);
    query.bindValue(3, number);
    query.bindValue(4, number1);
    query.bindValue(5, userId);
    return query.exec();
}

bool MainWindow::addMerchant(QString name)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO user(user_name,floor,unit,number,number1) VALUES(?,0,0,0,0)");
    query.bindValue(0, name);
    query.exec();
    createCleanMeter(query.lastInsertId().toInt());
    return true;
}

bool MainWindow::hasMerchant(QString name)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT user_id FROM user WHERE user_name=? AND floor=0 AND unit=0 AND number=0");
    query.bindValue(0, name);
    query.exec();
    if(query.first()){
        return true;
    }
    return false;
}

bool MainWindow::createCleanMeter(int userId)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare(QString("INSERT INTO y%1 VALUES(?,0,'卫生费',0,0,0,0,0)")
                  .arg(QDate::currentDate().year()));
    query.bindValue(0, userId);
    return query.exec();
}

bool MainWindow::hasCleanTag()
{
    QSqlQuery query(QSqlDatabase::database());
    query.exec("SELECT value FROM config WHERE key='clean_tag'");
    if(query.first()){
        return query.value(0).toInt() == 1;
    }
    return false;
}

void MainWindow::setCleanTag(bool tag)
{
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE config SET value=? WHERE key='clean_tag'");
    query.bindValue(0, tag ? 1 : 0);
    query.exec();
}

void MainWindow::init()
{
    int currentYear = QDate::currentDate().year();
    QSqlQuery query(QSqlDatabase::database());

    //Initialize User table
    query.exec("SELECT COUNT(*) FROM sqlite_master where type='table' and name='user'");
    if(!query.first() || query.value(0).toInt() != 1){
        query.exec("CREATE TABLE user(user_id integer primary key autoincrement not null,"
                   "user_name text not null,floor integer not null,unit integer not null,"
                   "number integer not null,number1 integer not null)");
    }

    //Initialize Income table
    query.exec("SELECT COUNT(*) FROM sqlite_master where type='table' and name='income'");
    if(!query.first() || query.value(0).toInt() != 1){
        query.exec("CREATE TABLE income(date integer,time text,money real,info text,"
                   "primary key(date,time))");
    }

    //Initialize Config table
    query.exec("SELECT COUNT(*) FROM sqlite_master where type='table' and name='config'");
    if(!query.first() || query.value(0).toInt() != 1){
        query.exec("CREATE TABLE config(key text,value text,unique(key,value));");
        query.exec("INSERT INTO config values('water_unit_price',8)");
        query.exec("INSERT INTO config values('clean_unit_price',20)");
    }

    //Initialize Year table
    query.exec(QString("SELECT COUNT(*) FROM sqlite_master where type='table' and name='y%1'")
               .arg(currentYear));
    if(!query.first() || query.value(0).toInt() != 1){//如果没有今年的表
        query.exec(QString("CREATE TABLE y%1(user_id integer,meter_id integer,meter_name text,"
                   "quarter1 integer,quarter2 integer,quarter3 integer,quarter4 integer,"
                   "pay_record integer,primary key(user_id,meter_id))").arg(currentYear));

        query.exec(QString("INSERT INTO y%1 SELECT user_id,meter_id,meter_name,"
                           "max(quarter1,quarter2,quarter3,quarter4),0,0,0,pay_record FROM y%2")
                   .arg(currentYear).arg(currentYear - 1));
        setCleanTag(false);
    }

    //到11月了，准备收卫生费喽
    if(QDate::currentDate().month() >= 11 && !hasCleanTag()){
        setCleanTag(true);
        QSqlQuery query(QSqlDatabase::database());
        query.exec(QString("UPDATE y%1 SET pay_record=pay_record+1 WHERE meter_id=0")
                   .arg(currentYear));
    }
}

void MainWindow::on_actionAddUser_triggered()
{
    ui->pages->setCurrentIndex(PageType::ADD_USER);
}

void MainWindow::on_actionDeleteUser_triggered()
{
    ui->pages->setCurrentIndex(PageType::QUERY);
    tableModel->setShowMode(TableModel::DeleteUserMode);
    on_btnQuery_clicked();
}

void MainWindow::on_btnAddUserSubmit_clicked()
{
    if(ui->editAddUserName->text().isEmpty()){
        QMessageBox::warning(0, "温馨提示", "请填写用户名！");
        ui->editAddUserName->setFocus();
        return;
    }

    QString name = ui->editAddUserName->text().trimmed();

    if(ui->rbAddUserNormal->isChecked()){
        //添加普通用户
        int floor = ui->cbAddUserFloor->currentText().toInt();
        int unit = ui->cbAddUserUnit->currentText().toInt();
        int number = ui->cbAddUserNumber1->currentText().toInt();

        if(ui->cbAddUserNumber2->currentText() == "无"){ //只有一间房
            int id = Database::getUserIdByAddress(floor, unit, number);
            if(id == -1){
                addUser(name, floor, unit, number);
            }else{
                if(QMessageBox::question(0, "替换用户？", QString("是否要 “%1” 替换 “%2” ？")
                    .arg(name).arg(Database::getUserNameById(id)),
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){
                    return;
                }
                updateUser(id, name, floor, unit, number);
            }
        }else{ //霸占两件房
            int number1 = ui->cbAddUserNumber2->currentText().toInt();
            int id1 = Database::getUserIdByAddress(floor, unit, number);
            int id2 = Database::getUserIdByAddress(floor, unit, number1);
            if(id1 != -1 && id2 != -1){
                QMessageBox::critical(0, "错误", QString("用户 “%1” 和 “%2” 不能同时被替换，请至少先删除一个！")
                      .arg(Database::getUserNameById(id1)).arg(Database::getUserNameById(id2)), QMessageBox::Yes);
                return;
            }else if(id1 != -1){
                if(QMessageBox::question(0, "替换用户", QString("是否要 “%1” 替换 “%2” ？")
                    .arg(name).arg(Database::getUserNameById(id1)),
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){
                    return;
                }
                updateUser(id1, name, floor, unit, number, number1);
            }else if(id2 != -1){
                if(QMessageBox::question(0, "替换用户", QString("是否要 “%1” 替换 “%2” ？")
                    .arg(name).arg(Database::getUserNameById(id2)),
                                        QMessageBox::Yes|QMessageBox::No) == QMessageBox::No){
                    return;
                }
                updateUser(id2, name, floor, unit, number, number1);
            }else{
                addUser(name, floor, unit, number, number1);
            }
        }
    }else{
        //添加商家
        if(hasMerchant(name)){
            QMessageBox::critical(0, "错误", QString("已经有名为 “%1” 的商家，请查证后添加！").arg(name),
                                  QMessageBox::Ok);
            return;
        }
        addMerchant(name);
    }

    QMessageBox::information(0, "温馨提示", QString("用户 “%1” 添加/修改成功！").arg(name), QMessageBox::Ok);
    ui->editAddUserName->clear();
}

void MainWindow::on_actionManageMeter_triggered()
{
    ui->pages->setCurrentIndex(PageType::QUERY);
    tableModel->setShowMode(TableModel::ManageMetersMode);
    on_btnQuery_clicked();
}

void MainWindow::on_actionRecord_triggered()
{
    ui->pages->setCurrentIndex(PageType::QUERY);
    tableModel->setShowMode(TableModel::RecordMode);
    on_btnQuery_clicked();
}

void MainWindow::on_actionAbout_triggered()
{
    ui->pages->setCurrentIndex(PageType::WELCOME);
}

void MainWindow::on_actionHelp_triggered()
{
    ui->pages->setCurrentIndex(PageType::HELP);
}

void MainWindow::on_actionExit_triggered()
{
    if(QMessageBox::question(0, "温馨提示", "您确定要退出吗？", QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
            == QMessageBox::Yes){
        this->close();
    }
}

void MainWindow::queryByAddress(bool byAddress)
{
    if(byAddress){
        ui->cbQueryFloor->setEnabled(true);
        ui->cbQueryUnit->setEnabled(true);
        ui->cbQueryNumber->setEnabled(true);
        ui->editQueryName->setEnabled(false);
    }else{
        ui->cbQueryFloor->setEnabled(false);
        ui->cbQueryUnit->setEnabled(false);
        ui->cbQueryNumber->setEnabled(false);
        ui->editQueryName->setEnabled(true);
    }
}

void MainWindow::addNormalUser(bool normalUser)
{
    if(normalUser){
        ui->cbAddUserFloor->setEnabled(true);
        ui->cbAddUserUnit->setEnabled(true);
        ui->cbAddUserNumber1->setEnabled(true);
        ui->cbAddUserNumber2->setEnabled(true);
    }else{
        ui->cbAddUserFloor->setEnabled(false);
        ui->cbAddUserUnit->setEnabled(false);
        ui->cbAddUserNumber1->setEnabled(false);
        ui->cbAddUserNumber2->setEnabled(false);
    }
}

void MainWindow::on_btnQuery_clicked()
{
    //查询策略
    int queryMask = AbstractPage::QueryAll;
    if(ui->gbQueryPay->isChecked()){
        if(ui->rbQueryPay->isChecked()){
            queryMask |= AbstractPage::QueryPay;
        }else{
            queryMask |= AbstractPage::QueryNotPay;
        }
    }
    if(ui->gbQueryPolicy->isChecked()){
        if(ui->rbQueryByAddress->isChecked()){
            queryMask |= AbstractPage::QueryByAddress;
        }else{
            queryMask |= AbstractPage::QueryByName;
        }
    }

    //执行查询
    if(ui->cbQueryFloor->currentText() == "商户"){
        tableModel->query(queryMask, ui->cbQueryYear->currentText().toInt(),
                          0, 0, 0, ui->editQueryName->text());
    }else{
        tableModel->query(queryMask,
                         ui->cbQueryYear->currentText().toInt(),
                         ui->cbQueryFloor->currentText().toInt(),
                         ui->cbQueryUnit->currentText().toInt(),
                         ui->cbQueryNumber->currentText().toInt(),
                         ui->editQueryName->text());
    }
}

void MainWindow::on_actionSetCleanRate_triggered()
{
    bool ok;
    double price = QInputDialog::getDouble(0, "设置卫生费", "请输入每年应缴的卫生费（单位：元/年）",
                                           Database::getCleanUnitPrice(), 0, 10000, 1, &ok);
    if(ok){
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("UPDATE config SET value=? WHERE key='clean_unit_price'");
        query.bindValue(0, price);
        query.exec();
    }
}

void MainWindow::on_actionSetWaterRate_triggered()
{
    bool ok;
    double price = QInputDialog::getDouble(0, "设置水费", "请输入水费单价（单位：元/度）",
                                           Database::getWaterUnitPrice(), 0, 1000, 1, &ok);
    if(ok){
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("UPDATE config SET value=? WHERE key='water_unit_price'");
        query.bindValue(0, price);
        query.exec();
    }
}

void MainWindow::on_actionincome_triggered()
{
    ui->pages->setCurrentIndex(PageType::INCOME);
    on_btnTodayIncome_clicked();
}

void MainWindow::on_btnTodayIncome_clicked()
{
    ui->calendarIncome->setSelectedDate(QDate::currentDate());
    on_calendarIncome_clicked(QDate::currentDate());
}

void MainWindow::on_calendarIncome_clicked(const QDate &date)
{
    double allIncome = incomeTableModel->update(date.toJulianDay());
    ui->lblIncome->setText(QString("%1-%2-%3总收入：%4")
                           .arg(date.year())
                           .arg(date.month())
                           .arg(date.day())
                           .arg(allIncome));
}

void MainWindow::onIncomeChanged(double money)
{
    ui->lblIncome->setText(QString("%1-%2-%3总收入：%4")
                           .arg(ui->calendarIncome->selectedDate().year())
                           .arg(ui->calendarIncome->selectedDate().month())
                           .arg(ui->calendarIncome->selectedDate().day())
                           .arg(money));
}
