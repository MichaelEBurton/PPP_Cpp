//Error: Infinite loop because we forgot curly brackets
//Error: Infinite loop because i is always less than 10 change to ++i
#include "../../../std_lib_facilities.h"

int main()
try{
    int i = 0;
    int j = 9;
    while(i<10) {
        ++i;
        if(j < i) cout<<"Success!\n";
    }
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