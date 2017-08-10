#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>

//初始化数据库
bool initDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    if(!db.open()){
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载数据库
    if(!initDatabase()){
        QMessageBox::critical(0, "数据库错误", "数据库引擎不能正确加载，请检查sqldrivers文件夹是否存在！", QMessageBox::Ok);
        return a.exit(-1);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
