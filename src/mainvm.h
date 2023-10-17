#ifndef MAINVM_H
#define MAINVM_H

#include <QObject>
#include <QDebug>
#include <QQuickItem>

class MainVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * parent READ parent WRITE setParent) // !!! IMPORTANT !!!

    int m_counter = 0;

signals:
    void nextPressed(QString const &, int);
    void increased(int counter);

public:
    explicit MainVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    ~MainVM() { qDebug(); }

    Q_INVOKABLE void start() {
        emit increased(m_counter);
    }

    Q_INVOKABLE void increase() {
        m_counter ++;
        emit increased(m_counter);
    }

    Q_INVOKABLE void next() {
        emit nextPressed("PAM", m_counter);
    }
};

#endif // MAINVM_H
