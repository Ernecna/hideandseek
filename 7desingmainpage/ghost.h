#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Ghost: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ghost(int sceneWidth, int sceneHeight, QGraphicsItem* parent=nullptr);
     ~Ghost();
public slots:
    void move();
    bool getHasHitPlayer() const { return hasHitPlayer; }
    void setHasHitPlayer(bool hitPlayer) { hasHitPlayer = hitPlayer; }

private:
    bool hasHitPlayer;
    int sceneWidth;
    int sceneHeight;


};

#endif // GHOST_H
