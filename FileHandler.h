#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Book.h"
#include "Category.h"
#include "UserManagement.h"
#include <string>

class FileHandler {
public:
    static void loadBooks(Category*& head, const std::string& filename, int& lastID);
    static void saveBooks(Category* head, const std::string& filename);
    // static void loadUsers(const std::string& filename);
    // static void saveUsers(const std::string& filename);
};

#endif
