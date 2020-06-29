/*
    Write a function that takes a vector<string> argument and returns a vector<int> containing the number of characters in each string.
    Also find the longest and the shortest string and the lexicographically first and last string. How many separate functions 
    would you use for these tasks?

    Notes: I think we should write five functions since these are each distinct tasks. The last two tasks could probably be done in two 
             functions, but the user experience wouldn't be that great, so I've made separate functions. If I know more about structs 
             that might be useful to create less functions.


*/
#include "../../../std_lib_facilities.h"

vector<int> num_of_characters(vector<string>& s)
{
    int min = 999999;
    int max = 999999;

    vector<int> characters;
    for(int i = 0; i < s.size(); ++i)
    {
        characters.push_back(s[i].length());
    }

    return characters;
}

string smallest_string(vector<int>& n, vector<string>& s)
{
    int index = 0;
    int length = 999999;

    for(int i = 0; i < n.size(); ++i)
    {
        if(n[i] < length)
        {
            length = n[i];
            index = i;
        }
    }
    return s[index];
}

string largest_string(vector<int>& n, vector<string>& s)
{
    int index = 0;
    int length = -999999;

    for(int i = 0; i < n.size(); ++i)
    {
        if(n[i] > length)
        {
            length = n[i];
            index = i;
        }
    }
    return s[index];
}

string first_string(vector<string> s)
{
    sort(s);
    return s[0];
}

string last_string(vector<string> s)
{
    sort(s);
    return s[s.size() - 1];
}

int main()
try
{
    vector<string> test = {"United States", "Canada", "United Kingdom", "Zimbabwe",
                           "Germany", "Peru", "Thailand", "Pakistan"};

    vector<int> n_characters = num_of_characters(test);

    cout<<"Smallest string: "<<smallest_string(n_characters, test)<<'\n'
        <<"Largest string: "<<largest_string(n_characters, test)<<'\n'
        <<"First string: "<<first_string(test)<<'\n'
        <<"Last string: "<<last_string(test)<<'\n';
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
