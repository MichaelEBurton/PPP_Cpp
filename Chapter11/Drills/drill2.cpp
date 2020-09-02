/*
    Output your birth_year in decimal, hexadecmial, and octal form.
*/

#include "../../../std_lib_facilities.h"

int birth_year;

int main()
{
    cout<<"Please enter your birth year: ";
    cin>>birth_year;
    cout<<'\n';

    cout<<'\n'
        <<birth_year<<"\t"<<"decimal\n"
        <<hex<<birth_year<<"\t"<<"hexadecimal\n"
        <<oct<<birth_year<<"\t"<<"octal\n";
}