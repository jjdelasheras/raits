#include <QString>
#include <QVector>
#include "auxfunctions.h"

const QString tail(const QString& str)
{
    QString aux;
    for(int i = str.size() - 1;str[i] != '/' && 0 <= i;--i) {
        aux.push_front(str[i]);
    }
    return aux;
}

template <class T1, class T2, class T3>
void mapping(QVector<T1>* _vec, T2 _var, T3 (*fp)(T1, T2))
{
    for(int i = 0;i < _vec.size(); ++i)  {
        fp(_vec[i], _var);
    }
}
