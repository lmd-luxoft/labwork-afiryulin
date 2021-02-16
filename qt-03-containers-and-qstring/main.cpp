#include <QCoreApplication>
#include <QDebug>
#include <QStack>

#include <QListIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name
    QListIterator<QString> javaStyleIterator(names);
    QString longestName;
    while(javaStyleIterator.hasNext())
    {
        QString currentName = javaStyleIterator.next();
        if(currentName.length() > longestName.length())
        {
            longestName = currentName;
        }
    }

    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);


    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name
    QString shortestName = longestName;
    for(QList<QString>::iterator i = names.begin(); i != names.end(); i++)
    {
        if(shortestName.length() > i->length())
        {
            shortestName = *i;
        }
    }
    qDebug() << shortestName.prepend("Shortest name: ");


    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string
    QStringList lynnSuffixNames;
    for(auto it = names.begin(); it !=names.end(); it++)
    {
        if(it->endsWith("lynn"))
        {
            lynnSuffixNames.append(*it);
        }
    }

    qDebug() << lynnSuffixNames;

    // print all names in reverse order
    // TODO: 1. Using QStack
    QStack<QString> stack;
    for(auto it = names.rbegin(); it !=names.rend(); it++)
    {
        stack.push_back(*it);
    }
    qDebug() << "QStack reverse " << stack;

    // TODO: 2. Using other QList
    QList<QString> reverceNames{names.rbegin(), names.rend()};
    qDebug() << "QList reverse " << reverceNames;

    // TODO: 3. Without other containers
    for(auto it = names.rbegin(); it !=names.rend(); it++)
    {
        qDebug() << *it;
    }

    return a.exec();
}
