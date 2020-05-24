// The 46th term in the sequence is the largest that can fit into an integer type (1836311903)
#include "../../../std_lib_facilities.h"

int main()
try{
    int no_to_show = 0;
    cout<<"How many numbers in the sequence of fibonacci numbers would you like to see? ";
    cin>>no_to_show;

    vector<int> fibonacci;
    for(int i = 0; i < no_to_show;++i){
        if(i == 0 || i == 1){
            fibonacci.push_back(1);
        } 
        else {
            fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);
        }
        if(i < no_to_show - 1) cout<<fibonacci[i]<<", ";
        else cout<<fibonacci[i];
    }
    return 0;
}
catch(exception& e){
    cerr<<"error: "<<e.what()<<'\n';
    return 1;
}
catch(...){
    cerr<<"Oops: unknown exception!\n";
    return 2;
}