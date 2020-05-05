#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Pleas enter an integer number: \n";

    int num;

    cin>>num;

    if (num % 2 == 0)
        cout<<"The value "<<num<<" is an even number.";
    else
        cout<<"The value "<<num<<" is an odd number";
}