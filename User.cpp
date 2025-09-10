#include "User.h"
#include <algorithm>

User::User(int id, const std::string& name) : id(id), name(name) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
const std::vector<int>& User::getBorrowedBooks() const { return borrowedBooks; }

void User::borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
}

void User::returnBook(int bookId) {
    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookId),
        borrowedBooks.end()
    );
}
