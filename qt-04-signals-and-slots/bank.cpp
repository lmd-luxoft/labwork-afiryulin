#include "bank.h"
#include "bankaccount.h"

Bank::Bank(QObject *parent) : QObject(parent)
{
}

long Bank::totalBalance() const
{
    long totalBalance = 0;
    for(int i = 0; i < this->children().length(); ++i) {
        QObject *child = this->children().at(i);
        if (this->children().at(i)->inherits("BankAccount")) {
            totalBalance += qobject_cast<const BankAccount *> (child)->balance();
        }
    }
    return totalBalance;
}

// TODO: implement slot to listen accounts and emit totalBalanceChanged signal
void Bank::updateTotalBalance()
{
    emit totalBalanceChanged(totalBalance());
}
