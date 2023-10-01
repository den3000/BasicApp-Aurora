#ifndef MAINVM_H
#define MAINVM_H

#include <QObject>
#include <QDebug>
#include <QQuickItem>

class MainVM : public QObject
{
    Q_OBJECT

public:
    explicit MainVM(QObject *parent = nullptr): QObject(parent) { qDebug(); };
    ~MainVM() { qDebug(); }

    Q_INVOKABLE void nextPressed() { qDebug(); }
};

#endif // MAINVM_H
