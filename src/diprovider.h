#ifndef DIPROVIDER_H
#define DIPROVIDER_H

#include <QObject>
#include "dicontainer.h"

class DiProvider: public QObject {
    Q_OBJECT

    DiContainer diContainer;

    shared_ptr<MathService> m_mathService;
    shared_ptr<MathService> lazyMathService() {
        if(!m_mathService) {
            m_mathService = diContainer.mathServiceInstance();
        }
        return m_mathService;
    };

public:
    explicit DiProvider(QObject * parent = nullptr)
        : QObject(parent)
    { qDebug(); }
    ~DiProvider() { qDebug(); }

    Q_INVOKABLE MainVM * mainVmInstance()
        { return unique_unwrap(diContainer.mainVmInstance(lazyMathService())); }

    Q_INVOKABLE AboutVM * aboutVmInstance(QString const & text, int counter)
        { return unique_unwrap(diContainer.aboutVmInstance(text, counter, lazyMathService())); }
};
#endif // DIPROVIDER_H
