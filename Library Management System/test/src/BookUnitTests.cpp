#include <gtest/gtest.h>
#include "Book.hpp"
#include "Table.hpp"
#include "SQLiteWrapper.hpp"

class BookTest : public ::testing::Test {
protected:
    database* db;
    uint64_t isbn = 0;
    std::vector<Book> books;
    
    void SetUp() override {
        openDatabase("TestDatabase", &db);
        BooksTable::createBooksTable(db);
    }
    
    void TearDown() override {
        closeDatabase(db);
    }
};

TEST_F(BookTest, AddBook) {
    //Assert
    ASSERT_TRUE(BooksTable::addBook(db, Book(1, "Test Title1", "Test Author1", "Test Genre1", "111111")));

    //Clean
    ASSERT_TRUE(BooksTable::clearBooksTable(db));
}

TEST_F(BookTest, ViewBooks) {
    //Arrange
    const uint16_t numberOfBooks = 4;
    Book book1(0, "Test Title1", "Test Author1", "Test Genre1", "111111");
    Book book2(0, "Test Title2", "Test Author2", "Test Genre2", "222222");
    Book book3(0, "Test Title3", "Test Author4", "Test Genre3", "333333");
    Book book4(0, "Test Title4", "Test Author4", "Test Genre4", "444444");
    BooksTable::addBook(db, book1);
    BooksTable::addBook(db, book2);
    BooksTable::addBook(db, book3);
    BooksTable::addBook(db, book4);
    std::array<Book,numberOfBooks> testBooks = {book1,book2,book3,book4};

    //Act
    books = BooksTable::viewBooks(db);

    //Assert
    for(int i=0;i<books.size();i++)
    {   
        ASSERT_EQ(books[i],testBooks[i]);
    }

    //Clean
    BooksTable::clearBooksTable(db);
}

TEST_F(BookTest, UpdateBook) {
    //Arrange
    Book book(0, "Test Title", "Test Author", "Test Genre", "111111");
    Book bookTest(0, "Updated Title", "Test Author", "Updated Genre", "111111");
    BooksTable::addBook(db, book);
    books = BooksTable::viewBooks(db);

    //Act
    book.mId = books[0].mId;
    book.mTitle = "Updated Title";
    book.mGenre = "Updated Genre";
    ASSERT_TRUE(BooksTable::updateBook(db, book));
    books = BooksTable::viewBooks(db);

    //ASSERT
    ASSERT_EQ(books[0],bookTest);

    //Clean
    BooksTable::clearBooksTable(db);
}

TEST_F(BookTest, DeleteBook) {
    //Arrange
    Book book = {0, "Test Title", "Test Author", "Test Genre", "111111"};
    BooksTable::addBook(db, book);
    
    //Act
    books = BooksTable::viewBooks(db);
    ASSERT_TRUE(BooksTable::deleteBook(db, books[0].mId));

    //Assert
    books = BooksTable::viewBooks(db);
    ASSERT_TRUE(books.size() == 0);

    //Clean
    BooksTable::clearBooksTable(db);
}