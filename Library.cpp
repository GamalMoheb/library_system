#include "Library.h"
#include <iostream>

void Library::addBook(int id, const std::string& title, const std::string& author) {
    books.emplace(id, Book(id, title, author));
}

void Library::deleteBook(int bookId) {
    if (books.erase(bookId))
        std::cout << "✅ Book deleted!\n";
    else
        std::cout << "❌ Book not found!\n";
}

void Library::addUser(int id, const std::string& name) {
    users.emplace(id, User(id, name));
}

void Library::deleteUser(int userId) {
    if (users.erase(userId))
        std::cout << "✅ User deleted!\n";
    else
        std::cout << "❌ User not found!\n";
}

void Library::borrowBook(int userId, int bookId) {
    if (users.find(userId) == users.end()) { std::cout << "❌ User not found!\n"; return; }
    if (books.find(bookId) == books.end()) { std::cout << "❌ Book not found!\n"; return; }
    if (books.at(bookId).isBookBorrowed()) { std::cout << "❌ Book already borrowed!\n"; return; }

    books.at(bookId).borrowBook();
    users.at(userId).borrowBook(bookId);
    std::cout << "✅ Book borrowed!\n";
}

void Library::returnBook(int userId, int bookId) {
    if (users.find(userId) == users.end() || books.find(bookId) == books.end()) {
        std::cout << "❌ Invalid user or book!\n";
        return;
    }
    books.at(bookId).returnBook();
    users.at(userId).returnBook(bookId);
    std::cout << "✅ Book returned!\n";
}

void Library::displayBooks() const {
    std::cout << "\n📚 Books:\n";
    for (const auto& pair : books) {
        const Book& book = pair.second;
        std::cout << "ID: " << book.getId() << " | Title: " << book.getTitle()
                  << " | Author: " << book.getAuthor()
                  << " | Status: " << (book.isBookBorrowed() ? "Borrowed" : "Available") << "\n";
    }
}

void Library::displayUsers() const {
    std::cout << "\n👤 Users:\n";
    for (const auto& pair : users) {
        const User& user = pair.second;
        std::cout << "User ID: " << user.getId() << " | Name: " << user.getName() << " | Books: ";
        for (int bookId : user.getBorrowedBooks()) std::cout << bookId << " ";
        std::cout << "\n";
    }
}
