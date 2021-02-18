#include <QCoreApplication>
#include "bankaccount.h"
#include <QDebug>
#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // don't change type of account, use it as QObject*
    QObject *account = new BankAccount;

    // TODO: set holder name
    // TODO: print it to qDebug()
    account->setProperty("holderName", QVariant("John Doe"));

    qDebug() << account->property("holderName").toString();
    qDebug() << account->property("balance").toLongLong();

    account->setProperty("balance", QVariant::fromValue(200L));
    qDebug() << account->property("balance").toLongLong();
    // TODO: get balance from property to qDebug()

    return a.exec();
}
