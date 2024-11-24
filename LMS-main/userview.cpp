#include "userview.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include "FeedbackDialog.h"


UserView::UserView(QWidget *parent) : QWidget(parent) {
    setupUI();
    loadBooks();
    loadUserData();
    loadSeminars();

}

UserView::~UserView() {}

void UserView::setupUI() {

    // Set up the layout and UI components
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Search bar
    searchInput = new QLineEdit(this);
    searchInput->setPlaceholderText("Search for a book");
    connect(searchInput, &QLineEdit::textChanged, this, &UserView::searchBooks);
    mainLayout->addWidget(searchInput);

    // List view to display books or seminars
    listView = new QListWidget(this);
    mainLayout->addWidget(listView);
    listView->clear();

    // Borrow button
    borrowButton = new QPushButton("Borrow Book", this);
    mainLayout->addWidget(borrowButton);
    connect(borrowButton, &QPushButton::clicked, this, &UserView::borrowBook);

    // View history button
    viewHistoryButton = new QPushButton("View Borrowing History", this);
    mainLayout->addWidget(viewHistoryButton);
    connect(viewHistoryButton, &QPushButton::clicked, this, &UserView::viewHistory);

    searchInputSeminar = new QLineEdit(this);
    searchInputSeminar->setPlaceholderText("register for a seminar...");
    connect(searchInputSeminar, &QLineEdit::textChanged, this, &UserView::searchSeminars);
    mainLayout->addWidget(searchInputSeminar);

    // List view to display books or seminars
    listViewSeminar = new QListWidget(this);
    mainLayout->addWidget(listViewSeminar);
    listViewSeminar->clear();

    // Register seminar button
    registerButton = new QPushButton("Register for Seminar", this);
    mainLayout->addWidget(registerButton);
    connect(registerButton, &QPushButton::clicked, this, &UserView::registerForSeminar);

    feedbackButton = new QPushButton("Provide Feedback", this);
    mainLayout->addWidget(feedbackButton);
    connect(feedbackButton, &QPushButton::clicked, this, &UserView::provideFeedbackForSeminar);
}

void UserView::loadBooks() {
    // Load books from file
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/bookList.txt"); // Path to your books file
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open books file.");
        return;
    }

    QTextStream in(&file);
    availableBooks.clear(); // Clear the existing list before loading new data
    while (!in.atEnd()) {
        QString line = in.readLine();
        availableBooks.push_back(line); // Add book to vector
    }

    file.close();

    // Display books in the list widget
    listView->clear(); // Clear any previous data in the list view
    for (const auto& book : availableBooks) {
        listView->addItem(book); // Add each book to the list widget
    }
}

void UserView::searchBooks() {
    QString searchTerm = searchInput->text();  // Get search input text
    std::vector<QString> searchResults;  // Vector to store search results

    // Filter books based on the search term
    for (const auto& book : availableBooks) {
        if (book.contains(searchTerm, Qt::CaseInsensitive)) {
            searchResults.push_back(book);  // Add matching books to the results
        }
    }

    // Clear current list and show search results
    listView->clear();
    for (const auto& result : searchResults) {
        listView->addItem(result);  // Add search results to list view
    }
}

void UserView::borrowBook() {
    // Check if the user has reached the borrowing limit
    if (borrowedBooks.size() >= MAX_BORROW_LIMIT) {
        QMessageBox::warning(this, "Limit Reached", "You cannot borrow more than " + QString::number(MAX_BORROW_LIMIT) + " books at a time.");
        return; // Exit the function if the borrowing limit is reached
    }

    QListWidgetItem *selectedItem = listView->currentItem();  // Get selected book
    if (selectedItem) {
        QString selectedBook = selectedItem->text();  // Get the book title

        // Check if the book is available
        auto it = std::find(availableBooks.begin(), availableBooks.end(), selectedBook);
        if (it != availableBooks.end()) {
            // Remove the book from availableBooks and add to borrowedBooks
            availableBooks.erase(it);
            borrowedBooks.push_back(selectedBook);

            borrowingHistory.push_back(selectedBook + " - Due: 2024-12-01");  // Add to borrowing history

            loadBooks();  // Refresh the book list

            // Show success message
            QMessageBox::information(this, "Success", "You have borrowed: " + selectedBook);
        } else {
            QMessageBox::warning(this, "Error", "The book is not available.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please select a book to borrow.");
    }
}

void UserView::viewHistory() {
    listView->clear();  // Clear the list view

    // Display all borrowed books with due dates
    for (const auto& history : borrowingHistory) {
        listView->addItem(history);  // Add each entry in borrowingHistory to the list view
    }
}

void UserView::searchSeminars() {
    QString searchTerm = searchInputSeminar->text();  // Get the search term from the input field
    std::vector<QString> searchResults;

    // Filter seminars based on search input
    for (const auto& seminar : seminarList) {
        if (seminar.contains(searchTerm, Qt::CaseInsensitive)) {
            searchResults.push_back(seminar);
        }
    }

    // Clear the list and show search results
    listViewSeminar->clear();
    for (const auto& result : searchResults) {
        listViewSeminar->addItem(result);  // Add each matching seminar to the list view
    }
}
void UserView::registerForSeminar() {
    QListWidgetItem *selectedItem = listViewSeminar->currentItem();  // Get selected seminar
    if (selectedItem) {
        QString seminarName = selectedItem->text();  // Get seminar title

        // Simulate registration by showing a success message
        QMessageBox::information(this, "Success", "You have registered for: " + seminarName);

        // You can implement more advanced functionality here, such as storing the registration
        // status in a file or database.
    } else {
        // If no seminar is selected, show error
        QMessageBox::warning(this, "Error", "Please select a seminar to register.");
    }
}



void UserView::loadSeminars() {
    listViewSeminar->clear();
    QFile file("C:/Users/hp/Desktop/labProject/LMS-main/seminar.txt");  // File path to store seminars
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open seminars file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();  // Read each line from the file
        seminarList.push_back(line);  // Add line (seminar) to seminarList
    }

    file.close();  // Close the file after reading

    // Update the list view with the loaded seminars
    listViewSeminar->clear();
    for (const auto& seminar : seminarList) {
        listViewSeminar->addItem(seminar);  // Add each seminar to the list view
    }
}
void UserView::provideFeedbackForSeminar() {
    FeedbackDialog feedbackDialog(this);
    if (feedbackDialog.exec() == QDialog::Accepted) {
        QString feedback = feedbackDialog.getFeedback();
        int rating = feedbackDialog.getRating();
        QListWidgetItem *selectedItem = listViewSeminar->currentItem();
        if (selectedItem) {
            QString seminarName = selectedItem->text();

            // Save feedback to a file
            QFile file("C:/Users/hp/Desktop/labProject/LMS-main/feedback.txt");
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << seminarName << " - Rating: " << rating << "/5\n";
                out << "Feedback: " << feedback << "\n\n";
                file.close();
                QMessageBox::information(this, "Thank You", "Your feedback has been submitted.");
            } else {
                QMessageBox::warning(this, "Error", "Failed to save feedback.");
            }
        }
    }
}

void UserView::loadUserData() {
    // Example user data; ideally load from file or database

}
