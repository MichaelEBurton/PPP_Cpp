/*
    1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class B1. Implement each function to output its name (e.g. B1::vf()). Make
       the functions public. Make a B1 object and call each function.

    2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf() and f() for it.
*/

#include "../../../std_lib_facilities.h"

class B1 {
    public: 
        B1() {};

        virtual void vf() const {cout << "B1::vf()";}
        void f() const {cout << "B1::f()";}
};

struct D1 : B1 {
    void vf() const {cout << "D1::vf()";}
};

int main()
{
    B1 b;

    b.vf();
    cout<<'\n';
    b.f();
    cout<<'\n';

    D1 d;
    d.vf();
    cout<<'\n';
    d.f();
}