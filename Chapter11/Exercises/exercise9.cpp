/*
    Exercise 9 : Split the binary I/O program from section 11.3.2 into two: one program that converts an ordinary
                 text file into binary and one proram that reads binary and converts it to text. Test these programs
                 by comparing a text file with what you get by converting it to binary and back.

    Notes: I just made this as one file and it appears to work please let me know if you've found a way to improve it.
*/

#include "../../../std_lib_facilities.h"


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
    ifstream ist{iname, ios_base::binary};
    if(!ist) error("Cannot open file ", iname);

    string oname = get_output_file();
    ofstream ost{oname, ios_base::binary};
    if(!ost) error("Cannot open file ", oname);

    vector<char> v;
    for(char c; ist.read(as_bytes(c), sizeof(char));)
        v.push_back(c);
    
    for(char c:v)
        ost.write(as_bytes(c), sizeof(char));
    
    ifstream is{oname};
    ofstream os{oname};

    vector<char> v2;
    for(char c; is.read(as_bytes(c), sizeof(char));)
        v2.push_back(c);

    for(char c:v2)
        os.write(as_bytes(c),sizeof(char));

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