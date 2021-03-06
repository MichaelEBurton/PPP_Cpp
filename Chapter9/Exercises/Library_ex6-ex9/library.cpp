#include "library.h"

#include <string>
#include <vector>

using namespace std;
namespace Library_sys {

Library::Library()
{}

bool Library::is_patron(const Patron& p)
{
    for(Patron i:patrons)
        if(i.name() == p.name())
            return true;
    return false;
}

bool Library::book_exists(const Book& b)
{
    for(Book i:books)
        if(i.isbn() == b.isbn())
            return true;
    return false;
}

void Library::checkout_book(Patron& p, Book& b, Chrono::Date& d)
{
    //if(!is_patron(p)) error("Patron cannot be found in our system; sign up for a library card.");
    //if(!book_exists(b)) error("Book not found within our system, try a different book.");

    //if(!b.available()) error("Book is currently checked out.");

    //if(p.owes_fees()) error("Please pay your fees before borrowing books.");

    b.checkout();

    Transaction t(b, p, d);
    transactions.push_back(t);
}

vector<Patron> Library::fees_list()
{
    vector<Patron> f_list;

    for(Patron p:patrons)
        if(p.owes_fees())
            f_list.push_back(p);
    
    return f_list;
}

}

