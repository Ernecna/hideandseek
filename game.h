#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QBrush>
#include <QSet>

class Game: public QGraphicsView {
public:
    Game(const QString& player1Name, const QString& player2Name, QWidget* parent = 0);
    ~Game();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void spawnGhost();
    void checkCollisions();
    void resetGame(); // reset game function declaration
    void movePlayers(); // new function to move players


    QGraphicsEllipseItem* player1;
    QGraphicsEllipseItem* player2;
    QString player1Name;
    QString player2Name;
    QGraphicsTextItem* score1Text;
    QGraphicsTextItem* score2Text;
    QGraphicsTextItem* score3Text;

private:
    int sceneWidth;
    int sceneHeight;
    QSet<int> pressedKeys; // new set to hold pressed keys
};

#endif // GAME_H
