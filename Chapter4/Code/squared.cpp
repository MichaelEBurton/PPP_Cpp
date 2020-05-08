#include "../../../std_lib_facilities.h"

int old_square(int x)
{
    int sum = 0;
    for(int i = 0; i < x; ++i)
    {
        sum += x;
    }
    return sum;
}

int main()
{
    for(int i = 0; i<100; ++i){
        cout<<i<<"\t"<<old_square(i)<<"\n";
    }
}