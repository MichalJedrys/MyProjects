#ifndef BOOK_HPP
#define BOOK_HPP

#include "SQLiteWrapper.hpp"
#include <vector>
#include <iostream>

class Book {
public:

    /**
     * @brief Default constructor
     */
    Book() noexcept = default;

    /*
    * @brief Parameterized constructor
    */
    Book(int id, std::string title, std::string author, std::string genre, std::string isbn) noexcept;

    /**
     * @brief Copy constructor
     */
    Book(const Book& other) noexcept = default;

    /**
     * @brief Move constructor
     */
    Book(Book&& other) noexcept = default;

    /**
     * @brief Move assignment operator
     */
    Book& operator=(Book&& other) noexcept = default;

    /**
     * @brief Copy assignment operator
     */
    Book& operator=(const Book& other) noexcept = default;

    /**
     * @brief Destructor
     */
    ~Book() = default;

    /**
     * @brief Equal operator
     */
    bool operator==(const Book& other) const noexcept;

    /**
     * @brief Print operator of PDU class.
     */
    friend std::ostream& operator<<(std::ostream& os, const Book& book) noexcept;

    /**
     * ID of the book in the table
     */
    int mId;

    /**
     * Title of the book
     */
    std::string mTitle;

    /**
     * Author of the book
     */ 
    std::string mAuthor;

    /**
     * Genre of the book
     */
    std::string mGenre;

    /**
     * ISBN number
     */
    std::string mIsbn;
};



#endif // BOOK_HPP