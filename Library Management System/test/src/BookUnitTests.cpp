#include <gtest/gtest.h>
#include "Book.hpp"
#include "Table.hpp"
#include "SQLiteWrapper.hpp"

class BookTest : public ::testing::Test {
protected:
    database* db;

    void SetUp() override {
        openDatabase(":memory:", &db);
        createBooksTable(db);
    }

    void TearDown() override {
        closeDatabase(db);
    }
};

TEST_F(BookTest, AddBook) {
    Book book = {0, "Test Title", "Test Author", "Test Genre", "123456789"};
    EXPECT_TRUE(addBook(db, book));
}

TEST_F(BookTest, ViewBooks) {
    Book book = {0, "Test Title", "Test Author", "Test Genre", "123456789"};
    addBook(db, book);
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Test Title"), std::string::npos);
}

TEST_F(BookTest, UpdateBook) {
    Book book = {0, "Test Title", "Test Author", "Test Genre", "123456789"};
    addBook(db, book);
    book.title = "Updated Title";
    EXPECT_TRUE(updateBook(db, book));
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Updated Title"), std::string::npos);
}

TEST_F(BookTest, DeleteBook) {
    Book book = {0, "Test Title", "Test Author", "Test Genre", "123456789"};
    addBook(db, book);
    EXPECT_TRUE(deleteBook(db, 1));
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Test Title"), std::string::npos);
}