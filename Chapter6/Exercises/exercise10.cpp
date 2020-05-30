#include "../../../std_lib_facilities.h"

int factorial(int x){
    if(x < 0) error("Bad Argument: Negative Integer");
    int y = x;
    if(x == 0)
        return 1;
    return y*factorial(x - 1);
}

int permutation(int a, int b){
    int numerator = factorial(a);
    int denominator = factorial(a - b);
    return numerator/denominator;
}

int combination(int a, int b){
    int num = permutation(a,b);
    int denom = factorial(b);
    return num/denom;
}

int main()
try {
    int a,b;
    cout<<"Please enter two integers:\n";
    cin>>a>>b;
    
    char ch;
    cout<<"Would you like to calculate a permutation (p) or combination (c)";
    cin>>ch;

    int res = 0;
    if(ch == 'p'){
        res = permutation(a,b);
        cout<<"The number of permutations is: "<< res<<'\n';
    }
    else if(ch = 'c'){
        res = combination(a,b);
        cout<<"The number of combinations is: "<< res<<'\n';
    }
    else {
        cout<<"Unknown option";
    }
    return 0;
}
catch(exception& e){
    cerr<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops: Uknown exception!";
    return 2;
}