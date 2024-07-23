#include <gtest/gtest.h>
#include "Book.hpp"
#include "Table.hpp"
#include "SQLiteWrapper.hpp"

class BookTest : public ::testing::Test {
protected:
    database* db;

    void SetUp() override {
        openDatabase("TestDatabase", &db);
        createBooksTable(db);
    }

    void TearDown() override {
        closeDatabase(db);
    }
};

TEST_F(BookTest, AddBook) {
    Book book = {1, "Test Title1", "Test Author1", "Test Genre1", "111111"};
    ASSERT_TRUE(addBook(db, book));
    deleteBook(db,1);
}

TEST_F(BookTest, ViewBooks) {
    Book book = {2, "Test Title2", "Test Author4", "Test Genre2", "222222"};
    addBook(db, book);
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output << std::endl;
    EXPECT_NE(output.find("Test Title"), std::string::npos);
    deleteBook(db, 2);
}

TEST_F(BookTest, UpdateBook) {
    Book book = {3, "Test Title3", "Test Author4", "Test Genre3", "333333"};
    addBook(db, book);
    book.title = "Updated Title";
    EXPECT_TRUE(updateBook(db, book));
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Updated Title"), std::string::npos);
    deleteBook(db, 3);
}

TEST_F(BookTest, DeleteBook) {
    Book book = {4, "Test Title4", "Test Author4", "Test Genre4", "444444"};
    addBook(db, book);
    ASSERT_TRUE(deleteBook(db, 4));
    testing::internal::CaptureStdout();
    viewBooks(db);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Test Title"), std::string::npos);
}