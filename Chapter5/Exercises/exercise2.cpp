//ctok should return k not "int"
// Missing semicolon after return k
// cin>>d should be cin>>c
// Invalid argument passed to ctok shoudl be c not "c"
// Cout shouls be all lowercase

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
    double k = ctok(c);
    cout<<k<<'\n';
}