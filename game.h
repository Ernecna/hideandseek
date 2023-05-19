#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Game: public QGraphicsView {
public:
    Game(QWidget* parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
    void spawnGhost();
    void checkCollisions();

    QGraphicsRectItem* player1;
    QGraphicsRectItem* player2;

    int score1;
    int score2;
};

class Ghost: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Ghost(QGraphicsItem* parent=nullptr);
public slots:
    void move();
};

#endif // GAME_H
