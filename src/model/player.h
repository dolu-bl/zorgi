#pragma once

#include "item.h"



class Player : public Item
{
    Q_OBJECT

public:
    explicit Player(QObject* parent = nullptr);
    virtual ~Player() override;

public:
    virtual ItemType::Type type() const override;

};
