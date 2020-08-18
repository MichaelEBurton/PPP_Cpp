#include "library.h"

using namespace std;
using namespace Library_sys;

int main()
try {
    Book gatsby("1-2-3-a", "The Great Gatsby", "F. Scott Fitzgerald", "Jan 1, 1925", false, Genre::fiction);
    Book mice_n_men("1-2-4-a", "Of Mice and Men", "John Steinbeck", "Jan 1, 1937", false, Genre::fiction);
    Book bhot("2-1-5-b", "A brief history of time", "Stephen Hawkings", "Jan 1, 1988", true, Genre::nonfiction);

    cout<<gatsby;

    Book gatsby2 = gatsby;

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

    gatsby.checkout();

    
    lib.checkout_book(Michael, mice_n_men, Chrono::Date{20,Chrono::Month::aug,18});

    cout<<mice_n_men;
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
