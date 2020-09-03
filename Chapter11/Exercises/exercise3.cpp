/*
    Exercise 3: Write a program that removes all vowels from a file ("disemvowels"). For examples,
                Once upon a time! becomes nc pn tm! Suprisingly often, the result is still readable;
                try it on your friends.
*/

#include "../../../std_lib_facilities.h"

bool is_vowel(char c)
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    for(char ch:vowels)
        if(tolower(c) == ch) return true;

    return false;
}

int main()
try{
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

        for(char c:line)
            if(is_vowel(c));
            else ost<<c;
        
        ost<<'\n';
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