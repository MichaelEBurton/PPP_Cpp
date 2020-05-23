#include "../../../std_lib_facilities.h"

double ctok(double c)
{
    int k = c + 273.15;
    return k;
}

int main()
{
    constexpr double absolute_zero = -273.15;
    double c = 0;
    cin>>c;
    if(c < absolute_zero) error("error: Temperature given is below absolute zero");
    double k = ctok(c);
    cout<<k<<'\n';
}