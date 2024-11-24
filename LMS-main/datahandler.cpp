#include "datahandler.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

void DataHandler::loadBooks(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 3) {
                books.append(Book(fields[0], fields[1], fields[2]));
            }
        }
        file.close();
    }
}

void DataHandler::saveBooks(const QString &filename) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (const Book &book : books) {
            out << book.title << "," << book.author << "," << book.category << "\n";
        }
        file.close();
    }
}

// Similar implementations for loadUsers, saveUsers, loadSeminars, and saveSeminars
