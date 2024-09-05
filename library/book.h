#include<iostream>
#include <string>
#include <limits>
using namespace std;
  class book
  {


    private:
    string title,author;
    int num_pages ,year_pub ,ISBN_num;


    public:
    friend   bool operator ==(book &obj1 ,book &obj2 );
    friend ostream& operator<<(std::ostream& os, const book& book);
    friend istream& operator>>(std::istream& is, book& book);



    string get_title()
    {
        return title;
    }
    string get_author()
    {
        return author;
    }
    int get_num_pages()
    {
        return num_pages;
    }
    int get_year_pub()
    {
        return year_pub;
    }
    int get_ISBN_num()
    {
        return ISBN_num;
    }





    void set_title (string a)
    {
        title = a;
    }
    void set_author (string b)
    {
        author = b;
    }
    void set_num_pages (int c)
    {
        num_pages = c;
    }
    void set_year_pub (int d)
    {
        year_pub = d;
    }
    void set_ISBN_num (int e )
    {
        ISBN_num = e;
    }







    book()
    {
      title = "";
      author = "";
      num_pages = 0;
      year_pub = 0;
      ISBN_num = 0;
    }

    book(string a , string b , int c ,int d ,int e)
    {
      title = a;
      author = b;
      num_pages = c;
      year_pub = d;
      ISBN_num = e;
    }
    book(const book& a)
    {
      title = a.title;
      author = a.author;
      num_pages = a.num_pages;
      year_pub = a.year_pub;
      ISBN_num = a.ISBN_num;
    }
  };



  bool operator ==(book & obj ,const string & t )
   {
    return obj.get_title() == t ;
  }
  bool operator ==(book & obj ,const int & isbn )
   {
    return obj.get_ISBN_num() == isbn;
  }
  ostream& operator<<(ostream& os, const book& book) {
    os << "Title: " << book.title << "\n"
       << "Author: " << book.author << "\n"
       << "Number of Pages: " << book.num_pages << "\n"
       << "Year of Publication: " << book.year_pub << "\n"
       << "ISBN Number: " << book.ISBN_num;
    return os;
}

istream& operator>>(istream& is, book& book) {
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Title: ";
    getline(is, book.title);
    
    cout << "Enter Author: ";
    getline(is, book.author);
    
    cout << "Enter Number of Pages: ";
    is >> book.num_pages;
    
    cout << "Enter Year of Publication: ";
    is >> book.year_pub;
    
    cout << "Enter ISBN Number: ";
    is >> book.ISBN_num;
    
    return is;
}