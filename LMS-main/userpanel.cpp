#include "userpanel.h"
#include "userview.h"
#include <QUuid> // For generating unique IDs

UserPanel::UserPanel(QWidget *parent) : QWidget(parent) {
    // Create UI elements
    comboBox = new QComboBox(this);
    comboBox->addItem("Login");
    comboBox->addItem("Register");

    usernameLabel = new QLabel("Name:", this);
    usernameEdit = new QLineEdit(this);

    button = new QPushButton("Submit", this);

    // Create layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout;

    // Add widgets to layouts
    inputLayout->addWidget(usernameLabel);
    inputLayout->addWidget(usernameEdit);

    mainLayout->addWidget(comboBox);
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(button);

    // Connect the button's clicked signal to the handleButtonClicked slot
    connect(button, &QPushButton::clicked, this, &UserPanel::handleButtonClicked);
}

void UserPanel::handleButtonClicked() {
    QString username = usernameEdit->text().trimmed();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username.");
        return;
    }

    if (comboBox->currentIndex() == 0) { // Login
        if (loginUser(username)) {
            UserView *userView = new UserView();
            userView->setWindowTitle("User View");
            userView->showFullScreen();
            this->hide();
        } else {
            QMessageBox::warning(this, "Login Failed", "Name not found. Please register first.");
        }
    } else { // Register
        if (registerUser(username)) {
            QMessageBox::information(this, "Registration Successful", "You can now log in.");
        } else {
            QMessageBox::warning(this, "Registration Failed", "Name already exists.");
        }
    }
}

bool UserPanel::registerUser(const QString &username) {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/users.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to access user data.");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");
        if (!userDetails.isEmpty() && userDetails[0] == username) { // Check if username already exists
            file.close();
            return false;
        }
    }

    // Generate a unique user ID
    QString userId = QUuid::createUuid().toString(QUuid::WithoutBraces);

    // Add user details to the main file
    QTextStream out(&file);
    file.seek(file.size()); // Move to the end of the file
    out << username << ",{},{}\n"; // Format: username,borrowingHistory,seminarParticipation
    file.close();

    // Store the user ID in a separate file
    QFile idFile("C:/Users/hp/Desktop/labProject/LMS-main/randomID.txt");
    if (!idFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to store user ID.");
        return false;
    }

    QTextStream idOut(&idFile);
    idOut << username << "," << userId << "\n"; // Format: username,userID
    idFile.close();

    return true;
}

bool UserPanel::loginUser(const QString &username) {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to access user data.");
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList userDetails = line.split(",");
        if (!userDetails.isEmpty() && userDetails[0] == username) { // Check if username matches
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
