#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TableModel;
class IncomeTableModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum PageType{
        WELCOME = 0,
        ADD_USER = 1,
        QUERY = 2,
        HELP = 3,
        INCOME = 4,
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //初始化系统
    void init();

    bool addUser(QString name, int floor, int unit, int number, int number1 = -1);
    bool updateUser(int userId, QString name, int floor, int unit, int number, int number1 = -1);

    bool addMerchant(QString name);
    bool hasMerchant(QString name);

    //给指定ID用户创建卫生费记录
    bool createCleanMeter(int userId);

    bool hasCleanTag(); //是否有卫生费
    void setCleanTag(bool tag); //设置每年卫生费，10月开始就该添加了

private slots:
    //添加用户
    void on_actionAddUser_triggered();

    //退出系统
    void on_actionExit_triggered();

    //关于
    void on_actionAbout_triggered();

    //帮助
    void on_actionHelp_triggered();

    //销户
    void on_actionDeleteUser_triggered();

    //添加用户按钮事件
    void on_btnAddUserSubmit_clicked();

    //管理水表
    void on_actionManageMeter_triggered();

    //记录水表值
    void on_actionRecord_triggered();

    //改变查询的方式（根据地址/根据户主名）
    void queryByAddress(bool byAddress);

    //改变添加用户的类型
    void addNormalUser(bool normalUser);

    //查询
    void on_btnQuery_clicked();

    void on_actionSetCleanRate_triggered();

    void on_actionSetWaterRate_triggered();

    //查询日收入
    void on_actionincome_triggered();

    //转到今天按钮
    void on_btnTodayIncome_clicked();

    //收入日历被选中
    void on_calendarIncome_clicked(const QDate &date);

    void onIncomeChanged(double money);

private:
    Ui::MainWindow *ui;

    //查询表格Model
    TableModel *tableModel;
    //收入表格Model
    IncomeTableModel *incomeTableModel;
};

#endif // MAINWINDOW_H
