#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>

class User {
public:
    QString username;
    QString password;
    QList<QString> borrowingHistory;

    User(const QString &user, const QString &pass) : username(user), password(pass) {}
};

#endif // USER_H
