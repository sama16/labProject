#ifndef ADDEMINARDIALOG_H
#define ADDEMINARDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>

class AddSeminarDialog : public QDialog {
    Q_OBJECT

public:
    AddSeminarDialog(QWidget *parent = nullptr);
    QString getSeminarTitle();
    QString getSpeaker();
    QDate getDate();
    QString getDescription();

private:
    QLineEdit *titleEdit;
    QLineEdit *speakerEdit;
    QDateEdit *dateEdit;
    QLineEdit *descriptionEdit;
};

#endif // ADDEMINARDIALOG_H
