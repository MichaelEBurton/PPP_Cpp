/*
    Write a function that given two vector<double> s price and weight computes a value that is the sum of all price[i]*weight[i].
    Make sure to have weight.size()==price.size()
*/

#include "../../../std_lib_facilities.h"

double total_price(const vector<double>& price, const vector<double>& weight)
{
    if(price.size() != weight.size()) error("Differing vector legnths");

    double total = 0;
    for(int i = 0; i < price.size(); ++i)
    {
        total = total + price[i]*weight[i];
    }

    return total;
}

int main() 
try {
    
    vector<double> p = {2.00, 4.00,20.00,5.00};

    vector<double> w = {10, 1, 1, 4};

    cout<<total_price(p, w)<<'\n';

    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops! Unknown exception!";
    return 2;
}