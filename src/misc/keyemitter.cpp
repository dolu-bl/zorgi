#include <QQuickItem>
#include <QGuiApplication>

#include "keyemitter.h"



KeyEmitter::KeyEmitter(QObject* parent)
    : QObject(parent)
{
}

KeyEmitter::~KeyEmitter()
{
}

void KeyEmitter::emitKey(const Qt::Key key, const bool isPressed)
{
    auto receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
    if (nullptr == receiver)
        return;

    const QEvent::Type type = isPressed ? QEvent::KeyPress : QEvent::KeyRelease;
    QKeyEvent event(type, key, Qt::NoModifier, QKeySequence(key).toString());
    QCoreApplication::sendEvent(receiver, &event);
}
