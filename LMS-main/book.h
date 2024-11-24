#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
public:
    QString title;
    QString author;
    QString category;
    bool isAvailable;

    Book(const QString &t, const QString &a, const QString &c)
        : title(t), author(a), category(c), isAvailable(true) {}
};

#endif // BOOK_H
