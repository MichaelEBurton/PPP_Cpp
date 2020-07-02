
#include "../../../std_lib_facilities.h"

enum class Month {
    jan = 0, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
vector<string> month_tbl = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December" };

ostream& operator<<(ostream& os, Month m)
{
    return os << month_tbl[int(m)];
}

Month operator++(Month& m)
{
    m = (m==Month::dec)?Month::jan:Month(int(m)+1);

    return m;
}

class Date {
    public:
        Date(int y, Month m, int d);    //check for valid date and intialize
        
        int day() const {return d;}
        Month month() const {return m;}
        int year() const {return y;}

        void add_day(int n);          //increase the Date by n days
        void add_month(int n);        
        void add_year(int n) ;
    private:
        int y;                        //year, month, day
        Month m;
        int d;                  
};

Date::Date(int yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if(d < 1 || d > 31) error("Invalid Date");
}

void Date::add_day(int n)
{
    //increase dd by n days
    d += n;
    if(d > 31) d %= 31;
}

void Date::add_month(int n)
{
    // ...
    ++m;
}

void Date::add_year(int n)
{
    //...
    y += 1;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os<<'('<<d.year()
             <<','<<d.month()
             <<','<<d.day()<<')';
}

int main()
try{
    Date today{2020, Month::jul , 2};

    Date tomorrow = today;
    tomorrow.add_day(1);

    cout<<today<<'\n'
        <<tomorrow<<'\n';
    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops! Unkwon exception.";
    return 2;
}