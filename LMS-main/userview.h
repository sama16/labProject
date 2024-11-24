#ifndef USERVIEW_H
#define USERVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QString>
#include <vector>

class UserView : public QWidget {
    Q_OBJECT

public:
    explicit UserView(QWidget *parent = nullptr);
    ~UserView();
    struct User {
        QString username;
        QVector<QString> borrowedBooks;
        int lateReturnCount = 0;
        bool isBlacklisted = false;
    };
private slots:
    void searchBooks();           // Slot to handle book search
    void borrowBook();            // Slot to borrow selected book
    void viewHistory();           // Slot to view borrowing history
    void registerForSeminar();    // Slot to register for a seminar
    void searchSeminars();
    void provideFeedbackForSeminar();



private:
    void setupUI();               // Setup the UI components
    void loadBooks();             // Load books into the availableBooks list
    void loadUserData();          // Load user data (borrowing history)
    void loadSeminars();          // Load seminar list


    QLineEdit *searchInput;       // Input field for book search
    QListWidget *listView;        // List to display books or seminars
    QPushButton *borrowButton;    // Button to borrow selected book
    QPushButton *viewHistoryButton; // Button to view borrowing history
    QLineEdit *searchInputSeminar;
    QListWidget *listViewSeminar;
    QPushButton *registerButton;  // Button to register for seminar
    QPushButton *feedbackButton;

    std::vector<QString> availableBooks;   // List of available books
    std::vector<QString> borrowedBooks;    // User's borrowed books
    std::vector<QString> seminarList;      // List of seminars
    std::vector<QString> borrowingHistory; // User's borrowing history
 const int MAX_BORROW_LIMIT = 3;
};

#endif // USERVIEW_H
