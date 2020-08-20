#include <istream>
#include <ostream>

using std::ostream;
using std::istream;

namespace Chrono {

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
    class Invalid {};                //throws an exception

    Date(long int);                  // check for valid date and initialize
    Date() : days{0} {}              // Default constructor
    // the default copy operations are fine

    //nonmodifying operations
    int day();                      // return the current day in the month
    Month month();                  // return the current month in the year
    int year();                     // return the year

	long int days_since_zero() const {return days;} // return days since jan 1, 1960

    // modifying operations
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);


private:
    long int days;
};

bool is_date(long int d);                 // true for valid date

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

std::ostream& operator<<(std::ostream& os, const Date& d);  
std::istream& operator>>(std::istream& is, Date& d);
/*
Day day_of_week(const Date& d);     // day of week of d
Date next_Sunday(const Date& d);    // next Sunday after d
Date next_weekday(const Date& d);   // next weekday after d
*/
}                                   // Chrono

//Chrono.cpp ------------------------------------------------------------------------------------------------------------

#include "Chrono.h"

namespace Chrono {
// member function definitions:

Date::Date(long int dd)
    :days{dd}
{
    if(!is_date(dd)) throw Invalid{};
}

void Date::add_day(int n)
{
    if(n < 0) error("Cannot add negative days");

	days += n;
}

int Date::day()
{
    // add implementation
}

Month Date::month()
{

	// add implementation

}

int Date::year()
{
    int base = 1960;
    
	int increment = days % 365;

	return base + increment;
}

void Date::add_month(int n) //fix=====================================================================
{
    // ...
	int d = day();
	Month m = month();

    int days_in_month = 31;
	switch(m) {
        case Month::feb:
            days_in_month = 28;   // the length of February varies
            break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
            days_in_month = 30;                   // the rest have 30 days
            break;
    }
          
	days += days_in_month - d;
	days += d
}

void Date::add_year(int n)
{
	days += 365;
}
//helper functions:

bool is_date(long int d)
{
    // assume that y is valid

    if(d<=0) return false;                           // d must be positive

    return true;
}

bool operator==(const Date& a, const Date& b)
{
    return a.days_since_zero() == b.days_since_zero();
}

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os<<'('<<d.year()
             <<','<<int(d.month())
             <<','<<d.day()<<')';
}

istream& operator>>(istream& is, Date& dd)
{
    long int d;
    
    is>>d;
    if(!is) return is;
    
    return is;
    }

    dd = Date(d);                         // update dd

    return is;
}

enum class Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};
/*
Day day_of_week(const Date& d)
{
    // ...
}

Date next_Sunday(const Date& d)
{
    // ...
}

Date next_weekday(const Date& d)
{
    // ...
}*/
} // Chrono