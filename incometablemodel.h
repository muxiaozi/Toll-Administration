#ifndef INCOMETABLEMODEL_H
#define INCOMETABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class IncomeTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    IncomeTableModel();

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant tableData(const QModelIndex &index, int role) const;

    double update(long long julian);

public slots:
    bool onTableItemClicked(const QModelIndex& index);

signals:
    void onIncomeChanged(double money);

private:
    QStringList header;
    QList<QStringList> data;

    double allIncome;

};

#endif // INCOMETABLEMODEL_H
