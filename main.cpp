#include <iostream>
#include <string>
#include "Library.h"
using namespace std;
#include "UserManagement.h"

void libraryManagementSystem(Library& library) {
    int choice;
    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book to a Category\n";
        cout << "2. Add Category\n";
        cout << "3. Delete Book From A Category\n";
        cout << "4. Delete A Category\n";
        cout << "5. Delete A Book By Title\n";
        cout << "6. Search Book by Category\n";
        cout << "7. Search Book by Title\n";
        cout << "8. Search Book by Id\n";
        cout << "9. Search Book by Author\n";
        cout << "10. Show All Books\n";
        cout << "11. Lend a Book to a Customer\n";
        cout << "12. Return A Book\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                string category;
                cout << "Enter book category: ";
                getline(cin, category);
                library.addBooktoCategory(category);
                library.saveBooksToFile();
                break;
            }
            case 2: {
                string category;
                cout << "Enter book category to add: ";
                getline(cin, category);
                library.addCategory(category);
                library.saveBooksToFile();
                break;
            }
            case 3: {
                string category;
                cout << "Enter category from which you want to delete: ";
                getline(cin, category);
                library.deleteBookFromCategory(category);
                library.saveBooksToFile();
                break;
            }
            case 4: {
                string category;
                cout << "Enter book category to delete: ";
                getline(cin, category);
                library.deleteACategory(category);
                library.saveBooksToFile();
                break;
            }
            case 5: {
                string title;
                cout << "Enter Book title to delete: ";
                getline(cin, title);
                library.deleteBookByTitle(title);
                library.saveBooksToFile();
                break;
            }
            case 6: {
                string category;
                cout << "Enter book category to search: ";
                getline(cin, category);
                library.displayBooksInACategory(category);
                break;
            }
            case 7: {
                string title;
                cout << "Enter the title to search: ";
                getline(cin, title);
                library.searchBookbytitle(title);
                break;
            }
            case 8: {
                int id;
                cout << "Enter the id to search: ";
                cin >> id;
                library.searchBookById(id);
                cin.ignore();
                break;
            }
            case 9: {
                string author;
                cout << "Enter the Author to search: ";
                getline(cin, author);
                library.searchBookbyauthor(author);
                break;
            }
            case 10:
                library.DisplayBooks();
                break;

            case 11: {
                string title,borrowerName;
                library.DisplayBooks();
                cout << "Enter The Title of book you want to lend: ";
                getline(cin,title);
                bool isborrowed=library.isBookBorrowed(title);
                bool isExists=library.isBookExists(title);

                if(isExists==false) {
                    cout << "Book is not here" << endl;
                    cout << "press enter to continue..." << endl;
                    cin.ignore();
                    break;
                }

                if (isborrowed==false && isExists==true) { // run only if book is not borrowed and also exists
                library.searchBookbytitle(title);
                cout << "Now Enter the Id of Book for Lending: ";
                int id;
                cin >> id;
                cin.ignore();
                cout << "\nEnter the Name of Borrower: ";
                getline (cin,borrowerName);
                library.borrowBook(id,borrowerName);
                library.saveBooksToFile();
                }
                else {
                    cout << "Book is already borrowed.";
                }
                break;
            }
               case 12: {
                cout << "Now Enter the Id of Book for Returning: ";
                int id;
                cin >> id;
                library.returnBook(id);
                library.saveBooksToFile();
                break;
            }
            case 13:
                cout << "Exiting... Saving data.\n";
                library.saveBooksToFile();
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 13);
}


int main() {
    Library library;
    library.loadBooksFromFile();

    UserManagement userManager;
    userManager.loadUsersFromFile("users.txt");

    int choice2;
    bool authenticated = false;

    do {
        cout << "========== Login/SignUp ==========";
        cout << "\n1. Register\n2. Login\n3. Exit\nEnter choice: ";
        cin >> choice2;
        cin.ignore();

        if (choice2 == 1) {
            string username, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            userManager.registerUser(username, password);
            userManager.saveUsersToFile("users.txt");
        } else if (choice2 == 2) {
            string username, password;
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            authenticated = userManager.loginUser(username, password);
            if (authenticated) {
                cout << "\nLogin successful. Accessing Library Management System...\n";
                libraryManagementSystem(library);
            }
        }

    } while (choice2 != 3);

    return 0;
}
