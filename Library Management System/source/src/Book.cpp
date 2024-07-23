#include "Book.hpp"

bool addBook(database* db, const Book& book) {
    std::string sql = "INSERT INTO books (title, author, genre, isbn) VALUES (?, ?, ?, ?)";
    sqlStatement* statement;
    if (!prepareStatement(db, sql, &statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        return false;
    }
    setText(statement, 1, book.title);
    setText(statement, 2, book.author);
    setText(statement, 3, book.genre);
    setText(statement, 4, book.isbn);
    if (!evaluateStatement(statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        sqlFinalize(statement);
        return false;
    }
    sqlFinalize(statement);
    return true;
}

void viewBooks(database* db) {
    std::string sql = "SELECT id, title, author, genre, isbn FROM books";
    sqlStatement* statement;
    if (!prepareStatement(db, sql, &statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        return;
    }
    while (hasRow(statement)) {
        Book book;
        
        book.id = getInt(statement, 0);
        book.title = getText(statement, 1);
        book.author = getText(statement, 2);
        book.genre = getText(statement, 3);
        book.isbn = getText(statement, 4);

        std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << ", Genre: " << book.genre << ", ISBN: " << book.isbn << std::endl;
    }
    sqlFinalize(statement);
}

bool updateBook(database* db, const Book& book) {
    std::string sql = "UPDATE books SET title = ?, author = ?, genre = ?, isbn = ? WHERE id = ?";
    sqlStatement* statement;
    if (!prepareStatement(db, sql, &statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        return false;
    }
    setText(statement, 1, book.title);
    setText(statement, 2, book.author);
    setText(statement, 3, book.genre);
    setText(statement, 4, book.isbn);
    setInt(statement, 5, book.id);
    if (!evaluateStatement(statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        sqlFinalize(statement);
        return false;
    }
    sqlFinalize(statement);
    return true;
}

bool deleteBook(database* db, int bookId) {
    std::string sql = "DELETE FROM books WHERE id = ?";
    sqlStatement* statement;
    if (!prepareStatement(db, sql, &statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        return false;
    }
    sqlite3_bind_int(statement, 1, bookId);
    if (!evaluateStatement(statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        sqlFinalize(statement);
        return false;
    }
    sqlFinalize(statement);
    return true;
}