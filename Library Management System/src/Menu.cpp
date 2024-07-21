#include "Menu.hpp"
#include "Book.hpp"
#include <iostream>

void displayMenu(database* db) {
    int choice;
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
                std::getline(std::cin, book.title);
                std::cout << "Enter author: ";
                std::getline(std::cin, book.author);
                std::cout << "Enter genre: ";
                std::getline(std::cin, book.genre);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, book.isbn);

                if (addBook(db, book)) {
                    std::cout << "Book added successfully." << std::endl;
                } else {
                    std::cout << "Failed to add book." << std::endl;
                }
                break;
            }
            case 2:
                viewBooks(db);
                break;
            case 3: {
                Book book;
                std::cout << "Enter book ID to update: ";
                std::cin >> book.id;
                std::cin.ignore();
                std::cout << "Enter new title: ";
                std::getline(std::cin, book.title);
                std::cout << "Enter new author: ";
                std::getline(std::cin, book.author);
                std::cout << "Enter new genre: ";
                std::getline(std::cin, book.genre);
                std::cout << "Enter new ISBN: ";
                std::getline(std::cin, book.isbn);

                if (updateBook(db, book)) {
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

                if (deleteBook(db, bookId)) {
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