#include "Menu.hpp"
#include "Table.hpp"
#include <iostream>

void displayMenu(database* db) {
    int choice;
    std::vector<Book> books;
    do {
        std::cout << "\nWelcome to the library!" << std::endl;
        std::cout << "1. Add Book" << std::endl;
        std::cout << "2. View Books" << std::endl;
        std::cout << "3. Update Book" << std::endl;
        std::cout << "4. Delete Book" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Book book;
                std::cin.ignore();
                std::cout << "Enter title: ";
                std::getline(std::cin, book.mTitle);
                std::cout << "Enter author: ";
                std::getline(std::cin, book.mAuthor);
                std::cout << "Enter genre: ";
                std::getline(std::cin, book.mGenre);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, book.mIsbn);

                if (BooksTable::addBook(db, book)) {
                    std::cout << "Book added successfully." << std::endl;
                } else {
                    std::cout << "Failed to add book." << std::endl;
                }
                break;
            }
            case 2:
                books = BooksTable::viewBooks(db);
                for(auto &book : books)
                {
                    std::cout << book << std::endl;
                }
                break;
            case 3: {
                Book book;
                std::cout << "Enter book ID to update: ";
                std::cin >> book.mId;
                std::cin.ignore();
                std::cout << "Enter new title: ";
                std::getline(std::cin, book.mTitle);
                std::cout << "Enter new author: ";
                std::getline(std::cin, book.mAuthor);
                std::cout << "Enter new genre: ";
                std::getline(std::cin, book.mGenre);
                std::cout << "Enter new ISBN: ";
                std::getline(std::cin, book.mIsbn);

                if (BooksTable::updateBook(db, book)) {
                    std::cout << "Book updated successfully." << std::endl;
                } else {
                    std::cout << "Failed to update book." << std::endl;
                }
                break;
            }
            case 4: {
                int bookId;
                std::cout << "Enter book ID to delete: ";
                std::cin >> bookId;

                if (BooksTable::deleteBook(db, bookId)) {
                    std::cout << "Book deleted successfully." << std::endl;
                } else {
                    std::cout << "Failed to delete book." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);
}