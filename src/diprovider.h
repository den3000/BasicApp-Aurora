#ifndef DIPROVIDER_H
#define DIPROVIDER_H

#include <QObject>
#include "dicontainer.h"

class DiProvider: public QObject {
    Q_OBJECT

    DiContainer diContainer;

public:
    explicit DiProvider(QObject * parent = nullptr)
        : QObject(parent)
    { qDebug(); }
    ~DiProvider() { qDebug(); }

    Q_INVOKABLE MainVM * mainVmInstance()
        { return unique_unwrap(diContainer.mainVmInstance()); }

    Q_INVOKABLE AboutVM * aboutVmInstance(QString const & text, int counter)
        { return unique_unwrap(diContainer.aboutVmInstance(text, counter)); }
};
#endif // DIPROVIDER_H
