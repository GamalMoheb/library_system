#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <map>
#include <unordered_map>

class Library {
private:
    std::map<int, Book> books;
    std::unordered_map<int, User> users;

public:
    void addBook(int id, const std::string& title, const std::string& author);
    void deleteBook(int bookId);
    void addUser(int id, const std::string& name);
    void deleteUser(int userId);
    void borrowBook(int userId, int bookId);
    void returnBook(int userId, int bookId);
    void displayBooks() const;
    void displayUsers() const;
};

#endif
