#ifndef DICONSUMER_H
#define DICONSUMER_H

#include <QObject>
#include "diprovider.h"

class DiConsumer: public QObject {
    Q_OBJECT

    DiProvider diProvider;

public:
    explicit DiConsumer(QObject * parent = nullptr)
        : QObject(parent)
    { qDebug(); }
    ~DiConsumer() { qDebug(); }

    Q_INVOKABLE MainVM * mainVmInstance()
        { return unique_unwrap(diProvider.mainVmInstance()); }

    Q_INVOKABLE AboutVM * aboutVmInstance(int counter)
        { return unique_unwrap(diProvider.aboutVmInstance(counter)); }
};
#endif // DICONSUMER_H
