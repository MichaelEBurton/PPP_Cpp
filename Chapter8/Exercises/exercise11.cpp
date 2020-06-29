/*
    Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the median.
      Do not use global variables. Either reutrn a struct containing the results or pass them back through reference aguments.

    Edited: 6/29/20

    Notes: Not the best program... I don't know anything about structs so I was had to use reference arguments that still require 
             global variables. I didn't want to assume that the user would put in a sorted vector so I sort it in the function. The
             downside of this is that it alters the vector itself through a pass-by-reference. I think this could be implemented better.
*/
#include "../../../std_lib_facilities.h"

void vector_stuff(vector<double>& v, double& max, double & min, double& mean, double& median)
{
    sort(v);

    double mx = -999999;
    double mn = 999999;

    int total = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] > mx) mx = v[i];
        if(v[i] < mn) mn = v[i];

        total += v[i];
    }

    double mea = total/v.size();

    double med = 0;
    if(v.size() % 2 == 0) 
        med = v[v.size()/ 2] + v[v.size()/2 + 1];
    else 
    {
        med  = v[(v.size() + 1) / 2];
    }

    max = mx;
    min = mn;
    median = med;
    mean = mea;
}

int main()
try{

    vector<double> v = { 1, 2, 3, 400, 500, 6, 7, 9, 10};

    double max = 0;
    double min = 0;
    double mean = 0;
    double median = 0;

    vector_stuff(v, max, min, mean, median);

    cout<<"Min: "<<min<<'\n'
        <<"Median: "<<median<<'\n'
        <<"Mean: "<<mean<<'\n'
        <<"Max: "<<max<<'\n';   

    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops! Unknown exception.";
    return 2;
}