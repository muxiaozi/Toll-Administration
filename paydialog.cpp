#include "paydialog.h"
#include "ui_paydialog.h"
#include <QSqlQuery>
#include "database.h"
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QDate>

PayDialog::PayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PayDialog)
{
    ui->setupUi(this);
    //去掉问号按钮
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    payTableModel = new PayTableModel;
    ui->tabPay->setModel(payTableModel);
    ui->tabPay->verticalHeader()->setHidden(true);
    ui->tabPay->horizontalHeader()->setAlternatingRowColors(true);
    ui->tabPay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->tabPay->horizontalHeader()->setStretchLastSection(true);
}

PayDialog::~PayDialog()
{
    delete ui;
    delete payTableModel;
}

void PayDialog::setUser(int userId)
{
    setWindowTitle(Database::getUserNameById(userId) + "【"
                   + Database::getUserAddressById(userId) + "】 - "
                   + "缴费详情");
    payTableModel->setUser(userId);
}

/**
 * 缴费窗口的表格Model
 * 继承于QAbstractTableModel
 */
PayTableModel::PayTableModel()
{
}

int PayTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid()) return 0;
    return datas.size();
}

int PayTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid()) return 0;
    return headers.size();
}

QVariant PayTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    if(role == Qt::TextAlignmentRole){
        return Qt::AlignCenter;
    }else if(role == Qt::DisplayRole){
        return datas.at(index.row()).at(index.column());
    }
    return QVariant();
}

QVariant PayTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole || orientation == Qt::Vertical) return QVariant();
    return headers.at(section);
}

bool PayTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.column() == 4 && role == Qt::EditRole){
        bool ok;
        qreal v = value.toReal(&ok);
        if(ok){
            datas[index.row()][index.column()] = QString::number(v);
            datas[index.row()][5] = QString::number(datas.at(index.row()).at(3).toDouble() * v);
            //修改总金额
            qreal allMoney = 0.0;
            for(int i = 0; i < datas.size() - 1; i++){
                allMoney += datas.at(i).at(5).toDouble();
            }
            datas[datas.size() - 1][5] = QString::number(allMoney);
            return true;
        }
    }else if(index.column() == 6 && role == Qt::EditRole){
        if(!value.toString().isEmpty())
            datas[index.row()][6] = value.toString();
    }

    return false;
}

Qt::ItemFlags PayTableModel::flags(const QModelIndex &index) const
{
    //单价可编辑，但是最后一行是总价，所以datas.size() - 1
    if(index.column() == 4 && index.row() != datas.size() - 1){
        return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
    }else if(index.column() == 6){
        return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
    }else{
        return Qt::ItemIsEnabled;
    }
}

void PayTableModel::setUser(int userId)
{
    this->userId = userId;
    QDate currentDate(QDate::currentDate());

    beginResetModel();

    headers.clear();
    headers<<"项目"<<"上次读数"<<"本次读数"<<"数量"<<"单价"<<"金额"<<"日期";
    datas.clear();
    QSqlQuery query(QSqlDatabase::database());
    query.prepare(QString("SELECT meter_id,meter_name,max(quarter1,quarter2,quarter3,quarter4),"
                          "pay_record FROM y%1 WHERE user_id=? ORDER BY meter_id DESC").arg(currentDate.year()));
    query.bindValue(0, userId);
    query.exec();
    qreal allMoney = 0.0;

    while(query.next()){
        QStringList row;
        row<<query.value("meter_name").toString(); //项目
        int cnt = 0; //缴费量
        if(query.value("meter_id").toInt() == 0){
            row<<""<<""<<query.value("pay_record").toString();
            cnt = query.value("pay_record").toInt();
            double cleanUnitPrice = Database::getCleanUnitPrice();
            row<<QString::number(cleanUnitPrice); //单价
            row<<QString::number(cnt * cleanUnitPrice); //金额
        }else{
            row<<query.value("pay_record").toString(); //上次读数
            row<<query.value(2).toString(); //本次读数
            cnt = row.at(2).toInt() - row.at(1).toInt();
            row<<QString::number(cnt); //缴费量
            double waterUnitPrice = Database::getWaterUnitPrice();
            row<<QString::number(waterUnitPrice); //单价
            row<<QString::number(cnt * waterUnitPrice); //金额
        }

        row<<QString("%1.%2").arg(currentDate.year()).arg(currentDate.month());
        row<<query.value("meter_id").toString(); //meter_id
        //普通水表欠费 或 卫生费
//        if(cnt > 0 || (query.value("meter_id").toInt() == 0 && query.value("pay_record").toInt() > 0)){
        if(cnt >= 0){
            allMoney += row.at(5).toDouble();
            datas.append(row);
        }
    }

    QStringList lastRow;
    lastRow<<"总计"<<""<<""<<""<<""<<QString::number(allMoney)<<"";
    datas.append(lastRow);

    endResetModel();
}

