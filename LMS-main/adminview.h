#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QLineEdit>
#include <QListWidget>

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


   
    QLineEdit *bookTitleInput;
    QLineEdit *bookAuthorInput;
    QStringList bookList; 

    
    QLineEdit *userInput;
    QStringList userList; 
     QListWidget *listView;
    
    QLineEdit *seminarTitleInput;
    QLineEdit *seminarDateInput;
      QStringList seminarList;


    
    void addBook();
    void editBook();
    void deleteBook();

    void addUser();
    void deleteUser();
    void manageUsers();

    void addSeminar();
    void editSeminar();
    void deleteSeminar();
};

#endif // ADMINVIEW_H
