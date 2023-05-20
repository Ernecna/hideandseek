#include "ghost.h"
#include <QTimer>
#include <stdlib.h>


///////////////////////////////////////////////////////GHOST CLASS PART
Ghost::Ghost(QGraphicsItem* parent): QObject(), QGraphicsEllipseItem(parent) {
    setRect(0, 0, 50, 50);

    // Move the ghost
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);


}

void Ghost::move() {
    if(!getHasHitPlayer()) { // only move if hasHitPlayer is false
        // small movement
        //setPos(x()+rand()%3-1, y()+rand()%3-1);
        // bigger move
        setPos(x()+rand()%9-3, y()+rand()%9-3);
    }
}
