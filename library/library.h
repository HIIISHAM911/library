#include<iostream>
#include <string>
#include <limits>
using namespace std;
class library {
private:
    string name;
    librarybook* books;
    int capacity;
    int numberOfBooks;

public:
    library() : name(""), capacity(10), numberOfBooks(0) {
        books = new librarybook[capacity];
    }

    library(string n, int c) : name(n), capacity(c), numberOfBooks(0) {
        books = new librarybook[capacity];
    }

    ~library() {
        delete[] books;
    }

    void addbook(const librarybook& lib) {
        if (numberOfBooks < capacity) {
            books[numberOfBooks++] = lib;
            cout << "The book has been added.\n";
        } else {
            cout << "Library is full.\n";
        }
    }

    librarybook* searchbytitle(const string& title1) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (books[i].get_title() == title1)
                return &books[i];
        }
        return nullptr;
    }

    librarybook* searchbyisbn(int num1) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (books[i].get_ISBN_num() == num1)
                return &books[i];
        }
        return nullptr;
    }

    void borrowbook(const string& title) {
        librarybook* foundBook = searchbytitle(title);
        if (foundBook && foundBook->get_status() == "available") {
            foundBook->set_status("borrowed");
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "Book is already borrowed or not found.\n";
        }
    }

    void deletebook(const string& title) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (books[i].get_title() == title) {
                for (int j = i; j < numberOfBooks - 1; j++) {
                    books[j] = books[j + 1];
                }
                numberOfBooks--;
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void print() const {
        for (int i = 0; i < numberOfBooks; i++) {
            cout << books[i] << endl;
        }
    }
};