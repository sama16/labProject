#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "adminview.h"
#include "userview.h"
#include "welcomeview.h"
#include "loginview.h"
#include"userpanel.h"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAdminPanel();
    void loginSuccessful();
    void showUserPanel();
    void goBackToWelcome();
    void goBack();


private:
    QStackedWidget *stackedWidget;
    WelcomeView *welcomeView;
    UserPanel *userpanel;
    LoginView *loginView;
    AdminView *adminView;
    UserView *userview;
;


};

#endif // MAINWINDOW_H
