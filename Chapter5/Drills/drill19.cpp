//Error: Forgot initialization type for vector
//Error: For loop doesn't do anything... unless we change it to print success multiple times
#include "../../../std_lib_facilities.h"

int main()
try{
    vector<int> v(5);
    for(int i = 0; i < v.size(); ++i); cout<<"Success!\n";
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