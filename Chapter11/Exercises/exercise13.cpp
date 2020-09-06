/*
    Exercise 13: Reverse the order of words (defined as whitespace-separated strings) in a file. For example, Norwegian
                 Blue parrot becomes parrot Blue Norwegian. You are allowed to assume that all the strings from the 
                 file will fit into memory at once.

    Notes: Could improve by fixing how punctuation is handled.
*/

#include "../../../std_lib_facilities.h"
//===================================================================================================================================
vector<string> get_words(ifstream& is)
{
    vector<string> words;
    while(!is.eof())
    {
        string s;
        is>>s;
        words.push_back(s);
    }
    return words;
}

void print_words(ofstream& os, vector<string> words)
{
    for(int i = words.size() - 1; i >= 0; --i)
    {
        os<<words[i]<<' ';
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

//===================================================================================================================================

int main()
try{
    string iname = get_input_file();
    ifstream ist{iname};
    if(!ist) error("Cannot open file ", iname);

    string oname = get_output_file();
    ofstream ost{oname};
    if(!ost) error("Cannot open file ", oname);

    vector<string> words = get_words(ist);
    print_words(ost, words);


    return 0;
}
catch(exception& e){
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...) {
    cerr<<"Oops, unknown error!\n";
    return 2;
}