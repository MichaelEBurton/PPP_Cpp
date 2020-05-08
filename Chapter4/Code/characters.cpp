// Use a loop to write out a table of characters
//  with their corresponding integer values.

#include "../../../std_lib_facilities.h"

int main()
{
    int i = 0;  // initialize control variable

    while(i < 26)
    {
        cout<<char('a' + i)<<"\t"<<int('a' + i)<<"\n";
        ++i;   // increment the loop variable i
    }
}