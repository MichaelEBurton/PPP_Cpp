//Error: Success not enclosed in quotes and is "not declared in this scope"

#include "../../../std_lib_facilities.h"

int main()
try{
    string success = "Success!";
    cout<<success<<'\n';
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