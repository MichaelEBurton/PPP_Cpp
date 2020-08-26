/*
    Print the data in original_points to see what it looks like.
*/

#include "../../../std_lib_facilities.h"

struct Point {
    double x;
    double y;
};

istream& operator>>(istream& is, Point& p)
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

    char ch2;
    char ch3;
    double xx;
    double yy;
    is>>xx>>ch2>>yy>>ch3;

    p.x = xx;
    p.y = yy;
    return is;
}

ostream& operator<<(ostream& os, Point& p)
{
    return os<<'('<<p.x<<','<<p.y<<')';
}

int main()
{
    int n = 7;
    vector<Point> original_points;
    cout<<"Please enter "<<n<<" (x,y) pairs: \n";

    while(original_points.size() < n)
    {
        Point p;
        cin>>p;
        original_points.push_back(p);
    }

    for(int j = 0; j < original_points.size(); ++j)
    {
        cout<<original_points[j]<<'\n';
    }
}