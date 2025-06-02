// FileHandler.cpp
#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

void FileHandler::loadBooks(Category*& head, const string& filename, int& lastID) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    int maxID = 0;  // Track the largest ID
    while (getline(file, line)) {
    if (line.empty()) continue; // Skip empty lines

    if (line.back() == '#') { // Category line
        string category = line.substr(0, line.length() - 1);
        Category* newCategory = new Category(category);
        // Link category into category list (linked list of categories)
        if (head == nullptr) {
            head = newCategory;
        } else {
            Category* tempCat = head;
            while (tempCat->next != nullptr) tempCat = tempCat->next;
            tempCat->next = newCategory;
        }

        // Now read books for this category
        while (getline(file, line) && line != "END_CATEGORY") {
            stringstream ss(line);
            string idStr, title, author,borrowerName,isBorrowed;
           
            getline(ss, idStr, '|');
            getline(ss, title, '|');
            getline(ss, author, '|');
            getline(ss,isBorrowed,'|');
            getline(ss,borrowerName,'|');
            bool isBorrow=stoi(isBorrowed); // it will take string as 1 or 0, then we convert it to integer which tells ether true or false.
            int id = stoi(idStr);
            if (id > maxID) maxID = id;

            Book* newBook = new Book(id, title, author,isBorrow,borrowerName);
            if (newCategory->bookHead == nullptr) {
                newCategory->bookHead = newBook;
            } else {
                Book* tempBook = newCategory->bookHead;
                while (tempBook->next != nullptr) tempBook = tempBook->next;
                tempBook->next = newBook;
            }
        }
    }
}


    lastID = maxID;  // Update last ID for Library class
    file.close();
}


void FileHandler::saveBooks(Category* head, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    Category* temp = head;
    while (temp != nullptr) {
        file << temp->name << "#" << endl;

        Book* bookTemp = temp->bookHead;  // Start of book list for this category
        while (bookTemp != nullptr) {
            file << bookTemp->id << "|"
                 << bookTemp->title << "|"
                 << bookTemp->author << "|"
                 << (bookTemp->isBorrowed ? "1" : "0") << "|"
                 << bookTemp->borrowerName << endl;
            bookTemp = bookTemp->next;  // Move to the next book
        }

        file << "END_CATEGORY" << endl;  // Optional marker for end of this category
        temp = temp->next;  // Move to the next category
    }

    file.close();
}

