/*
    Exercise 11: Write a function vector<string> split(const string& s, const string& w) that returns a vector of whitespace-separated
                 substrings from the argument s, where whitespace is defined as "ordinary whitespace" plus the characters in w

*/
#include "../../../std_lib_facilities.h"

vector<string> split(const string& s, const string& w)
{
    vector<string> r;

    string s2 = s;
    for(char& ch:s2)       // convert unusual whitespace to usual whitespace
    {
        for(char ws:w)
        {
            if(ch == ws) ch = ' ';
        }
    }
    istringstream ss{s2};

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

    string ws;
    cout<<"\nWhat characters would you like to use as whitespace: ";
    cin>>ws;

    vector<string> s_split = split(s, ws);

    cout<<"\nYour sentence contains the following substrings: \n";
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