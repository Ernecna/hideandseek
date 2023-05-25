#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include "startpage.h"

class StartPage : public QDialog {
    Q_OBJECT
public:
    StartPage(QWidget* parent = nullptr) : QDialog(parent) {
        QVBoxLayout* layout = new QVBoxLayout();
        setLayout(layout);

        QLabel* nameLabel1 = new QLabel("Player 1 name:");
        QLabel* nameLabel2 = new QLabel("Player 2 name:");
        player1Edit = new QLineEdit();
        player2Edit = new QLineEdit();
        QPushButton* startButton = new QPushButton("Start Game");

        layout->addWidget(nameLabel1);
        layout->addWidget(player1Edit);
        layout->addWidget(nameLabel2);
        layout->addWidget(player2Edit);
        layout->addWidget(startButton);

        connect(startButton, &QPushButton::clicked, this, &StartPage::startGame);
    }

signals:
    void gameStart(const QString& player1Name, const QString& player2Name);

private slots:
    void startGame() {
        emit gameStart(player1Edit->text(), player2Edit->text());
        close();
    }

private:
    QLineEdit* player1Edit;
    QLineEdit* player2Edit;
};

StartPage::StartPage(QWidget *parent) : QDialog(parent) {
    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);

    QLabel* nameLabel1 = new QLabel("Player 1 name:");
    QLabel* nameLabel2 = new QLabel("Player 2 name:");
    player1Edit = new QLineEdit();
    player2Edit = new QLineEdit();
    QPushButton* startButton = new QPushButton("Start Game");

    layout->addWidget(nameLabel1);
    layout->addWidget(player1Edit);
    layout->addWidget(nameLabel2);
    layout->addWidget(player2Edit);
    layout->addWidget(startButton);

    connect(startButton, &QPushButton::clicked, this, &StartPage::startGame);
}

void StartPage::startGame() {
    emit gameStart(player1Edit->text(), player2Edit->text());
    close();
}
