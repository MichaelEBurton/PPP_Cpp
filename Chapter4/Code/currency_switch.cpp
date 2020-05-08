#include "../../../std_lib_facilities.h"

int main()
{
    constexpr double dollars_per_yen = 0.0094;
    constexpr double dollars_per_kroner = 0.1;
    constexpr double dollars_per_pound = 1.24;

    double amount = 1;

    char unit = ' ';

    cout<<"Please enter a money amount followed by a currency (y [yen], k [kroner], or p [pounds])\n";
    cin>>amount>>unit;

    switch(unit){
        case 'y':
            cout<<amount<<" yen == $"<<dollars_per_yen*amount<<"\n";
            break;
        case 'k':
            cout<<amount<<" kroner == $"<<dollars_per_kroner*amount<<"\n";
        case 'p':
            cout<<amount<<" pounds == $"<<dollars_per_pound*amount<<"\n";
            break;
        default:
            cout<<"Sorry, I don't know a currency called "<<unit<<"'\n";

    }
}