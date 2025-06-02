// UserManagement.h
#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <string>
#include <vector>
using namespace std;

struct User {
    string username;
    string hashedPassword;
};

class UserManagement {
private:
    vector<User> users;
public:
    void loadUsersFromFile(const string& filename);
    void saveUsersToFile(const string& filename);
    void registerUser(const string& username, const string& password);
    bool loginUser(const string& username, const string& password);
    string hashPassword(const string& password);
};

#endif
