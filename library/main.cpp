#include<iostream>
#include <string>
#include <limits>
#include "book.h"
#include "LibraryBook.h"
#include "library.h"
using namespace std;
int main() {
    library lib("Mohamed Library", 10); // Create an instance of the library
    int choice;

    do {
        cout << "============== MOHAMED LIBRARY ==============\n";
        cout << "Press 1 to add a book\n";
        cout << "Press 2 to search for a book by title\n";
        cout << "Press 3 to search for a book by ISBN\n";
        cout << "Press 4 to borrow a book\n";
        cout << "Press 5 to delete a book\n";
        cout << "Press 6 to show all books\n";
        cout << "Press 7 to exit\n";

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter book details: ";
                librarybook newbook;
                cin >> newbook;
                lib.addbook(newbook);
                break;
            }
            case 2: {
                cout << "Enter the title: ";
                string bookname1;
                cin >> bookname1;
                librarybook* foundBook = lib.searchbytitle(bookname1);
                if (foundBook) {
                    cout << *foundBook << endl; // Dereference to print the book details
                } else {
                    cout << "Book not found!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter the ISBN: ";
                int isbnnum;
                cin >> isbnnum;
                librarybook* foundBook = lib.searchbyisbn(isbnnum);
                if (foundBook) {
                    cout << *foundBook << endl;
                } else {
                    cout << "Book not found!" << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter the name of the book to borrow: ";
                string title3;
                cin >> title3;
                lib.borrowbook(title3);
                break;
            }
            case 5: {
                cout << "Enter the name of the book to delete: ";
                string title4;
                cin >> title4;
                lib.deletebook(title4);
                break;
            }
            case 6: {
                lib.print();
                break;
            }
            case 7: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice, please try again!" << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
