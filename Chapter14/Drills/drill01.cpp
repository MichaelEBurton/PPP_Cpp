/*
    1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class B1. Implement each function to output its name (e.g. B1::vf()). Make
       the functions public. Make a B1 object and call each function.
*/

#include "../../../std_lib_facilities.h"

class B1 {
    public: 
        B1() {};

        virtual void vf() const {cout << "B1::vf()";}
        void f() const {cout << "B1::f()";}
};

int main()
{
    B1 b;

    b.vf();
    cout<<'\n';
    b.f();
}