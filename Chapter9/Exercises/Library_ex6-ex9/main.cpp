/*==============================================================*\
| Author: Michael B.                                            |
| Date: 8/19/20                                                 |
| Purpose: This program is used to test the implementation of   |
|            a library class that involves the use of the book, |
|            patron and chrono class. Currently the program is  |
|            not compiling due to some "undefinded reference";  |
|            probably a header issue?                           |
| Edit: Figured out how to resolve undefined references.        |
\*==============================================================*/

#include "library.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace Library_sys;

int main()
try {

    Book gatsby("1-2-3-a", "The Great Gatsby", "F. Scott Fitzgerald", "Jan 1, 1925", true, Book::Genre::fiction);
    Book mice_n_men("1-2-4-a", "Of Mice and Men", "John Steinbeck", "Jan 1, 1937", false, Book::Genre::fiction);
    Book bhot("2-1-5-b", "A brief history of time", "Stephen Hawkings", "Jan 1, 1988", true, Book::Genre::nonfiction);

    cout<<gatsby<<'\n';

    Library lib;

    lib.add_book(gatsby);
    lib.add_book(mice_n_men);
    lib.add_book(bhot);

    Patron Michael("Michael G.", 1234, 0);
    Patron Sophie("Sophie Q.", 1235, 2.0);
    Patron Carl("Carl T.", 2845, 0.0);

    lib.add_Patron(Michael);
    lib.add_Patron(Sophie);
    lib.add_Patron(Carl);
    
    gatsby.checkin();

    cout<<gatsby<<'\n';

    gatsby.checkout();

    Chrono::Date today(20, Chrono::Month::aug,18);
    
    lib.checkout_book(Michael, mice_n_men, today);

    cout<<mice_n_men<<'\n';

    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops unknown exception!";
    return 2;
}
