#pragma once

#include <QObject>



namespace ItemType
{
Q_NAMESPACE
enum Type
{
    Invalid = 0,
    Player = 1,
    Asteroid = 2,
};
Q_ENUM_NS(Type)
} // namespace ItemType
