#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter a number from 0 to 9 spelled out (i.e. 'zero', 'two', etc.)\n";

    string str_num;

    cin>>str_num;

    if (str_num == "zero")
        cout<<"0";
    else if (str_num == "one")
        cout<<"1";
    else if (str_num == "two")
        cout<<"2";
    else if (str_num == "three")
        cout<<"3";
    else if (str_num == "four")
        cout<<"4";
    else if (str_num == "five")
        cout<<"5";
    else if (str_num == "six")
        cout<<"6";
    else if (str_num == "seven")
        cout<<"7";
    else if (str_num == "eight")
        cout<<"8";
    else if (str_num == "nine")
        cout<<"9";
    else
        cout<<"not a number I know\n";
    
}