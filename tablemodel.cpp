#include "tablemodel.h"
#include <QSqlQuery>
#include <QMessageBox>

TableModel::TableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    currentPage = nullptr;

    deleteUserPage = new DeleteUserPage();
    manageMeterPage = new ManageMeterPage();
    recordPage = new RecordPage();
}

TableModel::~TableModel()
{
    delete deleteUserPage;
    delete manageMeterPage;
    delete recordPage;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if(currentPage == nullptr || parent.isValid()) return 0;
    return currentPage->row();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if(currentPage == nullptr || parent.isValid()) return 0;
    return currentPage->col();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    return currentPage->getTableData(index, role);
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole || orientation == Qt::Vertical) return QVariant();
    return currentPage->getHeaderData().at(section);
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return currentPage->flags(index);
}

void TableModel::setShowMode(const TableModel::ShowMode& mode)
{
    if(showMode != mode){
        showMode = mode;
        switch(mode){
        case DeleteUserMode:
            currentPage = deleteUserPage;
            break;
        case ManageMetersMode:
            currentPage = manageMeterPage;
            break;
        case RecordMode:
            currentPage = recordPage;
            break;
        }
    }
}

void TableModel::query(int queryMask, int year, int floor, int unit, int number, const QString &name)
{
    beginResetModel();
    currentPage->update(queryMask, year, floor, unit, number, name);
    endResetModel();
}

void TableModel::onTableItemClicked(const QModelIndex &index)
{
    if(currentPage->onTableItemClicked(index)){
        beginResetModel();
        endResetModel();
    }
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return currentPage->setData(index, value, role);
}
