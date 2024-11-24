#ifndef USERPANEL_H
#define USERPANEL_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class UserPanel : public QWidget {
    Q_OBJECT

public:
    explicit UserPanel(QWidget *parent = nullptr);

signals:
    void loginRequested(QString username, QString password);
    void registerRequested(QString username, QString password, QString confirmPassword);

private slots:
    void handleButtonClicked();

private:
    QComboBox *comboBox;
    QLineEdit *usernameEdit, *passwordEdit, *confirmPasswordEdit;
    QPushButton *button;
    QLabel *usernameLabel, *passwordLabel, *confirmPasswordLabel;
};

#endif // USERPANEL_H
