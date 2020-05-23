// Really large values break the post-condition

#include "../../../std_lib_facilities.h"

int area(int length, int width)
{
    if(length <=0 || width <= 0) error("area() pre-condition");
    int a = length*width;
    if(a<=0) error("area() post-condition");
    return a;
}

int main()
{
    int area2 = area(100000000,10000000);
    cout<<"area = "<<area2<<'\n';
}