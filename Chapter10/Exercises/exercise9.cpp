/*
    Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.
*/

#include "../../../std_lib_facilities.h"

void get_words(const string file, vector<string>& words)
{
    ifstream ist{file};
    if(!ist) error("Can't open input file ", file);

    for(string s; ist>>s;)
    {
        words.push_back(s);
    }
}

void merge_files(const string& f1, const string& f2, const string& o)
{
    vector<string> words;

    get_words(f1, words);
    get_words(f2, words);

    sort(words);

    ofstream ost{o};
    if(!ost) error("Can't open output file ", o);
    for(int i = 0; i < words.size(); ++i)
    {
        ost<<words[i]<<' ';   
    }
        
}

int main()
try {
    string f1;
    cout<<"What is the name of the first file you wish to merge: ";
    cin>>f1;

    string f2;
    cout<<"\nWhat is the name of the file you wish to merge with "<<f1<<": ";
    cin>>f2;

    string oname;
    cout<<"\nWhat is the name of the output file: ";
    cin>>oname;

    merge_files(f1, f2, oname);

    return 0;
}
catch(exception& e) {
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...) {
    cerr<<"Oops, unknown error!"<<'\n';
    return 2;
}