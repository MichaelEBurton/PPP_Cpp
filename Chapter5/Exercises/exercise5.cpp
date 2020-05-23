#include "../../../std_lib_facilities.h"

double ctok(double c)
{
    constexpr double absolute_zero = -273.15;
    if(c < absolute_zero) error("error: Temperature given is below absolute zero");
    double k = c + 273.15;
    return k;
}

double ktoc(double k)
{
    if(k < 0) error("error: Temperature given is below absolute zero");
    double c = k - 273.15;
    return c;
}

int main()
{
    double c = 0;
    cin>>c;
    double k = ctok(c);
    cout<<k<<'\n'
        <<ktoc(k)<<'\n';
}