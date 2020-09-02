/*
    Output your birth year in decimal, hexadecimal, and octal form. Label each value. Line up your output in columns
    using the tab character. Now output your age
*/

#include "../../../std_lib_facilities.h"

int main()
{
    int birth_year;
    cout<<"Please enter your year of birth: ";
    cin>>birth_year;

    cout<<'\n'
        <<birth_year<<"\t"<<"decimal\n"
        <<hex<<birth_year<<"\t"<<"hexadecimal\n"
        <<oct<<birth_year<<"\t"<<"octal\n";

}