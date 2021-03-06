#pragma once

#include <QObject>

class QEvent;
class QKeyEvent;
class QGuiApplication;
class QQmlApplicationEngine;

class SpaceModel;
class SpaceProxy;



class Game : public QObject
{
    Q_OBJECT

public:
    static void registerQmlTypes();
    static void init();
    static Game* gameFromQml();

public:
    explicit Game(QObject* parent = nullptr);
    virtual ~Game() override;

public:
    virtual bool eventFilter(QObject* watched, QEvent* event) override;

public:
    Q_INVOKABLE SpaceModel* model() const;
    Q_INVOKABLE SpaceProxy* proxy() const;

private:
    static QQmlApplicationEngine* m_engine;

private:
    bool keyPressEventFilter(QObject* watched, QKeyEvent* event);
    bool keyReleaseEventFilter(QObject* watched, QKeyEvent* event);

private:
    SpaceModel* m_model;
    SpaceProxy* m_proxy;

};
