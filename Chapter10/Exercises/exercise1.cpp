/*
    Write a program that produces the sum of all the numbers in a file of whitespace separated integers.
*/

#include "../../../std_lib_facilities.h"

int main()
try
{
    string iname;
    cout<<"Please enter a file name: ";
    cin>>iname;

    ifstream ist{iname};
    if(!ist) error("Can't open file ", iname);

    int s = 0;
    for(int i; ist>>i;)
        s += i;

    cout<<"The sum of integers in "
        <<iname
        <<" is "
        <<s<<'\n';

    return 0;
} 
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops unknown exception!";
    return 2;
}