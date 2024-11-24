#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "adminview.h"
#include"userview.h"
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

private:
    QStackedWidget *stackedWidget;
    AdminView *adminView;
    UserPanel *userpanel;
    WelcomeView *welcomeView;
    LoginView *loginView;

};

#endif // MAINWINDOW_H
