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

    QString m_text;
    int m_counter;
    shared_ptr<MathService> m_service;

signals:
    void confirmPressed(int counter);
    void decreased(QString const & text, int counter);

public:
    explicit AboutVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    explicit AboutVM(QString const & text, int counter, shared_ptr<MathService> service, QObject *parent = nullptr)
        : QObject(parent)
        , m_text { move(text) }
        , m_counter { counter }
        , m_service { service }
    { qDebug(); };
    ~AboutVM() { qDebug(); }

    Q_INVOKABLE void start() {
        emit decreased(m_text, m_counter);
    }

    Q_INVOKABLE void decrease() {
        m_counter = m_service->decreaseValue(m_counter);
        emit decreased(m_text, m_counter);
    }

    Q_INVOKABLE void confirm() {
        emit confirmPressed(m_counter);
    }
};

#endif // ABOUTVM_H
