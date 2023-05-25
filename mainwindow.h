#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "game.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void startGame();

private:
    QPushButton* startButton;
    QLineEdit* player1Name;
    QLineEdit* player2Name;
    Game* game;
};

#endif // MAINWINDOW_H
