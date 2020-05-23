#include "../../../std_lib_facilities.h"

int area(int length, int width)
{
    if(length <=0 || width <= 0) return -1;
    return length*width;
}

int framed_area(int x, int y)
{
    constexpr int frame_width = 2;
    if(x-frame_width<=0 || y-frame_width<=0)
        error("non-positive area() argument called by framed_area()");
    return area(x-frame_width, y-frame_width);
}

void f(int x, int y, int z)
{
    int area1 = area(x,y);
    if(area1<=0) error("non-positive area");
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;

    cout<<"Area 1: "<<area1<<"\n"
        <<"Area 2: "<<area2<<"\n"
        <<"Area 3: "<<area3<<"\n"
        <<"Ratio: "<<ratio<<"\n";
}

int main()
{
    //f(3,-1,1);
    //f(-3,1,7);
    //f(3,1,-6);
    //f(1,2,2);
}