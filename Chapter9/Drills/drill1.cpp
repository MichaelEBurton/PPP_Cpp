
#include "../../../std_lib_facilities.h"

struct Date {
    int y; // year
    int m; //month in year
    int d; //day in month
};

//helper functions:

bool is_date(int y, int m, int d);

void init_day(Date& dd, int y, int m, int d)
{
    if(!is_date(y, m, d)) error("Invalid Date!");  //check that (y,m,d) is a valid date
    //if it is, use it to initialize dd
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    //increase dd by n days
    dd.d += n;
    if(dd.d > 31) dd.d %= 31;
    
}

bool is_date(int y, int m, int d)
{
    if(m < 1 || m > 12) return false;
    if(d < 0 || d > 31) return false;
    if(y < 0) return false;

    return true;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os<<'('<<d.y
             <<','<<d.m
             <<','<<d.d<<')';
}

int main()
try{
    Date today;

    init_day(today, 2020, 7, 2);

    Date tomorrow = today;
    add_day(tomorrow, 1);

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