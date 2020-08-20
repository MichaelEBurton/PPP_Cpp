/*
    Design and implement a rational number class. 
      > Provide assignment, addition, subtraction, multiplication, division, and equality operators.
      > Also provide a conversion to double.

    Notes:
      > My implementation does not simplify rational numbers.
      > Rational numbers can only be operated on with anothe rational.
*/

#include "../../../std_lib_facilities.h"

//Rational.h
class Rational {
public:
    class Invalid {};
    Rational(int n, int d);

    //modifying operations
    


    // non-modifying operations
    int numerator() const {return num;}  // get numerator attribute
    int denominator() const {return denom;} // get denominator attribute;


private:
    int num;
    int denom;
}; 

Rational operator+(Rational& a, Rational& b);
Rational operator-(Rational& a, Rational& b);
Rational operator*(Rational& a, Rational& b);
Rational operator/(Rational& a, Rational& b);
bool operator==(const Rational& a, const Rational& b);
ostream& operator<<(ostream& os, Rational& a);

//=====================================================================================================================
// Rational.cpp
Rational::Rational(int nn, int dd)
    : num{nn}, denom{dd}
{
    if(dd <= 0) throw Invalid{};
    if(nn < 0) throw Invalid{};
}

Rational operator+(Rational& a, Rational& b)
{
 Rational r(a.numerator() * b.denominator() + b.numerator() * a.denominator(), b.denominator() * a.denominator());

 return r;
}

Rational operator-(Rational& a, Rational& b)
{
 Rational r(a.numerator() * b.denominator() - b.numerator() * a.denominator(), b.denominator() * a.denominator());

 return r;
}

Rational operator*(Rational& a, Rational& b)
{
    Rational r(a.numerator() * b.numerator(), a.denominator()*b.denominator());

    return r;
}

Rational operator/(Rational& a, Rational& b)
{
    Rational r(a.numerator() * b.denominator(), b.numerator() * a.denominator());

    return r;
}

bool operator==(const Rational& a, const Rational& b)
{
    return a.numerator()*b.denominator() == b.numerator() * a.denominator();
}

bool operator!=(const Rational& a, const Rational& b)
{
    return !(a == b);
}

double to_double(Rational& r)
{
    return double(r.numerator())/double(r.denominator());
}

ostream& operator<<(ostream& os, Rational& a)
{
    return os<<a.numerator()
             <<'/'
             <<a.denominator()
             <<'\n';
}

//=====================================================================================================================
int main()
try {
    Rational a(5,6);

    Rational b(10,12);

    if(a == b) cout<<"equal"<<'\n';
    else cout<<"not equal"<<'\n';

    Rational c = a + b;

    cout<<c<<'\n';

    Rational d = a/b;

    cout<<d<<'\n';

    double e = to_double(a);

    cout<<e<<'\n';

    return 0;
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops unknown exception!";
    return 2;
}

