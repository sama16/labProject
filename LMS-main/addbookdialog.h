#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class AddBookDialog : public QDialog {
    Q_OBJECT

public:
    AddBookDialog(QWidget *parent = nullptr);
    QString getBookTitle();
    QString getBookAuthor();
    QString getBookCategory();

private:
    QLineEdit *titleEdit;
    QLineEdit *authorEdit;
    QLineEdit *categoryEdit;
};

#endif // ADDBOOKDIALOG_H
