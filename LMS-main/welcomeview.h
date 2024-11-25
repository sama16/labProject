#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class WelcomeView : public QWidget {
    Q_OBJECT

public:
    explicit WelcomeView(QWidget *parent = nullptr);


signals:
    void adminRequested();
    void userRequested();

private:
    void setupUI();

};

#endif // WELCOMEVIEW_H
