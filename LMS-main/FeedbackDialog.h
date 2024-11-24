#ifndef FEEDBACKDIALOG_H
#define FEEDBACKDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>

class FeedbackDialog : public QDialog {
    Q_OBJECT

public:
    explicit FeedbackDialog(QWidget *parent = nullptr);

    QString getFeedback() const;
    int getRating() const;

private:
    QTextEdit *feedbackInput;
    QComboBox *ratingComboBox;
    QPushButton *submitButton;

    void setupUI();
};

#endif // FEEDBACKDIALOG_H
