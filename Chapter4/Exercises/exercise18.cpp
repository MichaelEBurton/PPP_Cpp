// Doesn't handle imaginary numbers
#include "../../../std_lib_facilities.h"

int main()
{
    double a;
    double b;
    double c;

    cout<<"Please enter the coefficients of the quadratic equation you wish to find the roots of (ax^2 + bx + c): \n"
        <<"a: ";
    cin>>a;
    cout<<"\n"<<"b: ";
    cin>>b;
    cout<<"\n"<<"c: ";
    cin>>c;
    cout<<"\n";

    cout<<"The roots for your equation are:"<<(-b - sqrt(b*b - 4*a*c)) / (2*a)
        <<" and "<<(-b + sqrt(b*b - 4*a*c)) / (2*a);
}