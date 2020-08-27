/*
    Define a Roman_int class for holding Roman numerals (as ints) with a << and >>. Provide Roman_int with an as_int() member that returns the
    int value, so that if r is a Roman_int, we can write cout<<"Roman"<<r<<"equals"<<r.as_int()<<'\n';
*/

#include "../../../std_lib_facilities.h"

class Roman_int {
public:
    Roman_int() {};
    Roman_int(string rn)
        : r{rn}
    {
    }
    string as_numeral() const {return r;}
    int as_int();

private:
    string r;

};

ostream& operator<<(ostream& os, Roman_int& rn);
istream& operator>>(istream& is, Roman_int& rn);

//====================================================================================

vector<char> numerals = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
vector<int> values = {1, 5, 10, 50, 100, 500, 1000};

int numeral_to_int(char n)
{
    for(int i = 0; i < numerals.size(); ++i)
    {
        if(n == numerals[i]) return values[i];
    }

    error("Bad Numeral");
}

int Roman_int::as_int()
{
    vector<char> char_numerals;

    for(char c:r)
        char_numerals.push_back(numeral_to_int(c));

    int sum = 0;
    int begin = char_numerals.size() - 1;  

    for(int i = begin; i >= 0; --i) // Parse the numeral from right to left
    {
        if(i == begin) sum += char_numerals[i];
        else
        {
            if(char_numerals[i] < char_numerals[i + 1]) sum -= char_numerals[i];
            else sum += char_numerals[i];
        }
        
    }

    return sum;
}

bool valid_numeral(char c) 
{
    for(char h:numerals)
    {
        if(c == h) return true;
    }
    return false;
            
}
ostream& operator<<(ostream& os, Roman_int& rn)
{
    return os<<rn.as_numeral()<<" is "<<rn.as_int();
}

istream& operator>>(istream& is, Roman_int& rn)
{
    string s;
    is>>s;
    for(char c:s)
        if(!valid_numeral(c)) error("Invalid numeral");
    
    rn = Roman_int{s};
    return is;
}

int main()
{
    Roman_int r;
    cout<<"Please enter a roman numeral: \n";
    cin>>r;

    cout<<r;
}