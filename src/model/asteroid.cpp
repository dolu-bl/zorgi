#include <QSize>

#include "asteroid.h"

Asteroid::Asteroid(QObject* parent)
    : Item(parent)
{
    setSize(QSize(50, 50));
}

Asteroid::~Asteroid()
{
}



ItemType::Type Asteroid::type() const
{
    return ItemType::Asteroid;
}
