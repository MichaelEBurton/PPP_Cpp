/*
    Go back to 2 and cause your output to show the base for each output.
*/

#include "../../../std_lib_facilities.h"

int birth_year;
int age;

int main()
{
    cout<<"Please enter your birth year: ";
    cin>>birth_year;
    cout<<'\n';

    cout<<showbase<<'\n'
        <<birth_year<<"\t"<<"decimal\n"
        <<hex<<birth_year<<"\t"<<"hexadecimal\n"
        <<oct<<birth_year<<"\t"<<"octal\n";

    cout<<"Please enter your age: ";
    cin>>age;
    cout<<'\n';

    cout<<dec<<age<<'\n';
}