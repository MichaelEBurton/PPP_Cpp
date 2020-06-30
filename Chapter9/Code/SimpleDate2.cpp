
#include "../../../std_lib_facilities.h"

struct Date {
    int y, m, d;                  //year, month, day
    Date(int y, int m, int d);    //check for valid date and intialize
    void add_day(int n);          //increase the Date by n days
};



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