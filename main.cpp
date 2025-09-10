#include "Library.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n2. Add User\n3. Borrow Book\n4. Return Book\n5. Show Books\n6. Show Users\n7. Delete Book\n8. Delete User\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id; 
            string title, author;
            cout << "Enter ID Title Author: ";
            cin >> id;
            cin.ignore();
            getline(std::cin, title);
            getline(std::cin, author);
            lib.addBook(id, title, author);
        } else if (choice == 2) {
            int id;
            string name;
            cout << "Enter ID Name: ";
            cin >> id;
            cin.ignore();
            getline(std::cin, name);
            lib.addUser(id, name);
        } else if (choice == 3) {
            int uid, bid; 
            cout << "Enter UserID BookID: ";
            cin >> uid >> bid; lib.borrowBook(uid, bid);
        } else if (choice == 4) {
            int uid, bid; 
            cout << "Enter UserID BookID: ";
            cin >> uid >> bid; 
            lib.returnBook(uid, bid);
        } else if (choice == 5) {
            lib.displayBooks();
        } else if (choice == 6) {
            lib.displayUsers();
        } else if (choice == 7) {
            int id;
             cout << "Enter Book ID: ";
             cin >> id; lib.deleteBook(id);
        } else if (choice == 8) {
            int id; 
            cout << "Enter User ID: "; 
            cin >> id;
             lib.deleteUser(id);
        }
    } while (choice != 0);

    return 0;
}
 