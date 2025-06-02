#include <iostream>
#include "Category.h"

using namespace std;

Category::Category(string name) {
    this->name=name;
    this->bookHead=nullptr;
    this->next=nullptr;
}

