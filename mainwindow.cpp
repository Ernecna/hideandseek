#include "MainWindow.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPalette>
#include<QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), game(nullptr)
{
    // Set background color to dark gray
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::darkGray);
    this->setPalette(palette);
    this->setAutoFillBackground(true);

    // Set custom font
    QFont font("Arial", 14, QFont::Bold);

    // Create labels
    QLabel* player1Label = new QLabel("<b>Player 1 name</b>", this);
    player1Label->setFont(font);
    player1Label->setStyleSheet("color: white;");

    QLabel* player2Label = new QLabel("<b>Player 2 name</b>", this);
    player2Label->setFont(font);
    player2Label->setStyleSheet("color: white;");

    // size settings
    resize(450,300);

    // Create line edits
    player1Name = new QLineEdit(this);
    player2Name = new QLineEdit(this);

    // Create start button
    startButton = new QPushButton("Start", this);
    startButton->setFont(font);

    // Create horizontal layouts
    QHBoxLayout* player1Layout = new QHBoxLayout;
    player1Layout->addWidget(player1Label);
    player1Layout->addWidget(player1Name);

    QHBoxLayout* player2Layout = new QHBoxLayout;
    player2Layout->addWidget(player2Label);
    player2Layout->addWidget(player2Name);

    // Create main layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSpacing(20);  // add space between widgets
    layout->setContentsMargins(10, 10, 10, 10);  // add margins around the layout
    layout->addLayout(player1Layout);
    layout->addLayout(player2Layout);
    layout->addWidget(startButton);

    // central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // connect
    connect(startButton, &QPushButton::clicked, this, &MainWindow::startGame);
}

MainWindow::~MainWindow()
{
    delete game;  // will also delete the children player1Name, player2Name, and startButton
}

void MainWindow::startGame()
{
    game = new Game(player1Name->text(), player2Name->text());
    game->show();
    this->hide();
}
