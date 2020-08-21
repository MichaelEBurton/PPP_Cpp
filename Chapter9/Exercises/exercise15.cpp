/*
    Author: Michael Burton

    Purpose: Refine the Money class by adding a currency (given as a constructor argument). Accept
               a floating-point initializer as long as it can be represented as a long int. Don't accept
               illegal operations. For example, Money*Money doesn't make sense, and USD1.23+DKK5.00 makes 
               sense only if you provide a conversion table defining the conversion factor between USD and 
               DKK.

    Edited:  8/21/20 

    Notes: Chose not to implement addition or subtraction of currency.

*/

//money.h
#include "../../../std_lib_facilities.h"

class Money {
public:
    Money(long int, string);
    Money() {};

    //modifying operations



    //non-modifying operations
    int cents() const;
    int dollars() const;
    string currency() const {return curr;}

private:
    long int m;    
    string curr;
};

// Arithmetic Operations

Money operator*(Money& a, Money& b);
Money operator/(Money& a, Money &b);

// Logical Operations
bool operator==(const Money& a, const Money& b);
bool operator!=(const Money& a, const Money& b);

// Output and Input operations.

ostream& operator<<(ostream& os, const Money& m);  
istream& operator>>(istream& is, Money& m);

bool in_curr_table(string s);

//===================================================================================================================
//money.cpp

Money::Money(long int mm, string cc)
: m{mm}, curr{cc}
{
    if(!in_curr_table(cc)) error("Unknown currency table");
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

Money operator*(Money& a, double& d)
{
    return Money(round((a.dollars() * 100 + a.cents()) * d), a.currency());
}

Money operator/(Money& a, double &d)
{
    return Money(round((a.dollars() * 100 + a.cents())/d),a.currency());
}

// Logical Operations
bool operator==(const Money& a, const Money& b)
{
    return a.dollars() == b.dollars() &&
           a.cents() == b.cents() &&
           a.currency() == b.currency();
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
            return os<<"("
                     <<m.currency()
                     <<-1*m.dollars()
                     <<".0"
                     <<-1*m.cents()
                     <<")";
        }
        else 
        {
            return os<<"("
                    <<m.currency()
                    <<-1*m.dollars()
                    <<"."
                    <<-1*m.cents()
                    <<")";
        }
    }

    if(m.cents() < 10)
        {
            return os<<m.currency()
                     <<m.dollars()
                     <<".0"
                     <<m.cents()
                     <<"";
        }
    
    return os<<m.currency()
             <<m.dollars()
             <<"."
             <<m.cents();
}  

istream& operator>>(istream& is, Money& m)
{
    int d,c;
    string s;
    char a;

    is>>s>>d>>a>>c;
    if(!is) return is;
    if(a != '.' || !in_curr_table(s))             // Oops: format error
    {
     is.clear(std::ios_base::failbit);   // set the fail bit
     return is;
    }

    m = Money(d*100 + c, s);               //update m

    return is;
}

//This is not meant to be a representative list of world currencies
vector<string> curr_table = {"AUD", "GBP", "EUR", "JPY", "CHF", "USD", "ARS", "BTN", "CAD",
                             "CNY", "CUP", "DKK"};

bool in_curr_table(string s)
{
    for(int i = 0; i < curr_table.size(); ++i)
    {
        if(s == curr_table[i]) return true;
    }
    return false;
}

//=============================================================================================================================
//main.cpp

int main()
try {
    Money a, b;
    
    cout<<"Please enter a money amount (USD 1.23)"<<'\n';
    cin>>a;
    
    cout<<"Please enter a money amount (USD 1.23)"<<'\n';
    cin>>b;

    double c;
    cout<<"Please enter a double"<<'\n';
    cin>> c;

    cout<<"You entered: "<<a<<", "<<b<<" and "<<c<<'\n';

    
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