/*
    Compare the two vectors and print Something's wrong! if the number of elements or 
    the values of elements differ
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

string something_wrong(vector<Point>& a, vector<Point>& b)
{
    string w = "Something's wrong!";

    if(a.size() != b.size()) return w;
    for(int i = 0; i < a.size(); ++i)
    {
        if(a[i].x != b[i].x || a[i].y != b[i].y) return w;
    }

    return "";
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

    ost.close(); // close the ofstream

    //Read the data from mydata.txt and store it in a new vector called processed_points.
    ifstream ist{oname};
    if(!ist) error("Can't open file", oname);
    vector<Point> processed_points;

    Point p;
    while(ist>>p) {
        processed_points.push_back(p);
    }


    cout<<something_wrong(original_points,processed_points);
}