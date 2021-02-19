#include "textstreamreader.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

TextStreamReader::TextStreamReader(QObject *parent) : QObject(parent)
{

}

void TextStreamReader::readFromFile(QString fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    QTextStream stream(&file);
    forever {

        QString line = stream.readLine();

        if(line.isNull() || line.isEmpty())
        {
            break;
        }

        double data = line.toDouble();
        qDebug() << "Read: " << data;
        emit dataReaded(data);
    }
    emit allDataReaded();
    qDebug() << "End of input file";
}
