#include "../../../std_lib_facilities.h"


void quad_roots(double a, double b, double c)
{
    double sq_root = b*b - 4*a*c;
    if(sq_root < 0) error("Error: no real roots exist");
    
    vector<double> roots(2); // Vector to store roots

    roots[0] = (-b - sqrt(sq_root)) / (2*a);
    roots[1] = (-b + sqrt(sq_root)) / (2*a);
    
    cout<<"The roots are: "<<roots[0]<<" and "<<roots[1];
}


int main()
{
    quad_roots(2,5,-3);
}