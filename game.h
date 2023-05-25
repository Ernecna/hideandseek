#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QBrush>

class Game: public QGraphicsView {
public:
    Game(const QString& player1Name, const QString& player2Name, QWidget* parent = 0);
      ~Game();
    void keyPressEvent(QKeyEvent *event);
    void spawnGhost();
    void checkCollisions();
    void resetGame(); // reset game function declaration



    QGraphicsEllipseItem* player1;
    QGraphicsEllipseItem* player2;
    QString player1Name;
    QString player2Name;

    int score1;
    int score2;
private:


    int sceneWidth;
    int sceneHeight;

};


#endif // GAME_H
