// UserManagement.cpp
#include "UserManagement.h"
#include "picosha2.h"  // SHA-256 header
#include <fstream>
#include <iostream>

void UserManagement::loadUsersFromFile(const string& filename) {
    users.clear();
    ifstream inFile(filename);
    if (!inFile) return;

    string username, hashedPassword;
    while (getline(inFile, username) && getline(inFile, hashedPassword)) {
        users.push_back({username, hashedPassword});
    }
    inFile.close();
}

void UserManagement::saveUsersToFile(const string& filename) {
    ofstream outFile(filename);
    for (const auto& user : users) {
        outFile << user.username << endl;
        outFile << user.hashedPassword << endl;
    }
    outFile.close();
}

string UserManagement::hashPassword(const string& password) {
    string hash = picosha2::hash256_hex_string(password);
    return hash;
}

void UserManagement::registerUser(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.username == username) {
            cout << "Username already exists!\n";
            return;
        }
    }

    string hashed = hashPassword(password);
    users.push_back({username, hashed});
    cout << "Registration successful!\n";
}

bool UserManagement::loginUser(const string& username, const string& password) {
    string hashed = hashPassword(password);
    for (const auto& user : users) {
        if (user.username == username && user.hashedPassword == hashed) {
            cout << "Login successful!\n";
            return true;
        }
    }
    cout << "Login failed. Check your credentials.\n";
    return false;
}
