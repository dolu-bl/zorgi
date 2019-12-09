#pragma once

#include <QObject>



class KeyEmitter : public QObject
{
    Q_OBJECT
public:
    explicit KeyEmitter(QObject* parent = nullptr);
    virtual ~KeyEmitter() override;

public slots:
    Q_INVOKABLE void emitKey(const Qt::Key key, const bool isPressed);

};
