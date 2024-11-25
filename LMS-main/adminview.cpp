
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <algorithm> // For std::remove and std::find
#include "welcomeview.h"
#include <QListWidget>
#include <QUuid>

class AdminView : public QWidget {
    Q_OBJECT

public:
    AdminView(QWidget *parent = nullptr);
    ~AdminView();

signals:
    void goBackToWelcome();

private:
    void setupUI();
    void loadBooks();  // Load books when initializing
    void saveBooks();  // Save books when destroying
    void loadUsers();  // Load users when initializing
    void saveUsers();  // Save users when destroying
    void loadSeminars(); // Load seminars
    void saveSeminars(); // Save seminars

    // Methods for managing books
    void addBook();
    void editBook();
    void deleteBook();

    // Methods for managing users
    void addUser();
    void deleteUser();
    void viewBorrowingHistory();
    void viewFeedback();

    // Methods for managing seminars
    void addSeminar();
    void editSeminar();
    void deleteSeminar();

    std::vector<QString> bookList;    // List of books
    std::vector<QString> userList;    // List of users
    std::vector<QString> seminarList; // List of seminars

    QLineEdit *bookTitleInput;
    QLineEdit *bookAuthorInput;
    QLineEdit *bookCategoryInput;
    QLineEdit *userInput;
    QLineEdit *seminarTitleInput;
    QLineEdit *seminarDateInput;
    QListWidget *listView; // Initialized list view widget
    QListWidget *listViewFeedback;
    WelcomeView *welcomeView; // For handling the go-back functionality
};

AdminView::AdminView(QWidget *parent) : QWidget(parent), welcomeView(nullptr) {
    setupUI();
    loadBooks();  // Load books when initializing
    loadUsers();  // Load users when initializing
    loadSeminars();
}

AdminView::~AdminView() {
    saveBooks();  // Save books when destroying
    saveUsers();  // Save users when destroying
    saveSeminars();
}

void AdminView::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *back = new QPushButton("Go Back", this);
    connect(back, &QPushButton::clicked, this, &AdminView::goBackToWelcome);
    layout->addWidget(back);

    // Book management
    QLabel *bookLabel = new QLabel("Manage Books", this);
    layout->addWidget(bookLabel);

    bookTitleInput = new QLineEdit(this);
    bookTitleInput->setPlaceholderText("Enter Book Title");
    layout->addWidget(bookTitleInput);

    bookAuthorInput = new QLineEdit(this);
    bookAuthorInput->setPlaceholderText("Enter Author Name");
    layout->addWidget(bookAuthorInput);

    bookCategoryInput = new QLineEdit(this);
    bookCategoryInput->setPlaceholderText("Enter Book category");
    layout->addWidget(bookCategoryInput);

    // Buttons for adding, editing, and deleting books
    QPushButton *addButton = new QPushButton("Add Book", this);
    connect(addButton, &QPushButton::clicked, this, &AdminView::addBook);
    layout->addWidget(addButton);

    QPushButton *editButton = new QPushButton("Edit Book", this);
    connect(editButton, &QPushButton::clicked, this, &AdminView::editBook);
    layout->addWidget(editButton);

    QPushButton *deleteButton = new QPushButton("Delete Book", this);
    connect(deleteButton, &QPushButton::clicked, this, &AdminView::deleteBook);
    layout->addWidget(deleteButton);

    // User management
    QLabel *userLabel = new QLabel("Manage Users", this);
    layout->addWidget(userLabel);

    userInput = new QLineEdit(this);
    userInput->setPlaceholderText("Enter Username");
    layout->addWidget(userInput);

    QPushButton *addUserButton = new QPushButton("Add User", this);
    connect(addUserButton, &QPushButton::clicked, this, &AdminView::addUser);
    layout->addWidget(addUserButton);

    QPushButton *deleteUserButton = new QPushButton("Delete User", this);
    connect(deleteUserButton, &QPushButton::clicked, this, &AdminView::deleteUser);
    layout->addWidget(deleteUserButton);

    // List view for feedback and history
    listView = new QListWidget(this);
    layout->addWidget(listView);

    QPushButton *viewBookHistory = new QPushButton("View Borrowing History", this);
    connect(viewBookHistory, &QPushButton::clicked, this, &AdminView::viewBorrowingHistory);
    layout->addWidget(viewBookHistory);


    // Seminar management
    QLabel *seminarLabel = new QLabel("Manage Seminars", this);
    layout->addWidget(seminarLabel);

    seminarTitleInput = new QLineEdit(this);
    seminarTitleInput->setPlaceholderText("Enter Seminar Title");
    layout->addWidget(seminarTitleInput);

    seminarDateInput = new QLineEdit(this);
    seminarDateInput->setPlaceholderText("Enter Seminar Date");
    layout->addWidget(seminarDateInput);

    QPushButton *addSeminarButton = new QPushButton("Add Seminar", this);
    connect(addSeminarButton, &QPushButton::clicked, this, &AdminView::addSeminar);
    layout->addWidget(addSeminarButton);

    QPushButton *editSeminarButton = new QPushButton("Edit Seminar", this);
    connect(editSeminarButton, &QPushButton::clicked, this, &AdminView::editSeminar);
    layout->addWidget(editSeminarButton);

    QPushButton *deleteSeminarButton = new QPushButton("Delete Seminar", this);
    connect(deleteSeminarButton, &QPushButton::clicked, this, &AdminView::deleteSeminar);
    layout->addWidget(deleteSeminarButton);


    listViewFeedback = new QListWidget(this);
    layout->addWidget(listViewFeedback);

    QPushButton *viewFeedbackHistory = new QPushButton("View Feedback History", this);
    connect(viewFeedbackHistory, &QPushButton::clicked, this, &AdminView::viewFeedback);
    layout->addWidget(viewFeedbackHistory);
}



