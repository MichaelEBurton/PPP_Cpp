// Prompt the user to enter three integer values and then output the values in 
//   numerical sequence separated by commas.
//
// Note: This program may be incomplete, it appears I do not have a strong grasp on conditionals in this language 

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter three integer values: ";

    int num1;
    int num2;
    int num3;

    cin>>num1>>num2>>num3;

    cout<<"\n";
    
    if (num1 == num2 && num2 == num3)
        cout<<num1<<", "<<num2<<", "<<num3;

    
    if(num2 == num1)
        if(num1 < num3)
            cout<<num1<<", "<<num2<<", "<<num3;
        else if(num1 > num3)
            cout<<num3<<", "<<num2<<", "<<num1;

    if(num2 == num3)
        if(num1 < num3)
            cout<<num1<<", "<<num2<<", "<<num3;
        else if(num1 > num3)
            cout<<num3<<", "<<num2<<", "<<num1;

    if(num1 == num3)
        if(num1 < num2)
            cout<<num1<<", "<<num3<<", "<<num2;
        else if(num1 > num2)
            cout<<num2<<", "<<num3<<", "<<num1;

    if (num1 < num2)
        if (num2 < num3)
            cout<<num1<<", "<<num2<<", "<<num3;
        else if (num3 < num2)
            if (num3 < num1)
                cout<<num3<<", "<<num1<<", "<<num2;
            else if (num1 < num3)
                cout<<num1<<", "<<num3<<", "<<num2;

    if (num2 < num1)
        if (num1 < num3)
            cout<<num2<<", "<<num1<<", "<<num3;
        else if (num3 < num1)
            if (num2 < num3)
                cout<<num2<<", "<<num3<<", "<<num1;
            else if (num3 < num2)
                cout<<num3<<", "<<num2<<", "<<num1;
}