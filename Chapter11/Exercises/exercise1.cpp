/*
    Write a program that reads a text file and converts its input to all lower case, producing a new file.
*/

#include "../../../std_lib_facilities.h"

string tolower(string& s)
{
    string s2;
    for(char x:s) s2 += tolower(x);

    return s2;
}

int main()
try{
    
    string iname;
    cout<<"Please enter the name of the file you wish to read: ";
    cin>>iname;

    ifstream ifs{iname};
    if(!ifs) error("Cannot open file ", iname);

    string oname;
    cout<<"Please enter the name of the new file: ";
    cin>>oname;

    ofstream ofs{oname};
    if(!ofs) error("Can't open file ", oname);

    for(string word; ifs>>word;)   // doesn't preserve file format
        ofs<<tolower(word)<<' ';
        
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