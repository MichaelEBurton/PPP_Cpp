// When the number gets to large it is represented as -1.
#include "../../../std_lib_facilities.h"

int main()
{
    int current = 1;
    double rice_all = 0.0;
    int all_rice = 0;

    for(int i = 1; i <= 64; ++i){
        all_rice += current;
        rice_all += current;
        current *= 2;
        cout<<"Integer: "<<all_rice<<"\n";
        cout<<"Double: "<<rice_all<<"\n";
    }
}