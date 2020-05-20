//Error: For loop should have curly brackets containing the code to execute
//Error: Results in an infinite loop 0 should be i
#include "../../../std_lib_facilities.h"

int main()
try{
    vector<char> v(5);
    for(int i=0; i < v.size(); ++i){
        cout<<"Success!\n";
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