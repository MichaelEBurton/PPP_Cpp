#include "book.h"
#include "../../../../std_lib_facilities.h"

namespace Library_sys {

// Genre definitions ---------------------------------------------------------

ostream& operator<<(ostream& os, Book::Genre g)
{
    vector<string> genre_tbl = 
    { 
        "Fiction", "Nonfiction", "Periodical", "Biography", "Children"
    };

    return os << genre_tbl[int(g)];
}

// Book Definitions -----------------------------------------------------------
Book::Book()
{
}

Book::Book(string ii, string tt, string aa, string cop, bool che, Genre gg)
    :i{ii}, t{tt}, a{aa}, co{cop}, ch{che}, g{gg}
{

    if(ii.length() > 7) error("invalid ISBN: example of valid form 1-2-3-a");
    if(ii[1] != '-' || ii[3] != '-' || ii[5] != '-') error("invalid ISBN: example of valid form 1-2-3-a");
    if(!isdigit(ii[0]) || !isdigit(ii[2]) || !isdigit(ii[4]) || isdigit(ii[6])) error("invalid ISBN: example of valid form 1-2-3-a");
}

void Book::checkin()
{
    if(ch) error("book already checked in!");

    ch = true;
}

void Book::checkout()
{
    if(!ch) error("book already checked out!");

    ch = false;
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
    string s;

    if(b.available())
        s = "available";
    else 
        s = "unavailable";

    return os<<"isbn: "<<b.isbn()<<'\n'
             <<"Title: "<<b.title()<<'\n'
             <<"Author: "<<b.author()<<'\n'
             <<"Genre: "<<b.genre()<<'\n'
             <<"Status: "<<s<<'\n';    
}

}

