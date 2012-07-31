#ifndef AUXFUNCTIONS_H
#define AUXFUNCTIONS_H
#include <QVector>

class QString;

const QString tail(const QString& str);

template <class T1, class T2, class T3>
void mapping(QVector<T1>* vec, T2 (*fp)(T1, T3));

#endif // AUXFUNCTIONS_H
