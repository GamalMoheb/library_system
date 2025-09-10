#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    int id;
    std::string name;
    std::vector<int> borrowedBooks;

public:
    User(int id, const std::string& name);
    int getId() const;
    std::string getName() const;
    const std::vector<int>& getBorrowedBooks() const;
    void borrowBook(int bookId);
    void returnBook(int bookId);
};

#endif
