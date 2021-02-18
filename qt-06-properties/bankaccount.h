#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>

class BankAccount : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName)
    Q_PROPERTY(quint64 balance MEMBER m_balance READ balance CONSTANT)

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    inline void setHolderName(QString holderName);
    inline QString holderName() const;
    inline quint32 balance() const;

public slots:


private:
    // TODO: declare holderName
    long m_balance;
    QString m_holderName;
};

inline QString BankAccount::holderName() const
{
    return m_holderName;
}

void BankAccount::setHolderName(QString holderName)
{
    m_holderName = holderName;
}

quint32 BankAccount::balance() const
{
    return m_balance;
}

#endif // BANKACCOUNT_H
