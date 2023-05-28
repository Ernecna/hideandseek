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
    // Create the background label and set the background image
   QLabel* backgroundLabel1 = new QLabel(this);
    QPixmap background("C:/Users/MONSTER/Desktop/hideandseek/img/back3.jpg");  // Replace with your image path
    backgroundLabel1->setPixmap(background.scaled(this->size()));
    backgroundLabel1->setScaledContents(true);


    // Set custom font and size for player labels
    QFont playerLabelFont("Arial", 18, QFont::Bold);

    // Create labels
    QLabel* player1Label = new QLabel("<b>Player 1 name</b>", this);
    player1Label->setFont(playerLabelFont);
    player1Label->setStyleSheet("color: white;");

    QLabel* player2Label = new QLabel("<b>Player 2 name</b>", this);
    player2Label->setFont(playerLabelFont);
    player2Label->setStyleSheet("color: white;");
    //
    //
    // Set custom font and size for the title
    QFont titleFont("Arial", 24, QFont::ExtraBold);

    // Create the title label
    QLabel* titleLabel = new QLabel("Hide and Seek Game \nCENG206 Project-2", this);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: white;");
    titleLabel->setAlignment(Qt::AlignCenter);


    // size settings
    resize(450, 300);

    // Create line edits
    player1Name = new QLineEdit(this);
    player2Name = new QLineEdit(this);

    // Create start button
    startButton = new QPushButton("Start", this);
    startButton->setFont(playerLabelFont);

    // Create horizontal layouts
    QHBoxLayout* player1Layout = new QHBoxLayout;
    player1Layout->addWidget(player1Label);
    player1Layout->addWidget(player1Name);

    QHBoxLayout* player2Layout = new QHBoxLayout;
    player2Layout->addWidget(player2Label);
    player2Layout->addWidget(player2Name);

    // Create main layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(titleLabel); // Add the title label to the layout
    layout->setAlignment(titleLabel, Qt::AlignCenter); // Align the title label to the center
    layout->setSpacing(20);  // add space between widgets
    layout->setContentsMargins(10, 10, 10, 10);  // add margins around the layout
    layout->addLayout(player1Layout);
    layout->addLayout(player2Layout);
    layout->addWidget(startButton);

    // central widget
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    // Set the background label as the central widget
    backgroundLabel1->setLayout(layout);
    setCentralWidget(backgroundLabel1);
    backgroundLabel1->setAlignment(Qt::AlignCenter);  // Image alignment in the label
    backgroundLabel1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // Resize policy of the label

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
