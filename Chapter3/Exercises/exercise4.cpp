//Write your program to determine (for two integers):
//  The smaller, larger, sum, difference, product, and ratio
//  of these values and report them to the user.

#include "../../../std_lib_facilities.h"


int main()
{
    cout<<"Please enter two integers:\n";
    int val1;
    int val2;
    cin>>val1>>val2;

    if (val1 > val2)
        cout<<"The first integer you entered ("<<val1<<") is greater than the second integer ("<<val2<<").\n";

    else if (val2 > val1)
        cout<<"The second integer you entered ("<<val2<<") is greater than the first integer ("<<val1<<").\n";

    else if (val1 == val2)
        cout<<"Woah! You entered the same integer twice!\n";

    cout<<"The sum of your integers is: "<<val1<<" + "<<val2<<" = "<<val1 + val2<<"\n";
    cout<<"The difference of your integers is: "<<val1<<" - "<<val2<<" = "<<val1 - val2<<"\n";
    cout<<"The product of your integers is: "<<val1<<" * "<<val2<<" = "<<val1 * val2<<"\n";
    cout<<"The ratio of your integers is: "<<val1<<" / "<<val2<<" = "<<val1 / val2<<"\n";
}