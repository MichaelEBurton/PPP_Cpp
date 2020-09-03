/*
    Exercise 2: Write a program that given a file name and a word outputs each line that contains that word together with
                the line number. Hint getline().
*/

#include "../../../std_lib_facilities.h"

bool contains_word(string& s, const string w)
{
    istringstream is{s};

    for(string word; is>>word;)
        if(word == w) return true;
    
    return false;
}

int main()
try{
    string iname;
    cout<<"What is the name of the file you wish to read: ";
    cin>>iname;

    ifstream ist{iname};
    if(!ist) error("Cannot open file ", iname);

    string word;
    cout<<"\nWhat word are you interested in: ";
    cin>>word;

    string oname;
    cout<<"\nWhat is the name of the file you wish to write: ";
    cin>>oname;

    ofstream ost{oname};
    if(!ost) error("Cannot open file ", oname);

    int linenum = 1;
    while(!ist.eof())
    {
        string line;
        getline(ist, line);

        if(contains_word(line, word))
            ost<<linenum<<' '<<line<<'\n';
        
        else 
            ost<<"  "<<line<<'\n';

        ++linenum;
    }    
    return 0;
}
catch(exception& e) {
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...){
    cerr<<"Oops, unknown error!";
    return 2;
}