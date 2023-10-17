#ifndef ABOUTVM_H
#define ABOUTVM_H

#include <QObject>
#include <QDebug>
#include <QQuickItem>

class AboutVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * parent READ parent WRITE setParent)

    int m_counter;

signals:
    void confirmPressed();
    void decreased(int counter);

public:
    explicit AboutVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    explicit AboutVM(int counter, QObject *parent = nullptr)
        : QObject(parent)
        , m_counter { counter }
    { qDebug(); };
    ~AboutVM() { qDebug(); }

    Q_INVOKABLE void start() {
        emit decreased(m_counter);
    }

    Q_INVOKABLE void decrease() {
        m_counter --;
        emit decreased(m_counter);
    }

    Q_INVOKABLE void confirm() {
        emit confirmPressed();
    }
};

#endif // ABOUTVM_H