QString PayTableModel::upperMoney(qreal x)
{
    QStringList NUM_C;
    NUM_C<<"零"<<"壹"<<"贰"<<"叁"<<"肆"<<"伍"<<"陆"<<"柒"<<"捌"<<
         "玖"<<"拾"<<"佰"<<"仟"<<"万"<<"亿";
    QString strNum = QString("%1").arg(x);
    int j;
    int length = strNum.size();

    int dotPos = strNum.indexOf('.');
    if(dotPos != -1){
        length = dotPos;
    }

    QString result;
    if(length == 1 && strNum[0] == '0')
        result.append(NUM_C[0]);
    else {
        for(int i = 0; i < length; i++) {
            if(strNum.at(i) == '0') {
                int offset = (length - i) % 4 == 0 ? 4 : (length - i) % 4;
                for(j = i + 1; j < i + offset; j++) {
                    if(strNum[j] != '0')
                        break;
                }
                if(j < i + offset && (strNum[i - 1] != '0' || (length - i) % 4 == 0))
                    result.append(NUM_C[strNum.at(i).toLatin1() - '0']);

            } else if(strNum[i] == '1') {
                if(length % 4 != 2 || i != 0)
                    result.append(NUM_C[strNum.at(i).toLatin1() - '0']);
            } else {
                result.append(NUM_C[strNum.at(i).toLatin1() - '0']);
            }

            switch((length - i) % 4) {
            case 0://千
                if(strNum[i] != '0')
                    result.append(NUM_C[12]);
                break;
            case 1: {
                switch((length - i) / 4) {
                case 1:
                    if(length > 8 && strNum[i] == '0' && strNum[i - 1] == '0' && strNum[i - 2] == '0' && strNum[i - 3] == '0');
                    else
                        result.append(NUM_C[13]);//万
                    break;
                case 2:
                    result.append(NUM_C[14]);//亿
                    break;
                }
                break;
            }
            case 2: { //十
                if(strNum[i] != '0')
                    result.append(NUM_C[10]);
                break;
            }
            case 3://百
                if(strNum[i] != '0')
                    result.append(NUM_C[11]);
                break;
            }
        }

        if(dotPos == -1){
            result.append("元整");
        }else{
            result.append("元");
            if(strNum.size() - length > 1){
                result.append(NUM_C[strNum.at(length + 1).toLatin1() - '0']).append("角");
            }
            if(strNum.size() - length > 2){
                result.append(NUM_C[strNum.at(length + 2).toLatin1() - '0']).append("分");
            }
        }
    }
    return result;
}

void PayTableModel::printPreview(QPrinter* printer)
{
    QPainter painter(printer);
    qreal cellWidth = printer->width() / 9; //excel显示宽度72像素
    qreal cellHeight = cellWidth / 72 * 20; //excel显示高度20像素
    qreal offsetHeight = 0;

    QFont font("宋体");
    font.setPointSize(11); //设置字体大小为11
    painter.setFont(font);

    painter.drawText(cellWidth * 4, cellHeight * 3 - cellHeight * 0.4, Database::getUserNameById(userId)); //户主
    painter.drawText(cellWidth * 6, cellHeight * 3 - cellHeight * 0.4, Database::getUserAddressById(userId)); //地址

    qreal allMoney = 0.0;
    QString info = QString("%1：").arg(Database::getUserNameById(userId));
    int curRow = 5;
    for(int i = 0; i < datas.size() - 1; i++){
        if(i > 0){
            offsetHeight = cellHeight / 2;
        }
        if(datas.at(i).at(5).toDouble() > 0){
            info.append(datas.at(i).at(0));
            info.append(datas.at(i).at(5));
            info.append(" ");
        }
        allMoney += datas.at(i).at(5).toDouble();
        painter.drawText(cellWidth * 1, cellHeight * curRow + offsetHeight, datas.at(i).at(0)); //收费项目
        painter.drawText(cellWidth * 2, cellHeight * curRow + offsetHeight, datas.at(i).at(1)); //上次读数
        painter.drawText(cellWidth * 3, cellHeight * curRow + offsetHeight, datas.at(i).at(2)); //本次读数
        painter.drawText(cellWidth * 4, cellHeight * curRow + offsetHeight, datas.at(i).at(3)); //缴费量
        painter.drawText(cellWidth * 5 - cellWidth * 0.3, cellHeight * curRow + offsetHeight, datas.at(i).at(4)); //单价
        painter.drawText(cellWidth * 6 - cellWidth * 0.3, cellHeight * curRow + offsetHeight, datas.at(i).at(5)); //金额
        painter.drawText(cellWidth * 7 - cellWidth * 0.5, cellHeight * curRow + offsetHeight, datas.at(i).at(6)); //日期
        curRow++;
    }

    painter.drawText(cellWidth * 5, cellHeight * 14, "实付："); //实付
    painter.drawText(cellWidth * 6, cellHeight * 14, QString("%1 元").arg(allMoney)); //实付
    painter.drawText(cellWidth * 4, cellHeight * 18, upperMoney(allMoney)); //金额大写
    painter.drawText(cellWidth * 5 - cellWidth * 0.5, cellHeight * 20, "樊"); //收费单位

    //收入
    Database::income(allMoney, info);
}

void PayDialog::on_btnboxPay_accepted()
{
    //设置打印机
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setPageOrientation(QPageLayout::Portrait);
    QPagedPaintDevice::Margins m;
    m.left = m.right = 17.8;
    m.top = m.bottom = 19.1;
    printer.setMargins(m);

    //生成预览
    //    QPrintPreviewDialog previewDialog(&printer, this);
    //    connect(&previewDialog, SIGNAL(paintRequested(QPrinter*)),
    //            payTableModel, SLOT(printPreview(QPrinter*)));
    //    previewDialog.exec();

    //直接打印
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec() == QDialog::Accepted){
        payTableModel->printPreview(&printer);
    }
}
