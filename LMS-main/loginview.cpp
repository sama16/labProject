#include "loginview.h"
#include "adminList.h"
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

LoginView::LoginView(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("Admin Login", this);
    layout->addWidget(label);

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");
    layout->addWidget(usernameInput);

    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Password");
    passwordInput->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordInput);

    loginButton = new QPushButton("Login", this);
    layout->addWidget(loginButton);

    
    connect(loginButton, &QPushButton::clicked, this, &LoginView::attemptLogin);
}
bool login=false;
void LoginView::attemptLogin() {
  
    if (usernameInput->text() != "" && passwordInput->text() != ""){
    for(int i=0;i<4;i++){
        if (usernameInput->text() == usernames[i] && passwordInput->text() == passwords[i]){
        emit loginSuccessful(); 
            login=true;
        }
    }
    if(!login){
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
    }
    else
     QMessageBox::warning(this, "Login Failed", "can not be empty");

}

