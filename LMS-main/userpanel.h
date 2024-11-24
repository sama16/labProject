#ifndef USERPANEL_H
#define USERPANEL_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class UserPanel : public QWidget {
    Q_OBJECT

public:
    explicit UserPanel(QWidget *parent = nullptr);

private:
    QComboBox *comboBox;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QPushButton *button;

    void handleButtonClicked();
    bool registerUser(const QString &username);
    bool loginUser(const QString &username);

signals:
    void loginRequested(const QString &username);
    void registerRequested(const QString &username);
};

#endif // USERPANEL_H
