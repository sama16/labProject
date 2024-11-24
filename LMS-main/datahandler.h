#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "book.h"
#include "user.h"
#include "seminar.h"
#include <QList>
#include <QString>

class DataHandler {
public:
    QList<Book> books;
    QList<User> users;
    QList<Seminar> seminars;

    void loadBooks(const QString &filename);
    void saveBooks(const QString &filename);
    void loadUsers(const QString &filename);
    void saveUsers(const QString &filename);
    void loadSeminars(const QString &filename);
    void saveSeminars(const QString &filename);
};

#endif // DATAHANDLER_H
