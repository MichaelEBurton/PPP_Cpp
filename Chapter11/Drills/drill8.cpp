/*
    Try reading as octal, hexadecimal, etc.
        1234 1234 1234 1234
    Explain the results. Try other inputs to see what happens.

    Results: When you enter 1234 1234 1234 1234 you receive the following output - 1234 4660 668 668
             This is to be expected since we are assuming we have a decimal number followed by a hexadecimal number
             and two octal numbers.

             1234 decimal
             1234 hexadecimal = 1*16^3 + 2*16^2 + 3*16 + 4*16^0 = 4660
             1234 octal = 1*8^3 + 2*8^2 + 3*8 + 4*8^0 = 668
             
*/

#include "../../../std_lib_facilities.h"

int main()
{
    int a;
    int b;
    int c;
    int d;

    cout<<"Enter four integers (decimal hexadecmial octal octal):\n";
    cin>>a>>oct>>b>>hex>>c>>d;
    cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<'\n';
}