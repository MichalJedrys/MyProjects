#ifndef BOOK_HPP
#define BOOK_HPP

#include "SQLiteWrapper.hpp"
#include <vector>
#include <iostream>

/*
* @brief Book structure containing all properties.
*/
struct Book {
    int id;
    std::string title;
    std::string author;
    std::string genre;
    std::string isbn;
};

// Add new book to the table.
bool addBook(database* db, const Book& book);

// View books in the table.
void viewBooks(database* db);

// Update the book in the table.
bool updateBook(database* db, const Book& book);

// Delete book from the table.
bool deleteBook(database* db, int bookId);

#endif // BOOK_HPP