#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
public:
    explicit Human(QObject *parent = nullptr);
    ~Human();
signals:

public:
    inline const int &age() const;
    inline void setAge(const int& age);
    inline const char& sexSymbol() const;
    inline void setSexSymbol(const char sexSymbol);
private:
    int     m_age;
    char    m_sexSymbol;
};

inline const int &Human::age() const
{
    return m_age;
}

inline void Human::setAge(const int &age)
{
    m_age = age;
}

inline const char &Human::sexSymbol() const
{
    return m_sexSymbol;
}

inline void Human::setSexSymbol(const char sexSymbol)
{
    m_sexSymbol = sexSymbol;
}

#endif // HUMAN_H
