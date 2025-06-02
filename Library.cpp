// Library.cpp
#include "Library.h"
#include "FileHandler.h"
#include "Category.h"
#include <iostream>  // For cout, endl
#include <iomanip>   // For manipulators like setw, setprecision, left, right
#include <fstream>

Library::Library() {
    head = nullptr;
    lastID = 0;
}

void Library::loadBooksFromFile() {
    FileHandler::loadBooks(head, "books.txt", lastID);
}

void Library::saveBooksToFile() {
    FileHandler::saveBooks(head, "books.txt");
}

// In Library.h (or Library.cpp if you prefer private methods)
Category* Library::findCategoryByName(const string& categoryName) {
    Category* temp = head;
    while (temp != nullptr) {
        if (temp->name == categoryName) {
            return temp; // Found the category
        }
        temp = temp->next;
    }
    return nullptr; // Category not found
}
// helper function for converting to lower case. for making it user-friendly
string Library::toLowerCase(const string& str) {
    string lower = str;
    for (char& c : lower) {
        c = tolower(c);  // `tolower` from <cctype>
    }
    return lower;
}


void Library::addBooktoCategory(const string& category) {
    // Find the category in the linked list
    Category* temp = findCategoryByName(category);

    if (temp == nullptr) {
        cout << "Category Not Found!" << endl;
        return;
    }

    int choice = 1; // Start with Yes (1)

    while (choice == 1) {
        string title, author;

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        lastID++; // Auto-assign new ID

        // Create new book
        Book* newBook = new Book(lastID, title, author, 0, "N/A");

        // Add to category's book list
        if (temp->bookHead == nullptr) {
            temp->bookHead = newBook;
        } else {
            Book* tempBook = temp->bookHead;
            while (tempBook->next != nullptr) {
                tempBook = tempBook->next;
            }
            tempBook->next = newBook;
        }

        cout << "The Book \"" << title << "\" by " << author << " was added to category \"" << category << "\"." << endl;

        cout << "\nDo you want to add another book to this category? (1 for Yes, 0 for No): ";
        cin >> choice;
        cin.ignore(); // Add this here to clear newline after number input
    }
}


void Library::addCategory(const string& category) {
    // Check if category already exists in the linked list
    Category* temp = findCategoryByName(category);

    if (temp != nullptr) {
        cout << "Category \"" << category << "\" already exists." << endl;
        return;
    }

    // If not found, add new category at the end
    Category* newCategory = new Category(category);

    if (head == nullptr) {
        head = newCategory;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newCategory;
    }

  cout << "Do you want to add books to this category?" << endl;
cout << "1 for Yes, 0 for No: ";
int input;
cin >> input;
cin.ignore(); // Clears leftover '\n' from cin >> input

if (input == 1) {
    string title, author;
    int choice = 1;

addBooktoCategory(category);
}
}

void Library::deleteBookFromCategory(const string& category){
    Category* temp=findCategoryByName(category);

    if (temp==nullptr) {
        cout << "Category Not Found!" << endl;
        return;
    }
    else {
      displayBooksInACategory(category);
      cout << "What you wanna delete? Enter id: ";
      int id;
        cin >> id;
        Book* bookList=temp->bookHead;

        
    Book* prev = nullptr;

    while (bookList != nullptr) {
        if (bookList->id == id) {
            if (prev == nullptr) {
                // Deleting head node
                temp->bookHead = bookList->next; 
            } else {
                // Deleting a non-head node
                prev->next = bookList->next;
            }
            delete bookList;
            cout << "Book with ID " << id << " deleted.\n";
            return; // Done, exit the function
        }
        prev = bookList;
        bookList = bookList->next;
    }

    cout << "Book with ID " << id << " not found.\n";
      
    }
}

