//Error: Condition should be < 9
#include "../../../std_lib_facilities.h"

int main()
try{
    string s = "Success!\n";
    for(int i = 0; i <9;++i) cout<<s[i];
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