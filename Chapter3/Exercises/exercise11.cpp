#include "../../../std_lib_facilities.h"

int main()
{
    int pennies;
    int nickels;
    int dimes;
    int quarters;
    int half_dollars;

    cout<<"How many pennies do you have? ";
    cin>> pennies;

    cout<<"\nHow many nickels do you have? ";
    cin>>nickels;

    cout<<"\nHow many dimes do you have? ";
    cin>>dimes;

    cout<<"\nHow many quarters do you have? ";
    cin>>quarters;

    cout<<"\nHow many half dollar coins do you have? ";
    cin>>half_dollars;

    cout<<"You have "<<pennies<<" pennies.\n"
        <<"You have "<<nickels<<" nickels.\n"
        <<"You have "<<dimes<<" dimes.\n"
        <<"You have "<<quarters<<" quarters.\n"
        <<"You have "<<half_dollars<<" half dollars.\n"
        <<"The value of all your coins is "<< pennies + (5*nickels) + (dimes*10) + (25*quarters) + (50*half_dollars)<<" cents.\n";

}