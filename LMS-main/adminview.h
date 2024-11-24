#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QLineEdit>

class AdminView : public QWidget {
    Q_OBJECT

public:
    explicit AdminView(QWidget *parent = nullptr);
    ~AdminView();

private:
    void setupUI();
    void loadBooks();
    void saveBooks();
    void loadUsers();
    void saveUsers();
    void loadSeminars();
    void saveSeminars();


    // Book management
    QLineEdit *bookTitleInput;
    QLineEdit *bookAuthorInput;
    QStringList bookList; // Store book information

    // User management
    QLineEdit *userInput;
    QStringList userList; // Store usernames
    //seminar management
    QLineEdit *seminarTitleInput;
    QLineEdit *seminarDateInput;
      QStringList seminarList;


    // Book functions
    void addBook();
    void editBook();
    void deleteBook();

    // User functions
    void addUser();
    void deleteUser();
    void manageUsers();

    //seminar finction
    void addSeminar();
    void editSeminar();
    void deleteSeminar();
};

#endif // ADMINVIEW_H
