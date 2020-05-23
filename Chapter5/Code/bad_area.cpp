#include "../../../std_lib_facilities.h"

class Bad_area{};

int area(int length, int width)
{
    if(length <=0 || width <= 0) throw Bad_area();
    return length*width;
}

int framed_area(int x, int y)
{
    constexpr int frame_width = 2;
    if(x-frame_width<=0 || y-frame_width<=0) throw Bad_area();
    return area(x-frame_width, y-frame_width);
}

int main()
try{
    int x=-1;
    int y=2;
    int z=4;
    //...
    int area1 = area(x,y);
    if(area1<=0) error("non-positive area");
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3; 
} 
catch(Bad_area){
    cout<<"oops! Bad area argument to area()\n";
}