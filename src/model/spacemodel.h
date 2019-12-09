#pragma once

#include <QObject>
#include <QSize>

#include <vector>
#include <memory>

class QEvent;
class QKeyEvent;

class Player;



class SpaceModel : public QObject
{
    Q_OBJECT

public:
    explicit SpaceModel(QObject* parent = nullptr);
    virtual ~SpaceModel() override;

public:
    Q_INVOKABLE Player* player() const;

    virtual bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onPlayerPositionChanged(const QVector2D& position);

private:
    bool keyPressEventFilter(QObject* watched, QKeyEvent* event);
    bool keyReleaseEventFilter(QObject* watched, QKeyEvent* event);

private:
    Player* m_player;

    QSize m_levelSize;
    QSize m_viewSize;

};
