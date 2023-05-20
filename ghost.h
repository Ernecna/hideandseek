#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Ghost: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ghost(QGraphicsItem* parent=nullptr);
public slots:
    void move();
    bool getHasHitPlayer() const { return hasHitPlayer; }
    void setHasHitPlayer(bool hitPlayer) { hasHitPlayer = hitPlayer; }

private:
    bool hasHitPlayer;

};

#endif // GHOST_H
