#include<iostream>
#include <string>
#include <limits>
using namespace std;

class librarybook : public book {
private:
    string status;
    string name_of_borrower;

public:
    librarybook() : status("available"), name_of_borrower("") {}

    librarybook(const string& a, const string& b, const book& obj) : book(obj) {
        status = a;
        name_of_borrower = b;
    }

    librarybook(const librarybook& a) : book(a) {
        status = a.status;
        name_of_borrower = a.name_of_borrower;
    }

    string get_status() const {
        return status;
    }

    string get_name_of_borrower() const {
        return name_of_borrower;
    }

    void set_status(const string& a) {
        status = a;
    }

    void set_name_of_borrower(const string& b) {
        name_of_borrower = b;
    }

    friend ostream& operator<<(ostream& out, const librarybook& obj);
    friend istream& operator>>(istream& in, librarybook& obj);
};

ostream& operator<<(ostream& out, const librarybook& obj) {
    out << static_cast<const book&>(obj) << "\n";
    out << "Status: " << obj.status << "\n";
    out << "Borrower's Name: " << obj.name_of_borrower << "\n";
    return out;
}

istream& operator>>(istream& in, librarybook& obj) {
    in >> static_cast<book&>(obj);  // Use the base class book's input
    in.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

    cout << "Enter Status: ";
    getline(in, obj.status);

    cout << "Enter Borrower's Name (if any): ";
    getline(in, obj.name_of_borrower);

    return in;
}