/*
    Make a simple table including the last name, first name, telephone number, and email address for yourself and at least five 
    of your friends. Experiment with different field widths until you are satisfied that the table is well presented.
*/

#include "../../../std_lib_facilities.h"

int main()
{
    cout<<setw(7)<<"John"<<'|'<<setw(7)<<"Doe"<<'|'<<"(123) 456-7892"<<'|'<<"jdoe7@hotmail.com\n"
        <<setw(7)<<"William"<<'|'<<setw(7)<<"Gates"<<'|'<<"(425) 745-1432"<<'|'<<"WGat3$@microsoft.com\n"
        <<setw(7)<<"Mary"<<'|'<<setw(7)<<"Shelley"<<'|'<<"(674) 958-9722"<<'|'<<"FrShell@aol.com\n"
        <<setw(7)<<"Carl"<<'|'<<setw(7)<<"Gauss"<<'|'<<"(777) 544-7012"<<'|'<<"carl.gauss@stat.edu\n"
        <<setw(7)<<"Carrie"<<'|'<<setw(7)<<"Carter"<<'|'<<"(243) 779-8391"<<'|'<<"ccarte8@netscape.com\n";
}