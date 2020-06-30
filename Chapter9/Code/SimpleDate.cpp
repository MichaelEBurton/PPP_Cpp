
#include "../../../std_lib_facilities.h"

struct Date {
    int y; // year
    int m; //month in year
    int d; //day in month
};

Date today;

// set today to December 24, 2005

today.y = 2005;
today.m = 12;
today.d = 24;

Date x;
x.y = -3;
x.m = 13;
x.d = 32;

Date y;
y.y = 2000;
y.m = 2;
y.d = 29;

//helper functions:

void init_day(Date& dd, int y, int m, int d)
{
    //check that (y,m,d) is a valid date
    //if it is, use it to initialize dd
}

void add_day(Date& dd, int n)
{
    //increase dd by n days
}

void f()
{
    Date today();
    init_day(today, 12, 24, 2005); //no day 2005 in year 12!
    add_day(today,1);
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