void AdminView::loadBooks() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/bookList.txt"); // Path to your books file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open books file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        bookList.push_back(line); // Use push_back to add to vector
    }

    file.close();
}
void AdminView::saveBooks() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/bookList.txt"); // Path to your books file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open books file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &book : bookList) {
        out << book << "\n"; // Write each book on a new line
    }

    file.close();
}
void AdminView::addBook() {
    QString title = bookTitleInput->text();
    QString author = bookAuthorInput->text();
    QString category = bookCategoryInput->text();  // Get the category from the input field

    // Check if the title is empty
    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title.");
        return;
    }

    // Add the book to the list with category included
    QString bookDetails = title;
    if (!author.isEmpty()) {
        bookDetails += " by " + author;  // Append the author if provided
    }
    if (!category.isEmpty()) {
        bookDetails += " (" + category + ")";  // Append the category if provided
    }

    bookList.push_back(bookDetails);  // Add the book to the list
    saveBooks();  // Save the updated list to a file (if necessary)

    QMessageBox::information(this, "Add Book", "Book added: " + bookDetails);

    // Clear input fields
    bookTitleInput->clear();
    bookAuthorInput->clear();
    bookCategoryInput->clear();  // Clear the category input field
}

void AdminView::editBook() {
    QString title = bookTitleInput->text();
    QString author = bookAuthorInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title to edit.");
        return;
    }

    bool bookFound = false;
    for (size_t i = 0; i < bookList.size(); ++i) {
        if (bookList[i].startsWith(title)) {
            bookList[i] = title + (author.isEmpty() ? "" : " by " + author);
            bookFound = true;
            saveBooks(); // Save the updated list after editing
            QMessageBox::information(this, "Edit Book", "Book updated: " + bookList[i]);
            break;
        }
    }

    if (!bookFound) {
        QMessageBox::warning(this, "Edit Error", "Book not found.");
    }
    bookTitleInput->clear();
    bookAuthorInput->clear(); // Clear input fields after editing
}

void AdminView::deleteBook() {
    QString title = bookTitleInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a book title to delete.");
        return;
    }

    auto it = std::remove_if(bookList.begin(), bookList.end(),
                             [&title](const QString &book) { return book.startsWith(title); });
    if (it != bookList.end()) {
        bookList.erase(it, bookList.end());
        saveBooks(); // Save the updated list after deleting
        QMessageBox::information(this, "Delete Book", "Book deleted: " + title);
    } else {
        QMessageBox::warning(this, "Delete Error", "Book not found.");
    }
    bookTitleInput->clear(); // Clear input field after deleting
}



void AdminView::loadUsers() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/users.txt"); // Path to your users file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open users file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        userList.push_back(line); // Use push_back to add to vector
    }

    file.close();
}

void AdminView::saveUsers() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/users.txt"); // Path to your users file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open users file for writing.");
        return;
    }


    QTextStream out(&file);
    for (const QString &user : userList) {
        out << user << "\n"; // Write each user on a new line
    }

    file.close();
}
// Include QUuid header for unique ID generation

void AdminView::addUser() {
    QString username = userInput->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username to add.");
        return;
    }

    // Check if user already exists
    if (std::find(userList.begin(), userList.end(), username) != userList.end()) {
        QMessageBox::warning(this, "Add User Error", "User already exists.");
        return;
    }

    // Generate a unique user ID
    QString userId = QUuid::createUuid().toString(QUuid::WithoutBraces);

    // Open the users file and append the new user details
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/users.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open users file.");
        return;
    }

    QTextStream out(&file);
    file.seek(file.size());  // Move to the end of the file
    out << username << ",{},{}\n";  // Format: username,borrowingHistory,seminarParticipation
    file.close();

    // Store the user ID in a separate file (randomID.txt)
    QFile idFile("C:/Users/hp/Desktop/labProject/LMS-main/randomID.txt");
    if (!idFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to store user ID.");
        return;
    }

    QTextStream idOut(&idFile);
    idOut << username << "," << userId << "\n";  // Format: username,userID
    idFile.close();

    // Add the new user to the list and save the updated list
    userList.push_back(username);
    saveUsers();  // Save the updated user list to the users file

    QMessageBox::information(this, "Add User", "User added: " + username);
    userInput->clear(); // Clear input field after adding
}

