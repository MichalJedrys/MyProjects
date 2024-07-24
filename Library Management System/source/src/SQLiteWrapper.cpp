#include "SQLiteWrapper.hpp"
#include <iostream>

bool prepAndEvaluate(database* db, std::string str)
{
    sqlStatement* statement;
    if (!prepareStatement(db, str, &statement)) {
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
    