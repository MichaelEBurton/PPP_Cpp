/* 
    Write a program that accepts two file names and produces a new file that is the contents of the first file followed by the
    contents of the second; that is, the program concatenates the two files.

    References: 0p3r4t4
*/

#include "../../../std_lib_facilities.h"

void add_content(const string& name, ofstream& ost)
// Add the contents of the file referred to by name to the output stream;
{
    ifstream is{name};
    if(!is) error("Can't open input file ", name);

    while(!is.eof()){           
        char c = is.get();    // read the file character by character to preserve format
        if(!is.eof()) ost<<c; // output as long as it's not the end of the file.
    }
    ost<<'\n';                // go to a new line when you're done with one file
}

void concatenate_files(const string& n1, const string& n2, const string& out)
// Adds the contents from file one and file two.
{
    ofstream ost{out};
    if(!ost) error("Can't open file ", out);

    add_content(n1, ost);
    add_content(n2, ost);
}

int main()
try {
    string bname;
    cout<<"Please enter the name of the base file: ";
    cin>>bname;

    string cname;
    cout<<"\nPlease enter the name of the file you wish to concatenate to "<<bname<<": ";
    cin>>cname;

    string oname;
    cout<<"\nWhat would you like to name the new file: ";
    cin>>oname;

    concatenate_files(bname, cname, oname);

    return 0;
}
catch(exception& e) {
    cerr<<"Error: "<<e.what();
    return 1;
}
catch(...) {
    cerr<<"Oops, Something bad happened!";
    return 2;
}