void Library::displayBooksInACategory(const string& category) {
    Category* temp = findCategoryByName(category);

    if (temp == nullptr) {
        cout << "Category Not Found!" << endl;
        return;
    }

    Book* catBooks = temp->bookHead;
    if (catBooks == nullptr) {
        cout << "No books in that category!" << endl;
    } else {
        cout << "\n=== Books in Category: " << category << " ===" << endl;

        // Table headers
        cout << left
             << setw(5)  << "ID"
             << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(15) << "Status"
             << setw(20) << "Borrower Name" << endl;

        cout << string(90, '-') << endl; // Divider

        while (catBooks != nullptr) {
            cout << left
                 << setw(5)  << catBooks->id
                 << setw(30) << catBooks->title
                 << setw(20) << catBooks->author
                 << setw(15) << (catBooks->isBorrowed ? "Borrowed" : "Not Borrowed")
                 << setw(20) << (catBooks->isBorrowed ? catBooks->borrowerName : "-") << endl;

            catBooks = catBooks->next;
        }

        cout << string(90, '-') << endl; // Ending divider
    }
}

void Library::deleteACategory(const string&category) {
 Category* temp = findCategoryByName(category);

    if (temp == nullptr) {
        cout << "Category Not Found!" << endl;
        return;
    } else {
        Category* prev=head;
            if (temp==head) {  
                head=head->next;
                
            }
            else  {
                while (prev->next!=temp) {
                    prev=prev->next;
                }
                prev->next=temp->next;
            }
            delete temp;
        cout << "The Category " << category << " has been deleted!" << endl;
    }
}

void Library::searchBookbytitle(const string& title) {
    string newtitle=toLowerCase(title);

    Category * temp=head;
    while (temp!=nullptr) {
        Book* bb=temp->bookHead;
        while (bb!=nullptr) {
            if (toLowerCase(bb->title)==newtitle) {
                cout << "Book " << bb->title << " was found in " << temp->name << " category! " << endl;
                cout << "Id No: " << bb->id << endl;
                return;
            }
            bb=bb->next;
        }
        temp=temp->next;
    }
    cout << "Book not found!" << endl;
}

void Library::searchBookById(int id) {
    Category * temp=head;
    while (temp!=nullptr) {
        Book* bb=temp->bookHead;
        while (bb!=nullptr) {
            if (bb->id==id) {
                cout << "Book of Id " << bb->id << " was found in " << temp->name << " category! " << endl;
                cout << "Book Name: " << bb->title << " by " << bb->author << endl;
                return;
            }
            bb=bb->next;
        }
        temp=temp->next;
    }
    cout << "Book not found!" << endl;
}

void Library::searchBookbyauthor(const string& author) {
    string newauthor=toLowerCase(author);

    Category * temp=head;
    while (temp!=nullptr) {
        Book* bb=temp->bookHead;
        while (bb!=nullptr) {
            if (toLowerCase(bb->author).find(newauthor) != string::npos) {
                cout << "Book by " << bb->author << " was found in " << temp->name << " category! " << endl;
                cout << "Name of Book is " << bb->title << endl; 
                
                return;
            }
            bb=bb->next;
        }
        temp=temp->next;
    }
    cout << "Book not found!" << endl;
}


void Library::deleteBookByTitle(const string& title) {
     Category* temp = head;
    string lowerCaseTitle=toLowerCase(title);
      if (temp == nullptr) {
        cout << "No Books are There!" << endl;
        return;
    } else {
        while (temp!=nullptr) {
         Book* catBooks = temp->bookHead;
         Book* prev=nullptr;
          while (catBooks!=nullptr) {
            if (toLowerCase(catBooks->title)==lowerCaseTitle) { // makign it lower case for user-freidnly
                  if (prev == nullptr) {
                // Deleting head node
                temp->bookHead = catBooks ->next;
            } else {
                // Deleting a non-head node
                prev->next =catBooks->next;
            }
            delete catBooks ;
            cout << "Book with title " << title << " deleted.\n";
            return; // Done, exit the function
            }
            
            prev=catBooks;
            catBooks=catBooks->next;
          }

          temp=temp->next;
        }
       
    }
 
    cout << "Book with title " << title << " not found.\n";
}

