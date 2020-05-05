// This file converts miles to kilometers

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter a distance in miles\n";
    double miles;
    cin>>miles;
    cout<<"Your distance ("<<miles<<" miles) is the same as "<<miles*1.609<<" kilometers";
}