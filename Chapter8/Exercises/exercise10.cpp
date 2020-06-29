
#include "../../../std_lib_facilities.h"

double vector_max(const vector<double>& v)
{
    double temp = v[0];

    for(int i = 1; i < v.size(); ++i)
    {
        if(v[i] > temp) temp = v[i];
    }

    return temp;
}

int main()
try{

    vector<double> v = { 1, 2, 3, 400, 500, 6, 7, 9, 10};

    cout<<vector_max(v);

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