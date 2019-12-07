#pragma once

#include "item.h"

class QPropertyAnimation;



class Player : public Item
{
    Q_OBJECT

public:
    explicit Player(QObject* parent = nullptr);
    virtual ~Player() override;

public:
    void startTurn(const Qt::ArrowType direction);
    void stopTurn();

    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveDown();

private:
    QPropertyAnimation* m_currentAnimation = nullptr;

};
