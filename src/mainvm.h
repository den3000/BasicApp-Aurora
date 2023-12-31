#ifndef MAINVM_H
#define MAINVM_H

#include "easy_import.h"
#include <QObject>
#include <QDebug>
#include <QQuickItem>
#include "mathservice.h"

class MainVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * parent READ parent WRITE setParent) // !!! IMPORTANT !!!

    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)

    int m_counter = 0;
    shared_ptr<MathService> m_service;
public:
    explicit MainVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    explicit MainVM(shared_ptr<MathService> service, QObject *parent = nullptr)
        : QObject(parent)
        , m_service { service }
    { qDebug(); };
    ~MainVM() { qDebug(); }

    int counter() const { return m_counter; }

    void setCounter(int counter) {
        m_counter = counter;
        emit counterChanged(m_counter);
    }

    Q_INVOKABLE void increase() { setCounter(m_service->increaseValue(m_counter)); }

    Q_INVOKABLE void next() { emit nextPressed(m_counter); }

signals:
    void counterChanged(int counter);
    void nextPressed(int);

public slots:
    void decreased(int counter) { setCounter(counter); }
};

#endif // MAINVM_H
