#include "adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent) : QDialog(parent) {
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &AddUserDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordEdit);
    layout->addWidget(addButton);
}

QString AddUserDialog::getUsername() {
    return usernameEdit->text();
}

QString AddUserDialog::getPassword() {
    return passwordEdit->text();
}
