#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> really large int
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

Game::Game(QWidget* parent): QGraphicsView(parent), score1(0), score2(0) {
    // Set up the scene and view
    QGraphicsScene* scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(1000, 1000);
    scene->setSceneRect(0, 0, 800, 600);

    // Create and position the players
    player1 = new QGraphicsRectItem(0, 0, 50, 50);
    player2 = new QGraphicsRectItem(0, 0, 50, 50);
    player1->setPos(0, scene->height()-player1->rect().height());
    player2->setPos(scene->width()-player2->rect().width(), scene->height()-player2->rect().height());
    scene->addItem(player1);
    scene->addItem(player2);

  /*  // Create and position the ghost
    Ghost* ghost = new Ghost();
    ghost->setPos(rand()%(int)(scene->width()-ghost->rect().width()), rand()%(int)(scene->height()-ghost->rect().height()));
    scene->addItem(ghost);
    // Create and position the ghost
    Ghost* ghost1 = new Ghost();
    ghost1->setPos(rand()%(int)(scene->width()-ghost->rect().width()), rand()%(int)(scene->height()-ghost->rect().height()));
    scene->addItem(ghost1);
    // Create and position the ghost

*/
    for(int i = 0; i < 15; ++i) {
        Ghost* ghost = new Ghost();
        ghost->setPos(rand() % (int)(scene->width()-ghost->rect().width()), rand() % (int)(scene->height()-ghost->rect().height()));
        scene->addItem(ghost);
    }

    // Enable key events
    this->setFocusPolicy(Qt::StrongFocus);
    // Start a timer to check for collisions
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::checkCollisions);
    timer->start(50);


}
void Game::keyPressEvent(QKeyEvent *event) {
    int stepSize = 10; // change this value to increase/decrease speed

    switch (event->key()) {
    case Qt::Key_Up:
        player1->setPos(player1->x(), player1->y()-stepSize);
        break;
    case Qt::Key_Down:
        player1->setPos(player1->x(), player1->y()+stepSize);
        break;
    case Qt::Key_Left:
        player1->setPos(player1->x()-stepSize, player1->y());
        break;
    case Qt::Key_Right:
        player1->setPos(player1->x()+stepSize, player1->y());
        break;
    case Qt::Key_W:
        player2->setPos(player2->x(), player2->y()-stepSize);
        break;
    case Qt::Key_S:
        player2->setPos(player2->x(), player2->y()+stepSize);
        break;
    case Qt::Key_A:
        player2->setPos(player2->x()-stepSize, player2->y());
        break;
    case Qt::Key_D:
        player2->setPos(player2->x()+stepSize, player2->y());
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void Game::checkCollisions() {
    // Check for collisions between player1 and the ghosts
    QList<QGraphicsItem*> collidingItems1 = player1->collidingItems();
    for (QGraphicsItem* item : collidingItems1) {
        if (dynamic_cast<Ghost*>(item)) {
            scene()->removeItem(item);
            delete item;
            score1++;
            if (score1 == 5) {
                // player1 wins, you can show a message or something
            }
            return;
        }
    }
   QList<QGraphicsItem*> collidingItems2 = player2->collidingItems();
    for (QGraphicsItem* item : collidingItems2) {
        if (dynamic_cast<Ghost*>(item)) {
            scene()->removeItem(item);
            delete item;
            score2++;
            if (score2 == 5) {
                // player2 wins, you can show a message or something
            }
            return;
        }
    }
}

Ghost::Ghost(QGraphicsItem* parent): QObject(), QGraphicsEllipseItem(parent) {
    setRect(0, 0, 50, 50);

    // Move the ghost
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Ghost::move() {
    setPos(x()+rand()%3-1, y()+rand()%3-1);
}
