#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    welcomeView = new WelcomeView(this);
    loginView = new LoginView(this);
    adminView = new AdminView(this);
    userpanel= new UserPanel(this);
    stackedWidget->addWidget(welcomeView);
    stackedWidget->addWidget(loginView);
    stackedWidget->addWidget(adminView);
    stackedWidget->addWidget(userpanel);
    connect(welcomeView, &WelcomeView::adminRequested, this, &MainWindow::showAdminPanel);
    connect(welcomeView, &WelcomeView::userRequested, this, &MainWindow::showUserPanel);
    connect(loginView, &LoginView::loginSuccessful, this, &MainWindow::loginSuccessful);
}

MainWindow::~MainWindow() {
    // Cleanup if necessary
}

void MainWindow::showAdminPanel() {
    stackedWidget->setCurrentWidget(loginView);
}
void MainWindow::showUserPanel() {
    stackedWidget->setCurrentWidget(userpanel);
}
void MainWindow::loginSuccessful() {
    stackedWidget->setCurrentWidget(adminView);
}
