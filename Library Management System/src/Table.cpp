#include "Table.hpp"
#include <iostream>

bool createBooksTable(database* db) {
    std::string sqlCreateTable =
        "CREATE TABLE IF NOT EXISTS books ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "author TEXT NOT NULL,"
        "genre TEXT,"
        "isbn TEXT UNIQUE NOT NULL);";
    
    sqlStatement* statement;
    if (!prepareStatement(db, sqlCreateTable, &statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        return false;
    }
    if (!evaluateStatement(statement)) {
        std::cerr << "SQL error: " << errorMessage(db) << std::endl;
        sqlFinalize(statement);
        return false;
    }
    sqlFinalize(statement);
    return true;
}