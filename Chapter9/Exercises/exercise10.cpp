#include "../../../std_lib_facilities.h"


bool leapyear(int y)
{
    // see exercise 10
    if(y % 4) return false;
    if(y % 100 == 0 && y % 400 == 0) return false;
    return true;
}

int main()
{
    int y = 2000;

    vector<int> years;

    for(int i = 0; i <= 16; ++i){
        years.push_back(y);
        ++y;
    }

    for(int i = 0; i < years.size();++i){
        if(leapyear(years[i]))
            cout<< years[i] <<" is a leap year!\n";
    }
}