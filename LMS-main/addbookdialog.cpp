#include "addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent) : QDialog(parent) {
    titleEdit = new QLineEdit(this);
    authorEdit = new QLineEdit(this);
    categoryEdit = new QLineEdit(this);

    QPushButton *addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &AddBookDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleEdit);
    layout->addWidget(authorEdit);
    layout->addWidget(categoryEdit);
    layout->addWidget(addButton);
}

QString AddBookDialog::getBookTitle() {
    return titleEdit->text();
}

QString AddBookDialog::getBookAuthor() {
    return authorEdit->text();
}

QString AddBookDialog::getBookCategory() {
    return categoryEdit->text();
}
