#ifndef INCOMETABLEMODEL_H
#define INCOMETABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class IncomeTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit IncomeTableModel(QObject* parent = NULL);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const override;

    double update(long long julian);

public slots:
    bool onTableItemClicked(const QModelIndex& index);

signals:
    void onIncomeChanged(double money);

private:
    QStringList header;
    QList<QStringList> m_data;

    double allIncome;

};

#endif // INCOMETABLEMODEL_H
