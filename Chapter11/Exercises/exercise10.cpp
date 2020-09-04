/*
    Exercise 10: Write a function vector<string> split(const string& s) that returns a vector of whitespace-separated
                substrings from the argument s, where whitespace is defined as ordinary whitespace
*/

#include "../../../std_lib_facilities.h"

vector<string> split(const string& s)
{
    vector<string> r;

    istringstream ss{s};

    for(string st; ss>>st;)
    {
        r.push_back(st);
    }

    return r;
}

int main()
try{
    string s;
    cout<<"Type your favorite sentence:\n";
    getline(cin, s);

    vector<string> s_split = split(s);

    cout<<"Your sentence contains the following substrings: \n";
    for(int i = 0; i < s_split.size(); ++i)
        cout<<s_split[i]<<'\n';
    
    return 0;
}
catch(exception& e)
{
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops, unknown error!";
    return 2;
}