#include "book.h"

namespace Library_sys {


// Genre definitions ---------------------------------------------------------

ostream& operator<<(ostream& os, Genre g)
{
    vector<string> genre_tbl = 
    { 
        "Fiction", "Nonfiction", "Periodical", "Biography", "Children"
    };

    return os << genre_tbl[int(g)];
}

// Book Definitions -----------------------------------------------------------

Book::Book(string ii, string tt, string aa, string cop, bool che, Genre gg)
    :i{ii}, t{tt}, a{aa}, co{cop}, ch{che}, g{gg}
{

    if(ii.length() > 7) error("invalid ISBN: example of valid form 1-2-3-a");
    if(ii[1] != '-' || ii[3] != '-' || ii[5] != '-') error("invalid ISBN: example of valid form 1-2-3-a");
    if(!isdigit(ii[0]) || !isdigit(ii[2]) || !isdigit(ii[4]) || isdigit(ii[6])) error("invalid ISBN: example of valid form 1-2-3-a");
}

string Book::status() const
{
    if(ch == true) return"Checked out";
    return "Available";
}

void Book::checkin()
{
    if(ch == false) error("book already checked in!");

    ch = false;
}

void Book::checkout()
{
    if(ch == true) error("book already checked out!");

    ch = true;
}

bool operator==(const Book& a, const Book& b)
{
    return a.isbn() == b.isbn();
}

bool operator!=(const Book& a, const Book& b)
{
    return !(a.isbn() == b.isbn());
}

ostream& operator<<(ostream& os, const Book& b)
{
    return os<<"isbn: "<<b.isbn()<<'\n'
             <<"Title: "<<b.title()<<'\n'
             <<"Author: "<<b.author()<<'\n'
             <<"Genre: "<<b.genre()<<'\n'
             <<"Status: "<<b.status()<<'\n';
    
}

}