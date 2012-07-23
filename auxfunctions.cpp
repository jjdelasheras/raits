#include <QString>
#include "auxfunctions.h"

const QString tail(const QString& str)
{
    QString aux;
    for(int i = str.size() - 1;str[i] != '/' && 0 <= i;--i) {
        aux.push_front(str[i]);
    }
    return aux;
}