void AdminView::deleteUser() {
    QString username = userInput->text();

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a username to delete.");
        return;
    }

    // Delete the user from the users list
    auto it = std::remove(userList.begin(), userList.end(), username);
    if (it != userList.end()) {
        userList.erase(it, userList.end());
        saveUsers(); // Save the updated user list after deleting

        // Now, delete the user ID from the randomID.txt file
        QFile idFile("C:/Users/hp/Desktop/labProject/LMS-main/randomID.txt");
        if (!idFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "File Error", "Could not open user ID file.");
            return;
        }

        QTextStream in(&idFile);
        QStringList lines;
        bool userFound = false;

        // Read all lines and remove the user ID entry
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(',');
            if (parts.size() >= 2 && parts[0] == username) {
                userFound = true;  // User found, skip this line
            } else {
                lines.append(line);  // Keep the other users
            }
        }

        // If user was found and deleted, rewrite the file without their ID
        if (userFound) {
            idFile.resize(0);  // Clear the file before writing new content
            QTextStream out(&idFile);
            for (const QString &line : lines) {
                out << line << "\n";  // Write the remaining users
            }
            idFile.close();
            QMessageBox::information(this, "Delete User", "User and their ID have been deleted: " + username);
        } else {
            QMessageBox::warning(this, "Delete Error", "User ID not found in ID file.");
        }

    } else {
        QMessageBox::warning(this, "Delete Error", "User not found.");
    }

    userInput->clear(); // Clear input field after deleting
}


void AdminView::viewBorrowingHistory(){
    listView->clear();  // Clear the list view

    // Open the borrowing history file
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/borrowHistory.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open borrowing history file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        listView->addItem(line);  // Add each entry to the list view
    }

    file.close();
}
void AdminView::viewFeedback(){


    listViewFeedback->clear();  // Clear the feedback list view

    // Open the feedback file
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/feedback.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open feedback file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        // Assuming feedback format is "username - feedbackText"
        QStringList feedbackData = line.split(" - ");
        if (feedbackData.size() == 2) {
            QString userName = feedbackData[0];
            QString feedbackText = feedbackData[1];

            // Display the feedback entry in the feedback list view
            listViewFeedback->addItem(userName + " said: " + feedbackText);
        }
    }

    file.close();
}
void AdminView::loadSeminars() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/seminar.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open seminars file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        seminarList.push_back(line); // Use push_back to add to vector
    }

    file.close();
}

void AdminView::saveSeminars() {
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/seminar.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open seminars file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &seminar : seminarList) {
        out << seminar << "\n"; // Write each seminar on a new line
    }

    file.close();
}



void AdminView::addSeminar() {
    QString title = seminarTitleInput->text();
    QString date = seminarDateInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title.");
        return;
    }

    seminarList.push_back(title + " on " + date); // Use push_back to add to vector
    saveSeminars(); // Save the updated list after adding
    QMessageBox::information(this, "Add Seminar", "Seminar added: " + title);
    seminarTitleInput->clear();
    seminarDateInput->clear(); // Clear input fields after adding
}

void AdminView::editSeminar() {
    QString title = seminarTitleInput->text();
    QString date = seminarDateInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title to edit.");
        return;
    }

    bool seminarFound = false;
    for (size_t i = 0; i < seminarList.size(); ++i) {
        if (seminarList[i].startsWith(title)) {
            seminarList[i] = title + " on " + date;
            seminarFound = true;
            saveSeminars(); // Save the updated list after editing
            QMessageBox::information(this, "Edit Seminar", "Seminar updated: " + seminarList[i]);
            break;
        }
    }

    if (!seminarFound) {
        QMessageBox::warning(this, "Edit Error", "Seminar not found.");
    }
    seminarTitleInput->clear();
    seminarDateInput->clear(); // Clear input fields after editing
}

void AdminView::deleteSeminar() {
    QString title = seminarTitleInput->text();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a seminar title to delete.");
        return;
    }

    auto it = std::remove_if(seminarList.begin(), seminarList.end(),
                             [&title](const QString &seminar) { return seminar.startsWith(title); });
    if (it != seminarList.end()) {
        seminarList.erase(it, seminarList.end());
        saveSeminars(); // Save the updated list after deleting
        QMessageBox::information(this, "Delete Seminar", "Seminar deleted: " + title);
    } else {
        QMessageBox::warning(this, "Delete Error", "Seminar not found.");
    }
    seminarTitleInput->clear(); // Clear input field after deleting
}
