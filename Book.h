#ifndef BOOK_H
#define BOOK_H
#include <chrono>
#include <iostream>
using namespace std;

class Book {
public:
int id;
string title;
string author;
bool isBorrowed;
string borrowerName;
Book* next;

    Book(int id, string title, string author,bool isBorrowed,string borrowerName);

};


#endif