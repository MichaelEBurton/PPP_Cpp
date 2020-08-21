/*
    Author: Michael Burton

    Purpose: Design and implement a Money class for calculations involving dollars and cents
               where arithmetic has to be accurate to the last cent using the 4/5 rounding 
               rule (.5 cent rounds up; anything less than .5 rounds down). Represent a monetary
               amount as a number of cents in a long int but input and output as dollars and cents, 
               e.g., $123.45. Do not worry about amounts that don't fit into a long int.

    Edited:  8/21/20 

*/

//money.h
#include "../../../std_lib_facilities.h"

class Money {
public:
    Money(long int);
    Money() {};

    //modifying operations



    //non-modifying operations
    int cents() const;
    int dollars() const;

private:
    long int m;    
};

// Arithmetic Operations
Money operator+(Money& a, Money& b);
Money operator-(Money& a, Money& b);
Money operator*(Money& a, Money& b);
Money operator/(Money& a, Money &b);

// Logical Operations
bool operator==(const Money& a, const Money& b);
bool operator!=(const Money& a, const Money& b);

// Output and Input operations.

ostream& operator<<(ostream& os, const Money& m);  
istream& operator>>(istream& is, Money& m);


//===================================================================================================================
//money.cpp

Money::Money(long int mm)
: m{mm}
{
}

int Money::dollars() const
{
    return m / 100;
}

int Money::cents() const
{
    return m % 100;
}

// Arithmetic Operators

Money operator+(Money& a, Money& b)
{
    long int aa = a.dollars() * 100 + a.cents();
    long int bb = b.dollars() * 100 + b.cents();

    return Money(aa + bb);
}

Money operator-(Money& a, Money& b)
{
    long int aa = a.dollars() * 100 + a.cents();
    long int bb = b.dollars() * 100 + b.cents();

    return Money(aa - bb);
}

Money operator*(Money& a, double& d)
{
    return Money(round((a.dollars() * 100 + a.cents()) * d));
}

Money operator/(Money& a, double &d)
{
    return Money(round((a.dollars() * 100 + a.cents())/d));
}

// Logical Operations
bool operator==(const Money& a, const Money& b)
{
    return a.dollars() == b.dollars() &&
           a.cents() == b.cents();
}

bool operator!=(const Money& a, const Money& b)
{
    return !(a==b);
}

// Output and Input operations.

ostream& operator<<(ostream& os, const Money& m)
{
    string s;
    if(m.dollars() < 0 || m.cents() < 0)
    {
        if(-1*m.cents() < 10)
        {
            return os<<"($"
                     <<-1*m.dollars()
                     <<".0"
                     <<-1*m.cents()
                     <<")";
        }
        else 
        {
            return os<<"($"
             <<-1*m.dollars()
             <<"."
             <<-1*m.cents()
             <<")";
        }
    }

    if(m.cents() < 10)
        {
            return os<<"$"
                     <<m.dollars()
                     <<".0"
                     <<m.cents()
                     <<"";
        }
    
    return os<<"$"
             <<m.dollars()
             <<"."
             <<m.cents();
}  

istream& operator>>(istream& is, Money& m)
{
    int d,c;
    char a,b;

    is>>a>>d>>b>>c;
    if(!is) return is;
    if(a != '$' || b != '.')             // Oops: format error
    {
     is.clear(std::ios_base::failbit);   // set the fail bit
     return is;
    }

    m = Money(d*100 + c);               //update m

    return is;
}

//=============================================================================================================================
//main.cpp

int main()
try {
    Money a, b;
    
    cout<<"Please enter a money amount ($1.23)"<<'\n';
    cin>>a;
    
    cout<<"Please enter a money amount ($1.23)"<<'\n';
    cin>>b;

    double c;
    cout<<"Please enter a double"<<'\n';
    cin>> c;

    cout<<"You entered: "<<a<<", "<<b<<" and "<<c<<'\n';

    cout<<a<<" + "<<b<<" = "<<a+b<<'\n';
    cout<<a<<" - "<<b<<" = "<<a-b<<'\n';
    cout<<a<<" * "<<c<<" = "<<a*c<<'\n';
    cout<<a<<" / "<<c<<" = "<<a/c<<'\n';

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