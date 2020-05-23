#include "../../../std_lib_facilities.h"

int area(int x, int y)
{
    return x*y;
}

int main()
{
    int x = -1;
    int y = 2;
    int area1 = area(x,y);
    if(area1 <0) error("Bad area");
}