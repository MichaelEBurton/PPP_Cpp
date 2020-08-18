#include "../../../../std_lib_facilities.h"

namespace Library_sys {

enum class Genre{
    fiction, nonfiction, periodical, biography, children
};

class Book {
public:
    Book(string i, string t, string a, string co, bool ch, Genre g); // check valid book & initialize
    Book();                                                 // Default Constructor


    string isbn() const {return i;}                         // const member: returns isbn
    string title() const {return t;}                        // const member: returns title
    string author() const {return a;}                       // const member: returns author
    string copyright() const {return co;}                   // const member: returns copyright date
    string status() const;                                  // const member: returns status of book
    Genre genre() const {return g;};

    void checkin();                                         // check-in a book
    void checkout();                                        // check-out a book

private:
    string i;
    string t;
    string a;
    string co;
    bool ch;
    Genre g;
};

ostream& operator<<(ostream& os, Genre g);
ostream& operator<<(ostream& os, const Book& b);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

}
