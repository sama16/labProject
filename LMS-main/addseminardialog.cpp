#include "addseminardialog.h"

AddSeminarDialog::AddSeminarDialog(QWidget *parent) : QDialog(parent) {
    titleEdit = new QLineEdit(this);
    speakerEdit = new QLineEdit(this);
    dateEdit = new QDateEdit(this);
    descriptionEdit = new QLineEdit(this);

    QPushButton *addButton = new QPushButton("Add", this);
    connect(addButton, &QPushButton::clicked, this, &AddSeminarDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleEdit);
    layout->addWidget(speakerEdit);
    layout->addWidget(dateEdit);
    layout->addWidget(descriptionEdit);
    layout->addWidget(addButton);
}

QString AddSeminarDialog::getSeminarTitle() {
    return titleEdit->text();
}

QString AddSeminarDialog::getSpeaker() {
    return speakerEdit->text();
}

QDate AddSeminarDialog::getDate() {
    return dateEdit->date();
}

QString AddSeminarDialog::getDescription() {
    return descriptionEdit->text();
}
