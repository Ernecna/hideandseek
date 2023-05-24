#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class StartPage: public QDialog {
    Q_OBJECT
public:
    StartPage(QWidget* parent=nullptr);
    QString getPlayer1Name() const;
    QString getPlayer2Name() const;

private:
    QLineEdit* player1NameField;
    QLineEdit* player2NameField;
};

#endif // STARTPAGE_H
