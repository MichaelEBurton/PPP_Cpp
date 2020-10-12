/*
    1. Define a class B1 with a virtual function vf() and a non-virtual function f(). Define both of these functions within class B1. Implement each function to output its name (e.g. B1::vf()). Make
       the functions public. Make a B1 object and call each function.

    2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf() and f() for it.

    3. Define a reference to B1 (a B1&) and initialize that to the D1 object you just defined. Call vf() and f() for that reference.

    4. Now define a function called f() for D1 and repeat 1-3. Explain the results.
        > The function calls for the B1 type object still have B1:: precede the respective functions
        > Now that D1 has an f() function the original B1::f() function is overridden.

    5. Add a pure virtual function pvf() to B1 and try to repeat 1-3. Explain the results.
        > None of the previous exercise will run because they will result in trying to create an abstract object.

    6. Define a class D2 derived from D1 and override pvf() in D2. Make an object of class D2 and invoke f(), vf(), and pvf() for it.



*/

#include "../../../std_lib_facilities.h"

class B1 {
    public: 
        B1() {};

        virtual void vf() const {cout << "B1::vf()";}
        void f() const {cout << "B1::f()";}
        virtual void pvf() const =0;
};

struct D1 : B1 {
    void vf() const {cout << "D1::vf()";}
    void f() const {cout<<"D1::f()";}
};

struct D2 : D1 {
    void pvf() const {cout<<"D2::pvf()";}
};

int main()
{
    /*B1 b;

    b.vf();
    cout<<'\n';
    b.f();
    cout<<'\n';

    D1 d;
    d.vf();
    cout<<'\n';
    d.f();
    cout<<'\n';

    B1& b2{d};
    b2.vf();
    cout<<'\n';
    b2.f();
    cout<<'\n';
    */

    D2 d2;
    d2.f();
    cout<<'\n';
    d2.vf();
    cout<<'\n';
    d2.pvf();
    cout<<'\n';

}