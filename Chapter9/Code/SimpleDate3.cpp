
#include "../../../std_lib_facilities.h"

class Date {
    int y, m, d;                      //year, month, day
    public:
        Date(int y, int m, int d);    //check for valid date and intialize
        void add_day(int n);          //increase the Date by n days
        int month() {return m;}
        int day() {return d;}
        int year() {return y;}
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