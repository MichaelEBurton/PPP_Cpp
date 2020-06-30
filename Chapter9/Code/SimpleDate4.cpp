
#include "../../../std_lib_facilities.h"

class Date {
    public:
        class Invalid {}              //to be used as an exception
        Date(int y, int m, int d);    //check for valid date and intialize
        void add_day(int n);          //increase the Date by n days
        int month() {return m;}
        int day() {return d;}
        int year() {return y;}
    private:
        int y, m, d;                  //year, month, day
        bool is_valid();              //return true if date is valid
};

Date::Date(int yy, int mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if(!is_valid()) throw Invalid{};
}

bool Date::is_valid()
{
    if(m < 1 || 12 < m) return false;
    // ...
}

void Date::add_day(int n)
{
    // ...
}


int main()
try{

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