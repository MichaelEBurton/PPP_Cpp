
#include "../../../std_lib_facilities.h"

class Book {
public:
    Book(string i, string t, string a, string co, bool ch); // check valid book & initialize
    Book();                                                 // Default Constructor


    string isbn() const {return i;}                         // const member: returns isbn
    string title() const {return t;}                        // const member: returns title
    string author() const {return a;}                       // const member: returns author
    string copyright() const {return co;}                   // const member: returns copyright date
    string status() const;                                  // const member: returns status of book

    void checkin();                                         // check-in a book
    void checkout();                                        // check-out a book

private:
    string i;
    string t;
    string a;
    string co;
    bool ch;
};

Book::Book(string ii, string tt, string aa, string cop, bool che)
    :i{ii}, t{tt}, a{aa}, co{cop}, ch{che}
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
             <<"Status: "<<b.status()<<'\n';
    
}

int main()
{
    Book gatsby("1-2-3-a", "The Great Gatsby", "F. Scott Fitzgerald", "Jan 1, 1925", false);

    cout<<gatsby;

    Book gatsby2 = gatsby;

    if(gatsby2 == gatsby) cout<<"This should print"<<'\n';
    if(gatsby!= gatsby2) cout<<"Something is wrong"<<'\n';

}


