#include "userpanel.h"
#include "userview.h"
UserPanel::UserPanel(QWidget *parent) : QWidget(parent) {
    // Create UI elements
    comboBox = new QComboBox(this);
    comboBox->addItem("Login");
    comboBox->addItem("Register");

    usernameLabel = new QLabel("Username:", this);
    usernameEdit = new QLineEdit(this);

    passwordLabel = new QLabel("Password:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    confirmPasswordLabel = new QLabel("Confirm Password:", this);
    confirmPasswordEdit = new QLineEdit(this);
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordEdit->setVisible(false);

    button = new QPushButton("Submit", this);

    // Create layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout;

    // Add widgets to layouts
    inputLayout->addWidget(usernameLabel);
    inputLayout->addWidget(usernameEdit);
    inputLayout->addWidget(passwordLabel);
    inputLayout->addWidget(passwordEdit);
    inputLayout->addWidget(confirmPasswordLabel);
    inputLayout->addWidget(confirmPasswordEdit);

    mainLayout->addWidget(comboBox);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(button);

    // Connect the button's clicked signal to the handleButtonClicked slot
    connect(button, &QPushButton::clicked, this, &UserPanel::handleButtonClicked);


    // Connect the comboBox's currentIndexChanged signal to a slot to show/hide confirm password field
    connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index) {
        confirmPasswordLabel->setVisible(index == 1);
        confirmPasswordEdit->setVisible(index == 1);
    });
}

void UserPanel::handleButtonClicked() {
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();

    if (comboBox->currentIndex() == 0) { // Login
        emit loginRequested(username, password);
        UserView *userView = new UserView();
        // Set UserView to full screen
        userView->setWindowTitle("User View");
        userView->showFullScreen();
        this->hide();
    } else { // Register
        emit registerRequested(username, password, confirmPassword);
    }

}
