#include "Book.hpp"

Book::Book(int id, std::string title, std::string author, std::string genre, std::string isbn) noexcept
{
    mId = id;;
    mTitle = title;
    mAuthor = author;
    mGenre = genre;
    mIsbn = isbn;
}

bool Book::operator==(const Book& other) const noexcept
{
    return (this->mTitle == other.mTitle) && (this->mAuthor == other.mAuthor) && (this->mGenre == other.mGenre) && (this->mIsbn == other.mIsbn);
}

std::ostream& operator<<(std::ostream& os, const Book& book) noexcept
{
    os << "ID: " << book.mId << ", Title: " << book.mTitle << ", Author: " << book.mAuthor << ", Genre: " << book.mGenre << ", ISBN: " << book.mIsbn << std::endl;
    return os;
}