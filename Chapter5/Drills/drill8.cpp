//Error: Logic Error! c should be set to true
#include "../../../std_lib_facilities.h"

int main()
try{
    bool c = true;
    if(c) cout<<"Success!\n";
    else cout<<"Fail!\n";
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