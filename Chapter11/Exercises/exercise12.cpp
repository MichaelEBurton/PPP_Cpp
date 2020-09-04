/*
    Exercise 12: Reverse the order of characters in a text file. For example, asdefghijkl becomes lkjihgfedcba. Warning:
                 there is no really good, portable, and efficient way of reading a file backward.
                
*/

#include "../../../std_lib_facilities.h"

vector<string> read_file(ifstream& is)
// Put each line into it's own string
{
    vector<string> lines;

    while(!is.eof())
    {
        string s;
        getline(is, s);

        lines.push_back(s);
    }
    return lines;
}

string reverse_string(string& s)
{
    string st;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        st += s[i];
    }
    return st;
}

vector<string> reverse(const vector<string>& s)
{
    vector<string> r;
    for(int i = s.size() - 1; i >= 0; --i)
    {   
        string rev_this = s[i];
        string rev = reverse_string(rev_this);
        r.push_back(rev);
    }
    return r;
}

//===================================================================================================================================
// File names
string get_input_file()
{
    string iname;
    cout<<"What is the name of the file you wish to read: ";
    cin>>iname;

    return iname;
}

string get_output_file()
{
    string oname;
    cout<<"\nWhat is the name of the file you wish to write: ";
    cin>>oname;

    return oname;
}

//===================================================================================================================================

int main()
try{
    
    string iname = get_input_file();
    ifstream ist{iname};
    if(!ist) error("Cannot open file ", iname);

    string oname = get_output_file();
    ofstream ost{oname};
    if(!ost) error("Cannot open file ", oname);

    vector<string> lines = read_file(ist);
    vector<string> reversed = reverse(lines);

    for(int i = 0; i< reversed.size(); ++i)
        ost<<reversed[i]<<'\n';


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