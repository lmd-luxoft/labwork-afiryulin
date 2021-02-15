#include <QCoreApplication>
#include <QDebug>

#include "human.h"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    Human *human = qobject_cast<Human*>(parent);

    qDebug() << human->objectName()
             << "age: " << human->age()
             << "sex: " << human->sexSymbol();

    for(const auto& child : human->children())
    {
       printTreeInfo(child);
    }
}

Human* generateFamily()
{
    const char MALE = 'M';
    const char FEMALE = 'F';

    Human* parent = new Human();
    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSexSymbol(MALE);

    Human *maryGrey = new Human(parent);
    maryGrey->setObjectName("Mary Grey");
    maryGrey->setAge(28);
    maryGrey->setSexSymbol(FEMALE);

    Human *fredSmith = new Human(maryGrey);
    fredSmith->setObjectName("Fred Smith");
    fredSmith->setAge(2);
    fredSmith->setSexSymbol(MALE);

    Human *janeSmith = new Human(maryGrey);
    janeSmith->setObjectName("Jane Smith");
    janeSmith->setAge(2);
    janeSmith->setSexSymbol(FEMALE);

    Human *jasonGrey = new Human(parent);
    jasonGrey->setObjectName("Jason Grey");
    jasonGrey->setAge(32);
    jasonGrey->setSexSymbol(MALE);

    Human *seanGray = new Human(jasonGrey);
    seanGray->setObjectName("Sean Gray");
    seanGray->setAge(5);
    seanGray->setSexSymbol(MALE);

    Human *jasicaGray = new Human(jasonGrey);
    jasicaGray->setObjectName("Jasica Gray");
    jasicaGray->setAge(1);
    jasicaGray->setSexSymbol(FEMALE);

    Human *hannahGray = new Human(jasonGrey);
    hannahGray->setObjectName("Hannah Gray");
    hannahGray->setAge(1);
    hannahGray->setSexSymbol(FEMALE);

    return parent;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human *parent = generateFamily();

	// TODO: dump tree info using standard Qt method
	
    printTreeInfo(parent);

    // TODO: delete here what need only

    return a.exec();
}
