#include "datastreamwriter.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>

DataStreamWriter::DataStreamWriter(QString fileName, QObject *parent) : QObject(parent)
{
    // TODO: open file and create QDataStream
    file = new QFile(fileName);
    file->open(QIODevice::WriteOnly);
    stream = new QDataStream(file);
}

DataStreamWriter::~DataStreamWriter()
{
    delete stream;
    delete file;
}

void DataStreamWriter::writeData(double data)
{
    *stream << data;
    qDebug() << "Write: " << data;
}
