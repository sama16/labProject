#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class AddUserDialog : public QDialog {
    Q_OBJECT

public:
    AddUserDialog(QWidget *parent = nullptr);
    QString getUsername();
    QString getPassword();

private:
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
};

#endif // ADDUSERDIALOG_H
