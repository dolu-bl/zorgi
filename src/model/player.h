#pragma once

#include "item.h"



class Player : public Item
{
    Q_OBJECT

public:
    explicit Player(QObject* parent = nullptr);
    virtual ~Player() override;

public:
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();

};
