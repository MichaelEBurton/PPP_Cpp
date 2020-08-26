/*
    Open an ofstream and output each point to a file named mydata.txt.
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

    string oname;
    cout<<"Please enter an output file name (mydata.txt)\n";
    cin>>oname;
    ofstream ost{oname};
    if(!ost) error("Can't open file ",oname);
    for(int j = 0; j < original_points.size(); ++j)
    {
        ost<<original_points[j]<<'\n';
    }
}