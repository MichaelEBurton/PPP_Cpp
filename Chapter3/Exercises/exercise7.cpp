// Prompt the user to enter three string values and then output the values in 
//   alphabetical sequence separated by commas.
//
// Note: This program may be incomplete, it appears I do not have a strong grasp on conditionals in this language 

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter three integer values: ";

    string val1;
    string val2;
    string val3;

    cin>>val1>>val2>>val3;

    cout<<"\n";
    
    if (val1 == val2 && val2 == val3)
        cout<<val1<<", "<<val2<<", "<<val3;

    
    if(val2 == val1)
        if(val1 < val3)
            cout<<val1<<", "<<val2<<", "<<val3;
        else if(val1 > val3)
            cout<<val3<<", "<<val2<<", "<<val1;

    if(val2 == val3)
        if(val1 < val3)
            cout<<val1<<", "<<val2<<", "<<val3;
        else if(val1 > val3)
            cout<<val3<<", "<<val2<<", "<<val1;

    if(val1 == val3)
        if(val1 < val2)
            cout<<val1<<", "<<val3<<", "<<val2;
        else if(val1 > val2)
            cout<<val2<<", "<<val3<<", "<<val1;

    if (val1 < val2)
        if (val2 < val3)
            cout<<val1<<", "<<val2<<", "<<val3;
        else if (val3 < val2)
            if (val3 < val1)
                cout<<val3<<", "<<val1<<", "<<val2;
            else if (val1 < val3)
                cout<<val1<<", "<<val3<<", "<<val2;

    if (val2 < val1)
        if (val1 < val3)
            cout<<val2<<", "<<val1<<", "<<val3;
        else if (val3 < val1)
            if (val2 < val3)
                cout<<val2<<", "<<val3<<", "<<val1;
            else if (val3 < val2)
                cout<<val3<<", "<<val2<<", "<<val1;
}