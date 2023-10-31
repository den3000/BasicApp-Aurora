#ifndef MATHSERVICE_H
#define MATHSERVICE_H

#include <QDebug>

class MathService {
    int m_increment;
public:
    explicit MathService(int increment)
        : m_increment { increment }
    { qDebug(); };
    ~MathService() { qDebug(); }

    int increaseValue(int value) { return value + m_increment; }

    int decreaseValue(int value) { return value - m_increment; }
};
#endif // MATHSERVICE_H
