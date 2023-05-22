#include "game.h"
#include "qapplication.h"
#include "ghost.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QMessageBox>


Game::Game(QWidget* parent): QGraphicsView(parent), score1(0), score2(0) {
    // Set up the scene and view
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::black);
    setScene(scene);
    setFixedSize(1000, 1000);
    scene->setSceneRect(0, 0, 1000, 1000);

    // Create and position the players
    player1 = new QGraphicsEllipseItem(0, 0, 100, 100);
    player2 = new QGraphicsEllipseItem(0, 0, 100, 100);
    player1->setPos(0, scene->height()-player1->rect().height());
    player2->setPos(scene->width()-player2->rect().width(), scene->height()-player2->rect().height());
    scene->addItem(player1);
    scene->addItem(player2);
    //PLAYER COLORS
    player1->setBrush(QBrush(Qt::yellow));
    player2->setBrush(QBrush(Qt::red));

    // Add text to the players
    QGraphicsTextItem* p1Text = new QGraphicsTextItem("P1", player1);
    QGraphicsTextItem* p2Text = new QGraphicsTextItem("P2", player2);

    // TEXT COLOR
    p1Text->setDefaultTextColor(Qt::white);
    p2Text->setDefaultTextColor(Qt::white);

    // Adjust the positions of the text to be at the center of the players
    QRectF p1Rect = p1Text->boundingRect();
    QRectF p2Rect = p2Text->boundingRect();
    p1Text->setPos(player1->rect().width()/2 - p1Rect.width()/2, player1->rect().height()/2 - p1Rect.height()/2);
    p2Text->setPos(player2->rect().width()/2 - p2Rect.width()/2, player2->rect().height()/2 - p2Rect.height()/2);

  /*  // Create and position the ghost
    Ghost* ghost = new Ghost();
    ghost->setPos(rand()%(int)(scene->width()-ghost->rect().width()), rand()%(int)(scene->height()-ghost->rect().height()));
    scene->addItem(ghost);
    // Create and position the ghost
    Ghost* ghost1 = new Ghost();
    ghost1->setPos(rand()%(int)(scene->width()-ghost->rect().width()), rand()%(int)(scene->height()-ghost->rect().height()));
    scene->addItem(ghost1);

*/
    for(int i = 0; i < 21; ++i) {
        Ghost* ghost = new Ghost(scene->height(),scene->width());
        ghost->setBrush(Qt::black);

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
// MOVEMENT İS MANAGE BY THİS FUNCTİON
void Game::keyPressEvent(QKeyEvent *event) {
    int stepSize = 10; // change this value to increase/decrease speed
    qreal newX, newY;

    switch (event->key()) {
    case Qt::Key_Up:
        newY = player1->y() - stepSize;
        if (newY >= 0) {
            player1->setPos(player1->x(), newY);
            qDebug() << "Player1 moved";
        }
        break;
    case Qt::Key_Down:
        newY = player1->y() + stepSize;
        if (newY <= scene()->height() - player1->rect().height()) {
            player1->setPos(player1->x(), newY);
            qDebug() << "Player1 moved";
        }
        break;
    case Qt::Key_Left:
        newX = player1->x() - stepSize;
        if (newX >= 0) {
            player1->setPos(newX, player1->y());
            qDebug() << "Player1 moved";
        }
        break;
    case Qt::Key_Right:
        newX = player1->x() + stepSize;
        if (newX <= scene()->width() - player1->rect().width()) {
            player1->setPos(newX, player1->y());
            qDebug() << "Player1 moved";
        }
        break;
    case Qt::Key_W:
        newY = player2->y() - stepSize;
        if (newY >= 0) {
            player2->setPos(player2->x(), newY);
            qDebug() << "Player2 moved";
        }
        break;
    case Qt::Key_S:
        newY = player2->y() + stepSize;
        if (newY <= scene()->height() - player2->rect().height()) {
            player2->setPos(player2->x(), newY);
            qDebug() << "Player2 moved";
        }
        break;
    case Qt::Key_A:
        newX = player2->x() - stepSize;
        if (newX >= 0) {
            player2->setPos(newX, player2->y());
            qDebug() << "Player2 moved";
        }
        break;
    case Qt::Key_D:
        newX = player2->x() + stepSize;
        if (newX <= scene()->width() - player2->rect().width()) {
            player2->setPos(newX, player2->y());
            qDebug() << "Player2 moved";
        }
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
// HIT TO FINIS
int ghostsHit = 0;
// RESETGAME FUNCTİON TO START NEW GAME

void Game::resetGame() {
    // Reset scores
    score1 = 0;
    score2 = 0;
    ghostsHit=0;

    // Reset player positions
    player1->setPos(0, scene()->height()-player1->rect().height());
    player2->setPos(scene()->width()-player2->rect().width(), scene()->height()-player2->rect().height());

    // Remove all ghosts
    for (QGraphicsItem* item : scene()->items()) {
        if (Ghost* ghost = dynamic_cast<Ghost*>(item)) {
            scene()->removeItem(ghost);
            delete ghost;
        }
    }

    // Spawn new ghosts
    for(int i = 0; i < 21; ++i) {
        Ghost* ghost = new Ghost(900,700);
        ghost->setPos(rand() % (int)(scene()->width()-ghost->rect().width()), rand() % (int)(scene()->height()-ghost->rect().height()));
        scene()->addItem(ghost);
    }
}
// CHECK COLLİSONS PART

void Game::checkCollisions() {
    // Check for collisions between player1 and the ghosts
    QList<QGraphicsItem*> collidingItems1 = player1->collidingItems();
    for (QGraphicsItem* item : collidingItems1) {
        Ghost* ghost = dynamic_cast<Ghost*>(item);
        if (ghost) {
            if(!ghost->getHasHitPlayer()) {
                ghost->setHasHitPlayer(true);
                ghost->setBrush(Qt::yellow);
                score1++;
                ghostsHit++;
            }
        }
    }

    // Check for collisions between player2 and the ghosts
    QList<QGraphicsItem*> collidingItems2 = player2->collidingItems();
    for (QGraphicsItem* item : collidingItems2) {
        Ghost* ghost = dynamic_cast<Ghost*>(item);
        if (ghost) {
            if(!ghost->getHasHitPlayer()) {
                ghost->setHasHitPlayer(true);
                ghost->setBrush(Qt::red);
                score2++;
                ghostsHit++;
            }
        }
    }
    // End game when all ghosts have been hit
    if (ghostsHit == 21) {
        QMessageBox msgBox;
        QString winner = score1 > score2 ? "Player 1" : "Player 2";
        msgBox.setText(winner + " wins!");
        msgBox.setInformativeText("Do you want to play again?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        if (ret == QMessageBox::Yes) {
            resetGame();
        } else {
            QApplication::quit();
        }
    }
}
// ekran boyutlarını ayarlıcaz
// player1 ekrandan dışarı cıkarsa except handling
// yuvarlaklar dışarı kaçmıcak onu engellememiz lazım
// arayüz tasarlanmalı giriş ekranı
//rapor kaldı
//yaparken birkaç ss almanın faydası olacaktır.






