#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main() {
    try {
        // Create a MySQL driver instance
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        // Connect to the MySQL database
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");

        // Connect to the specific database
        con->setSchema("library_management");

        std::cout << "Connected to the database successfully!" << std::endl;

        // Clean up
        delete con;
    } catch (sql::SQLException &e) {
        std::cout << "SQLException: " << e.what() << std::endl;
        std::cout << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cout << "SQLState: " << e.getSQLState() << std::endl;
    }

    return 0;
}