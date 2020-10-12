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

    7. Define a class B2 with a pure virtual function pvf(). Define a class D21 with a string data member and a member function that overrides pvf(); D21::pvf() should output the value of the
       string. Define a class D22 that is just like D21 except that its data member is an int. Define a function f() that takes a B2& argument and calls pvf() for its argument. Call f() with a
       D21 and a D22. 

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
//===========================================================================================
class B2 {
    public:
        B2() {}

        virtual void pvf() const =0;
};

struct D21 : B2 {
    public: 
        void pvf() const {cout<<"D21::pvf()";}
        string s;
};

struct D22 : B2 {
    public:
        void pvf() const {cout<<"D22::pvf()";}
        int i;
};

void f(B2& b) {
    b.pvf();
}

int main()
{
    D21 d21;
    D22 d22;

    f(d21);
    cout<<'\n';
    
    f(d22);
    cout<<'\n';

}