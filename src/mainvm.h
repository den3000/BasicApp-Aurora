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

    int m_counter = 0;

    shared_ptr<MathService> m_service;

signals:
    void nextPressed(QString const &, int);
    void increased(int counter);

public:
    explicit MainVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    explicit MainVM(shared_ptr<MathService> service, QObject *parent = nullptr)
        : QObject(parent)
        , m_service { service }
    { qDebug(); };
    ~MainVM() { qDebug(); }

    Q_INVOKABLE void start() {
        emit increased(m_counter);
    }

    Q_INVOKABLE void increase() {
        m_counter = m_service->increaseValue(m_counter);
        emit increased(m_counter);
    }

    Q_INVOKABLE void next() {
        emit nextPressed(QString("Счётчик увеличен до: %1").arg(m_counter), m_counter);
    }

public slots:
    void decreased(int counter) {
        m_counter = counter;
        emit increased(m_counter);
    }
};

#endif // MAINVM_H
