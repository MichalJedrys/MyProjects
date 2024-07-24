#ifndef TABLE_HPP
#define TABLE_HPP

#include "SQLiteWrapper.hpp"
#include "Book.hpp"

class BooksTable{
public:
    // Create new table.
    static bool createBooksTable(database* db);

    // Clear the table.
    static bool clearBooksTable(database* db);

    // Add new book to the table.
    static bool addBook(database* db, const Book& book);

    // View books in the table.
    static std::vector<Book> viewBooks(database* db);

    // Update the book in the table.
    static bool updateBook(database* db, const Book& book);

    // Delete book from the table.
    static bool deleteBook(database* db, int bookId);
};

#endif // TABLE_HPP