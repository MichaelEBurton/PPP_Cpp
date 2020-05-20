//Error: Condition resulted in dividng by 0
#include "../../../std_lib_facilities.h"

int main()
try{
    int x = 2;
    double d = 2*x+0.5;;
    if(d==2*x+0.5) cout<<"Success!\n";
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