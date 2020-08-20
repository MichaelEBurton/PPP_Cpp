#include <string>
#include <ostream>
#include <vector>

namespace Library_sys {

class Book {
public:
    enum class Genre{
        fiction, nonfiction, periodical, biography, children
    };

    Book(std::string i, std::string t, std::string a, std::string co, bool ch, Genre g); // check valid book & initialize
    Book();                                                 // Default Constructor


    std::string isbn() const {return i;}                         // const member: returns isbn
    std::string title() const {return t;}                        // const member: returns title
    std::string author() const {return a;}                       // const member: returns author
    std::string copyright() const {return co;}                   // const member: returns copyright date
    bool available() const {return ch;}                     // const member: returns status of book, true infers the book is available
    Genre genre() const {return g;}

    void checkin();                                         // check-in a book
    void checkout();                                        // check-out a book

private:
    std::string i;
    std::string t;
    std::string a;
    std::string co;
    bool ch;
    Genre g;
};

std::ostream& operator<<(std::ostream& os, Book::Genre g);
std::ostream& operator<<(std::ostream& os, const Book& b);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);

}
