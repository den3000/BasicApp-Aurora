#ifndef MAINVM_H
#define MAINVM_H

#include <QObject>
#include <QDebug>
#include <QQuickItem>

class MainVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * parent READ parent WRITE setParent) // !!! IMPORTANT !!!
signals:
    void nextPressed();

public:
    explicit MainVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    ~MainVM() { qDebug(); }
};

#endif // MAINVM_H
