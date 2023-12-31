#ifndef ABOUTVM_H
#define ABOUTVM_H

#include "easy_import.h"

#include <QObject>
#include <QDebug>
#include <QQuickItem>
#include "mathservice.h"

class AboutVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * parent READ parent WRITE setParent)

    Q_PROPERTY(int inputCounter READ inputCounter WRITE setInputCounter NOTIFY inputCounterChanged)
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)

    int m_inputCounter;
    int m_counter;
    shared_ptr<MathService> m_service;
public:
    explicit AboutVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    explicit AboutVM(int counter, shared_ptr<MathService> service, QObject *parent = nullptr)
        : QObject(parent)
        , m_inputCounter { counter }
        , m_counter { counter }
        , m_service { service }
    { qDebug(); };
    ~AboutVM() { qDebug(); }

    int inputCounter() const { return m_inputCounter; }

    void setInputCounter(int counter) {
        m_inputCounter = counter;
        emit inputCounterChanged(m_inputCounter);
    }

    int counter() const { return m_counter; }

    void setCounter(int counter) {
        m_counter = counter;
        emit counterChanged(m_counter);
    }

    Q_INVOKABLE void decrease() { setCounter(m_service->decreaseValue(m_counter)); }

    Q_INVOKABLE void confirm() { emit confirmPressed(m_counter); }

signals:
    void counterChanged(int counter);
    void inputCounterChanged(int counter);
    void confirmPressed(int counter);
};

#endif // ABOUTVM_H
