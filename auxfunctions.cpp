<<<<<<< HEAD
=======
#include <QString>
>>>>>>> f00fd46ea9c2e028b977141a6990a442a53c6a56
#include "auxfunctions.h"

const QString tail(const QString& str)
{
    QString aux;
    for(int i = str.size() - 1;str[i] != '/' && 0 <= i;--i) {
        aux.push_front(str[i]);
    }
    return aux;
}
