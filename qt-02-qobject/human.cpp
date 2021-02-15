#include <QDebug>

#include "human.h"

Human::Human(QObject *parent)
    : QObject(parent)
    , m_age(-1)
    , m_sexSymbol(' ')
{
}

Human::~Human()
{
    qDebug() << objectName() << " destroyed";
}
