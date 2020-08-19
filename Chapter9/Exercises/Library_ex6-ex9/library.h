#include "book.h"              //Import book class
#include "patron.h"            //Import Patron class
#include "../../code/Chrono.h"    //Import Date class

namespace Library_sys {

struct Transaction 
{
    Book b;
    Patron p;
    Chrono::Date d;
    Transaction(Book bb, Patron pp, Chrono::Date dd)
        :b{bb}, p{pp}, d{dd} {}
};

class Library 
{
public:
    void add_book(Book b) {books.push_back(b);  }                 // Add a book to the library
    void add_Patron(Patron p) {patrons.push_back(p);}             // Add a Patron to the library
    void checkout_book(Patron p, Book b, Chrono::Date d);                 // Checkout a book
    vector<Patron> fees_list();                                  //List of Patrons that owe fees

private:
   vector<Book> books;
   vector<Patron> patrons;
   vector<Transaction> transactions;

   bool is_patron(Patron p);
   bool book_exists(Book b);

};

}