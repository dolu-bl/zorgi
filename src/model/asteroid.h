#pragma once

#include "item.h"



class Asteroid : public Item
{
    Q_OBJECT

public:
    explicit Asteroid(QObject* parent = nullptr);
    virtual ~Asteroid() override;

    virtual ItemType::Type type() const override;

};
