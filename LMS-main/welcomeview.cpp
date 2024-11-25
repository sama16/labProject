#include "welcomeview.h"
#include "adminview.h"
WelcomeView::WelcomeView(QWidget *parent) : QWidget(parent) {
    setupUI();
}

void WelcomeView::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Welcoming message
    QLabel *welcomeLabel = new QLabel("Welcome to the Public Library Management System!", this);
    welcomeLabel->setAlignment(Qt::AlignCenter); // Center the label

    QPushButton *adminButton = new QPushButton("Go to Admin Panel", this);
    connect(adminButton, &QPushButton::clicked, this, &WelcomeView::adminRequested);

    QPushButton *userButton = new QPushButton("Go to user Panel", this);
    connect(userButton, &QPushButton::clicked, this, &WelcomeView::userRequested);

    layout->addWidget(welcomeLabel);
    layout->addWidget(adminButton);
    layout->addWidget(userButton);
}

