#include "ghost.h"
#include <QTimer>
#include <stdlib.h>

Ghost::Ghost(int sceneWidth, int sceneHeight, QGraphicsItem* parent)
    : QObject(), QGraphicsEllipseItem(parent), sceneWidth(sceneWidth), sceneHeight(sceneHeight) {
    setRect(0, 0, 50, 50);

    // Move the ghost
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Ghost::move() {
    if(!getHasHitPlayer()) {
        // Calculate new position
        int newX = x() + rand()%9-3;
        int newY = y() + rand()%9-3;
// ŞART BLOKLARIYLA HAYALETLERİN DIŞARI ÇIKMASINI ENGELLEDİK .

        // Check if the new position would be outside the scene boundaries
        if (newX < 0) {
            newX = 0;
        } else if (newX + rect().width() > sceneWidth) {
            newX = sceneWidth - rect().width();
        }

        if (newY < 0) {
            newY = 0;
        } else if (newY + rect().height() > sceneHeight) {
            newY = sceneHeight - rect().height();
        }

        // Move ghost to the new position
        setPos(newX, newY);
    }
}
