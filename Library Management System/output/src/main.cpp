#include "Table.hpp"
#include "Menu.hpp"
#include <fstream>

void log(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios_base::app);
    logFile << message << std::endl;
}

int main() {
    database* db;
    int rc = sqlite3_open("LibraryDatabase.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << errorMessage(db) << std::endl;
        return 1;
    }

    if (!createBooksTable(db)) {
        std::cerr << "Failed to create books table." << std::endl;
        sqlite3_close(db);
        return 1;
    }

    displayMenu(db);

    sqlite3_close(db);
    return 0;
}