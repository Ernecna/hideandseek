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
      ~Game();
    void keyPressEvent(QKeyEvent *event);
    void spawnGhost();
    void checkCollisions();
    void resetGame(); // reset game function declaration



    QGraphicsEllipseItem* player1;
    QGraphicsEllipseItem* player2;

    int score1;
    int score2;
private:


    int sceneWidth;
    int sceneHeight;

};


#endif // GAME_H
