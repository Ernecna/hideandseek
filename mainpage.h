#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>

class StartPage : public QDialog {
    Q_OBJECT

public:
    explicit StartPage(QWidget* parent = nullptr);

signals:
    void gameStart(const QString& player1Name, const QString& player2Name);

private slots:
    void startGame();

private:
    QLineEdit* player1Edit;
    QLineEdit* player2Edit;
};

#endif // STARTPAGE_H
