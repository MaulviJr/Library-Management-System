# 📚 Library Management System in C++

## 🔍 Overview

This project is a **Library Management System** developed in **C++**. It allows users to:

- Register and log in as **Managers**.
- Manage books within **categories**.
- **Search**, **add**, and **delete** books.
- **Persist data** across sessions using **file handling**.

It demonstrates practical use of **Data Structures** like **Linked Lists**, **Vectors**, **Hashing**, and **File Handling** techniques.

---

## 📁 Project Structure

| File               | Purpose                                      |
|--------------------|----------------------------------------------|
| `Library.h/.cpp`   | Main library management logic                |
| `Book.h/.cpp`      | Defines the `Book` class                     |
| `Category.h/.cpp`  | Defines the `Category` class (collection of books) |
| `UserManagement.h/.cpp` | Handles user registration and login    |
| `FileHandler.h/.cpp` | Supports file operations (saving/loading data) |
| `books.txt`        | Stores book records persistently             |
| `users.txt`        | Stores user credentials                      |

---

## 🧠 Data Structures Used

| Data Structure       | Where Used           | Purpose                                         |
|----------------------|----------------------|-------------------------------------------------|
| Multi Linked List    | `Category` class     | Dynamic collection of books in each category    |
| `std::vector`        | `UserManagement`     | Stores list of registered users                 |
| File Handling (`fstream`) | Across the project | Persistent storage of books and users         |

---

## 🚀 Core Functionalities

### 1️⃣ User Management
- Register new users with **unique usernames**
- Login existing users
- Credentials stored securely in `users.txt` using **SHA-256 hash**

### 2️⃣ Book and Category Management
- Add books to categories
- Add new categories dynamically
- Delete books by:
  - Category
  - Title
- Delete entire categories

### 3️⃣ Search Functionalities
- Search books by:
  - Category
  - Title
  - ID
  - Author

### 4️⃣ Lending and Returning Books
- Lend books to customers
- Return books to the library

### 5️⃣ File Handling
- Automatically **save** and **load** data on program start/exit
- Uses `fstream` for reading/writing `books.txt` and `users.txt`

---

## 🧱 Object-Oriented Design

| Class           | Responsibility                                                |
|------------------|---------------------------------------------------------------|
| `Book`           | Represents a single book (ID, title, author)                  |
| `Category`       | Manages books in a category using a linked list               |
| `Library`        | Central system managing categories, books, and interactions   |
| `UserManagement` | Handles user authentication and management                    |
| `FileHandler`    | Reads/writes data to/from files                               |

---

## 🔮 Future Enhancements (Optional)

- 🖥️ **GUI Interface**: Build a graphical frontend for user interaction.
- 🔒 **Encapsulation**: Improve object-oriented design by applying encapsulation principles.
- 🔃 **Sorting Features**: Add support to sort books by title, author, etc.

---

## 📌 Notes

- This project is entirely written in C++.
- No external libraries are used for GUI or database interaction.
