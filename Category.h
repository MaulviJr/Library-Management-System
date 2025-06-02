#ifndef CATEGORY_H
#define CATEGORY_H
#include "Book.h"

class Category {
    public:
    string name;
    Book* bookHead;
    Category* next;

 Category(string name);

};


#endif