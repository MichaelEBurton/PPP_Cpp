//Error: Not sure if anything is wrong with this?
#include "../../../std_lib_facilities.h"

int main()
try{
    string s = "Success!\n";
    for(int i = 0; i<10;++i) cout<<s[i];
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