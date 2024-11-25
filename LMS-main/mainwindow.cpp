#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    welcomeView = new WelcomeView(this);
    loginView = new LoginView(this);
    adminView = new AdminView(this);
    userpanel= new UserPanel(this);
    userview=new UserView(this);


    stackedWidget->addWidget(welcomeView);
    stackedWidget->addWidget(loginView);
    stackedWidget->addWidget(adminView);
    stackedWidget->addWidget(userpanel);
    stackedWidget->addWidget(userview);

    connect(welcomeView, &WelcomeView::adminRequested, this, &MainWindow::showAdminPanel);
    connect(welcomeView, &WelcomeView::userRequested, this, &MainWindow::showUserPanel);
    connect(loginView, &LoginView::loginSuccessful, this, &MainWindow::loginSuccessful);
    connect(adminView, &AdminView::goBackToWelcome, this, &MainWindow::goBackToWelcome);  // Connect the signal
    connect(userview, &UserView::goBack, this, &MainWindow::goBack);  // Connect the signal



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
void MainWindow::goBackToWelcome() {
    stackedWidget->setCurrentWidget(welcomeView);  // Show WelcomeView when back button is clicked
}
void MainWindow::goBack() {
    stackedWidget->setCurrentWidget(welcomeView);  // Show WelcomeView when back button is clicked
}

