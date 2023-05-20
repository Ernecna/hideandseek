#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QBrush>

class Game: public QGraphicsView {
public:
    Game(QWidget* parent=nullptr);
    void keyPressEvent(QKeyEvent *event);
    void spawnGhost();
    void checkCollisions();
    void resetGame(); // reset game function declaration


    QGraphicsRectItem* player1;
    QGraphicsRectItem* player2;

    int score1;
    int score2;
};


#endif // GAME_H
