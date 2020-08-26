/*
    Using the code and discussion 10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a vector of Points
      called original_points.
*/

#include "../../../std_lib_facilities.h"

struct Point {
    double x;
    double y;
};

istream& operator>>(istream& is, Point p)
// read a point from is into p
// format (x , y)
// check format
{
    char ch1;
    if(is>>ch1 && ch1 !='(') {         // is this a point
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2, ch3;
    double x;
    double y;
    is>>x>>ch2>>y;
    if(is>>ch3 && ch3 !=')'){       // is this a point
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    p.x = x;
    p.y = y;
    return is;
}

int main()
{
    vector<Point> original_points{7};
    cout<<"Please input seven (x,y) pairs: \n";
    for(int i=0; i < 7; ++i)
    {
        Point p;
        cin>>p;
        original_points[i] = p;
    }

    
}