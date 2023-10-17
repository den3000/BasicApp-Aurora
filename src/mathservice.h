#ifndef MATHSERVICE_H
#define MATHSERVICE_H

#include <QDebug>

class MathService {

public:
    explicit MathService() { qDebug(); };
    ~MathService() { qDebug(); }

    int increaseValue(int value) {
        return value + 1;
    }

    int decreaseValue(int value) {
        return value - 1;
    }
};
#endif // MATHSERVICE_H
