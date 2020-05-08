// Use a loop to write out a table of characters
//  with their corresponding integer values.

#include "../../../std_lib_facilities.h"

int main()
{
    for(int i = 0;i < 26; ++i)
    {
        cout<<char('A' + i)<<"\t"<<int('A' + i)<<"\t"<<char('a' + i)<<"\t"<<int('a' + i)<<"\n";
    }
}