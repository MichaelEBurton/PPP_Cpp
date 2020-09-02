/*
    Label each value with the name of the base used.
    > Already implemented this is drill 2.
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