#include <iomanip> // For setw()

void Library::DisplayBooks() {
    Category* temp = head;

    if (temp == nullptr) {
        cout << "No categories found!" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << "\n=== Category: " << temp->name << " ===" << endl;

        Book* bb = temp->bookHead;
        if (bb == nullptr) {
            cout << "No books in this category." << endl;
        } else {
            // Table headers
            cout << left
                 << setw(5)  << "ID"
                 << setw(30) << "Title"
                 << setw(20) << "Author"
                 << setw(15) << "Status"
                 << setw(20) << "Borrower Name" << endl;

            cout << string(90, '-') << endl; // Divider

            while (bb != nullptr) {
                cout << left
                     << setw(5)  << bb->id
                     << setw(30) << bb->title
                     << setw(20) << bb->author
                     << setw(15) << (bb->isBorrowed ? "Borrowed" : "Not Borrowed")
                     << setw(20) << (bb->isBorrowed ? bb->borrowerName : "-") << endl;
                bb = bb->next;
            }
        }
        temp = temp->next;
    }
    cout <<"Press Enter to continue..." << endl;
    
    cin.get();
}

// Assuming you have this in your Library class

bool Library::isBookExists(const string& title) {
    Category* currCategory = head;
    string newtitle=toLowerCase(title);
    while (currCategory != nullptr) {
        Book* currBook = currCategory->bookHead;
        while (currBook != nullptr) {
            if (toLowerCase(currBook->title) == title) {
                // Found the book
                return true;
            }
            currBook = currBook->next;
        }
        currCategory = currCategory->next;
    }

    // Book not found
    return false;
}


bool Library::isBookBorrowed(const string& title) {
    string newTitle= toLowerCase(title);
    Category* currCategory = head;
    while (currCategory != nullptr) {
        Book* currBook = currCategory->bookHead;
        while (currBook != nullptr) {
            if (toLowerCase(currBook->title) == newTitle) {
                return currBook->isBorrowed;
            }
            currBook = currBook->next;
        }
        currCategory = currCategory->next;
    }
    return false; // Book not found, so we assume not borrowed
}


void Library::borrowBook(int id, const string& borrowerName) {
    Category* currCategory = head;
    while (currCategory != nullptr) {
        Book* currBook = currCategory->bookHead; // Assuming Category has a method to get book head.
        while (currBook != nullptr) {
            if (currBook->id == id) {
                if (!currBook->isBorrowed) {
                    currBook->isBorrowed=true;
                    currBook->borrowerName=borrowerName;
                    cout << "Book ID " << id << " has been borrowed by " << borrowerName << ".\n";
                    return;
                } 
                // else {
                //     cout << "Book ID " << id << " is already borrowed by " << currBook->borrowerName << ".\n";
                //     return;
                // }
            }
            currBook = currBook->next;
        }
        currCategory = currCategory->next;
    }
    cout << "Book with ID " << id << " not found.\n";
}

void Library::returnBook(int id) {
    Category* currCategory=head;
    while (currCategory!=nullptr) {
        Book * currBook= currCategory->bookHead;
        while (currBook!=nullptr) {
                if (currBook->id==id) {
                    if(currBook->isBorrowed==true) {
                        currBook->isBorrowed=false;
                        cout << "The Book " << currBook->title << " was Borrowed by " << currBook->borrowerName << " and it has been returned! " << endl;
                        currBook->borrowerName="N/A";
                        return;
                    }
                     else {
                    cout << "The book " << currBook->title << " wasn't borrowed by anyone! " << endl;
                        return;
                }
                }
               
                currBook=currBook->next;
        }
        currCategory=currCategory->next;
    }
   cout << "Book with ID " << id << " not found.\n";

    

}