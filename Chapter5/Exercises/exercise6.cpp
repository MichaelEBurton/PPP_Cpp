#include "../../../std_lib_facilities.h"

double ftoc(double f)
{
    double c = (5/9)*f - 32;
    return c;
}

double ctof(double c)
{
    double f = (9/5)*c + 32;
    return f;
}

int main()
{
    double c = 0;
    cin>>c;
    double f = ctof(c);
    cout<<f<<'\n'
        <<ftoc(f)<<'\n';
}