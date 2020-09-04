/*
    Exercise 7: Modify the program from the previous exercise so that it replaces don't with do not, can't with cannot, etc.;
                leaves hyphens with words intact (so that we get " do not use the as-if rule "); and converts all characters 
                to lower case.

    Notes: Kind of messy, easily broken. Try placing anything directly after the end of a double quote (no whitespace)
*/

#include "../../../std_lib_facilities.h"
//===================================================================================================================================
// Contractions
vector<string> contractions = {"can't", "don't", "won't", "ain't", "wouldn't", "couldn't"};
vector<string> un_contracted = {"cannot", "do not", "will not", "is not", "would not", "could not"};

bool is_contraction(string& s)
{
    for(string ss:contractions)
        if(ss == s) return true;
    return false;
}

string un_contract(string s)
{
    if(!is_contraction(s)) error("Not a contraction");
    for(int i =0; i<contractions.size(); ++i)
        if(s == contractions[i]) return un_contracted[i];
    return "ERROR IN PROGRAM";
}
//===================================================================================================================================
// Hyphenated Words
bool contains_hyphen(string& s)
{
    for(char c:s)
    {
        if(c == '-')
        return true;
    }
    return false;
}

bool is_hyphenated(string& s)
{
    if(s == "-") return false;
    if(contains_hyphen(s))
    {
        if(s.size() > 1)
            if(s[s.size() - 1] == '-' || s[0] == '-') return false;
        return true;
    }
    return false;
}
//===================================================================================================================================
// Punctuation Station
vector<char> punctuation = {'.', ';', ',', '?', '-', '\''};

bool is_punct(char c)
{
    for(int i = 0; i<punctuation.size(); ++i)
        if(c == punctuation[i]) return true;
    return false;
}
//===================================================================================================================================
// 
void process_line(ofstream& ost, string line)
{    
    istringstream ss{line}; // create string input stream
    ostringstream os;       // create string output stream

    bool inquotes = false; // indicator if string currently enclosed in quotes
    bool endquote = false;
    while(!ss.eof())
    {
        char c;
        ss>>c;    // read the string character by character
        string s;

        if(inquotes)
        {   
            ss.unget();
            ss>>s;
            os<<s<<' ';
            if(c == '"') 
            {
                inquotes = false; // end of double quotes
                endquote = true;
            }
        }
        else if(c == '"') 
        {
            if(endquote) endquote = false;
            else
            {
                inquotes = true;      // if we encounter a double quote alter indicator variable
                os<<c;
            }
        }
        else if(c == ' ') os<<c;      // preserve whitespace
        else                          // if the character is not a double quote or whitespace
        {
            ss.unget();               // put the character back in the stream
            ss>>s;                    // grab a string

            if(is_contraction(s)) os<<un_contract(s)<<' ';
            else if(is_hyphenated(s)) os<<s<<' ';
            else 
            {
                for(char ch:s)
                {
                    if(is_punct(ch)) os<<' ';
                    else os<<ch;
                }
                os<<' ';
            }
        }    
    }
    ost<<os.str();
}

void process_file(ifstream& ist, ofstream& ost)
{
    while(!ist.eof())
    {
        string line;                          
        getline(ist, line);                   

        process_line(ost, line);         // Process the file line by line

        ost<<'\n';                            // Move to next line in output file. 
    }
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
//==================================================================================================================
int main()
try
{
    string iname = get_input_file();
    ifstream ist{iname};
    if(!ist) error("Cannot open file ", iname);

    string oname = get_output_file();
    ofstream ost{oname};
    if(!ost) error("Cannot open file ", oname);

    process_file(ist, ost);

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