/*
    Exercise 15: Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using 
                 scientific format and precision 8 in four fields of 20 characters per line.
*/

#include "../../../std_lib_facilities.h"
//===================================================================================================================================
void reformat_doc(ifstream& is, ofstream& os)
{
    vector<double> numbers;
    for(double d; is>>d;)
        numbers.push_back(d);

    os<<scientific<<setprecision(8);

    for(int i = 0; i < numbers.size(); ++i)
    {
        os<<setw(20)<<numbers[i];
        if(i % 4 == 3) os<<'\n';
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

    reformat_doc(ist, ost);

    return 0;
}
catch(exception& e){
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...) {
    cerr<<"Oops, unknown error!"<<'\n';
    return 2;
}