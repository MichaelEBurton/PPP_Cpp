/*
    Exercise 6: Write a program that replaces punctuation with whitespace. Consider . (dot), ; (semicolon),
                , (comma), ? (question mark), - (dash), ' (single quote) punctuation characters. Don't modify
                characters within a pair of double quotes ("). For example,
                "- don't use the as-if rule." becomes "don t use the as if rule ".
*/

#include "../../../std_lib_facilities.h"

vector<char> punctuation = {'.', ';', ',', '?', '-', '\''};

bool is_punct(char c)
{
    for(int i = 0; i<punctuation.size(); ++i)
        if(c == punctuation[i]) return true;
    return false;
}

int main()
try
{
    string iname;
    cout<<"What is the name of the file you wish to read: ";
    cin>>iname;

    ifstream ist{iname};
    if(!ist) error("Cannot open file ", iname);

    string oname;
    cout<<"\nWhat is the name of the file you wish to write: ";
    cin>>oname;

    ofstream ost{oname};
    if(!ost) error("Cannot open file ", oname);

    while(!ist.eof())
    {
        string line;
        getline(ist, line);

        bool inquotes = false; // indicator if string currently enclosed in quotes
        for(char c:line)
        {
            if(inquotes) 
            // Do not alter text in quotes
            {
                ost<<c;
                if(c == '"') inquotes = false;  // end of double quotes
            }

            if(c == '"') inquotes = true; // if we encounter a double quote alter indicator variable
            if(is_punct(c)) ost<<' ';
            else ost<<c;
        }
        ost<<'\n';
    }
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