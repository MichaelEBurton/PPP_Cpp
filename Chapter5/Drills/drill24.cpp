//Error: Logic error, d is assigned a new value in the if statement instead of checkin a condition
//Error: d is converted to an integer
#include "../../../std_lib_facilities.h"

int main()
try{
    int x = 4;
    double d = 5/(x-2);
    if(d == 2) cout<<"Success!\n";
    return 0;
}
catch (exception& e){
    cerr<<"error: "<<e.what()<<"\n";
    return 1;
}
catch(...){
    cerr<<"Oops: unknown exception!\n";
    return 2;
}