//Error: Misspecified output operator
//Error: Change s to be fool
#include "../../../std_lib_facilities.h"

int main()
try{
    string s = "fool";
    if(s == "fool") cout<<"Success!\n";
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