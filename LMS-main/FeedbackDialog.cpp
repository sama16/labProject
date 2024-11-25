#include "FeedbackDialog.h"
#include <QVBoxLayout>
#include <QLabel>

FeedbackDialog::FeedbackDialog(QWidget *parent)
    : QDialog(parent),
    feedbackInput(new QTextEdit(this)),
    ratingComboBox(new QComboBox(this)),
    submitButton(new QPushButton("Submit", this)) {

    setupUI();
}

void FeedbackDialog::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *feedbackLabel = new QLabel("Please provide your feedback:", this);
    layout->addWidget(feedbackLabel);

    layout->addWidget(feedbackInput);

    QLabel *ratingLabel = new QLabel("Rate the seminar (1 to 5):", this);
    layout->addWidget(ratingLabel);

    for (int i = 1; i <= 5; ++i) {
        ratingComboBox->addItem(QString::number(i));
    }
    layout->addWidget(ratingComboBox);

    layout->addWidget(submitButton);
    connect(submitButton, &QPushButton::clicked, this, &QDialog::accept); 
}

QString FeedbackDialog::getFeedback() const {
    return feedbackInput->toPlainText(); 
}

int FeedbackDialog::getRating() const {
    return ratingComboBox->currentIndex() + 1; 
}
