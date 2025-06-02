// Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Category.h"
using namespace std;

class Library {
private:
    // Book* head;
    Category* head;
    int lastID;

public:
    Library();
    void loadBooksFromFile();
    void saveBooksToFile();
    void addBooktoCategory(const string& category);
    string toLowerCase(const string& str);
    void addCategory(const string& category);
    void deleteBookFromCategory(const string& category);
    void deleteACategory(const string& category);
    void deleteBookByTitle(const string& title);
    void displayBooksInACategory(const string& category);
    void searchBookbytitle(const string& title);
    void searchBookbyauthor(const string& author);
    void searchBookById(int id);
    Category* findCategoryByName(const string& categoryName);
    void borrowBook(int id, const string& borrowerName);
    void returnBook(int id);
    bool isBookBorrowed(const string& title);
    void DisplayBooks();
};

#endif
