#include <iostream>
#include "Book.h"
using namespace std;


Book::Book(int id, string title, string author,bool isBorrowed,string borrowerName) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->borrowerName=borrowerName;
    this->isBorrowed=isBorrowed;
    this->next = nullptr;
}