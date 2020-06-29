
#include "../../../std_lib_facilities.h"

void print_until_s(vector<string>& v, string quit)
{
    for(string s:v){
        if(s == quit) return;
        cout<<s<<'\n';
    }
}

void print_until_ss(vector<string>& v, string quit)
{
    int quits = 0;
    for(string s:v){
        if(s == quit) ++quits;
        if(quits == 2) return;
        cout<<s<<'\n';
    }
}

int main()
try
{
    string quit = "quit";

    vector<string> v = {"one", "two", "three", "quit"};
    print_until_s(v, quit);

    vector<string> v2 = {"quit", "two", "three", "four"};
    print_until_s(v2, quit);

    vector<string> v3 = {"one", "two", "quit", "four"};
    print_until_s(v3, quit);

    vector<string> v4 = {"one", "quit", "three", "four", "five", "quit", "seven"};
    print_until_ss(v4, quit);
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops! Unknown exception.";
    return 2;
}
