#ifndef DICONSUMER_H
#define DICONSUMER_H

#include <QObject>
#include "dicontainer.h"

class DiConsumer: public QObject {
    Q_OBJECT

    DiContainer diContainer;

public:
    explicit DiConsumer(QObject * parent = nullptr)
        : QObject(parent)
    { qDebug(); }
    ~DiConsumer() { qDebug(); }

    Q_INVOKABLE MainVM * mainVmInstance()
        { return unique_unwrap(diContainer.mainVmInstance()); }

    Q_INVOKABLE AboutVM * aboutVmInstance(QString const & text, int counter)
        { return unique_unwrap(diContainer.aboutVmInstance(text, counter)); }
};
#endif // DICONSUMER_H
