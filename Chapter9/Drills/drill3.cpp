
#include "../../../std_lib_facilities.h"

class Date {
    int y, m, d;                      //year, month, day
    public:
        Date(int y, int m, int d);    //check for valid date and intialize
        void add_day(int n);          //increase the Date by n days
        int month() const {return m;}
        int day() const {return d;}
        int year() const {return y;}
};

bool is_date(int y, int m, int d)
{
    if(m < 1 || m > 12) return false;
    if(d < 0 || d > 31) return false;
    if(y < 0) return false;

    return true;
}

Date::Date(int yy, int mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    if(!is_date(yy, mm, dd)) error("Invalid Date");
}

void Date::add_day(int n)
{
    //increase dd by n days
    d += n;
    if(d > 31) d %= 31;
    
}


ostream& operator<<(ostream& os, const Date& d)
{
    return os<<'('<<d.year()
             <<','<<d.month()
             <<','<<d.day()<<')';
}

int main()
try{
    Date today{2020, 7 , 2};

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