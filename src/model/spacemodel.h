#pragma once

#include <QObject>
#include <QVector2D>

class QTimer;

class Item;
class Player;



class SpaceModel : public QObject
{
    Q_OBJECT

public:
    explicit SpaceModel(QObject* parent = nullptr);
    virtual ~SpaceModel() override;

public:
    Q_INVOKABLE int itemsCount() const;
    Q_INVOKABLE Item* item(int i) const;
    Q_INVOKABLE QVector<Item*> items() const;

    Q_INVOKABLE QVector<Player*> players() const;

private slots:
    void onMainTimer();

private:
    // TODO : move fileData() to another entity
    void fillData();

private:
    QVector<Item*> m_items;
    QTimer* m_mainTimer = nullptr;

};
