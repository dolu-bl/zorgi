#pragma once

#include <QObject>
#include <QSize>

#include <vector>
#include <memory>

class Player;



class SpaceModel : public QObject
{
    Q_OBJECT

public:
    explicit SpaceModel(QObject* parent = nullptr);
    virtual ~SpaceModel() override;

public:
    Q_INVOKABLE Player* player() const;

private slots:
    void onPlayerPositionChanged(const QVector2D& position);

private:
    Player* m_player;

    QSize m_levelSize;
    QSize m_viewSize;

};
