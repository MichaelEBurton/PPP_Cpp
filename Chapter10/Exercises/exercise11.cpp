/*
    Exercise 11: Write a program that produces the sum of all the whitespace-separated integers in a text file. 
    For example, bears: 17 elephants 9 end should output 26.
*/

#include "../../../std_lib_facilities.h"

void skip_to_int(istream& ist)
{
    if(ist.fail()) {    // we found something that wasn't an integer
        ist.clear();    // we'd like to look at the characters
        for(char ch; ist>>ch;) {    // throw away non-digits
            if(isdigit(ch)) {
                ist.unget();    // put the digit back
                                // so that we can read the number
                return;
            }
        }
    }
    error("no input");          // eof or bad: give up
}

int sum_file(string& iname)
{
    ifstream ist{iname};
    if(!ist) error("Can't open input file ", iname);

    int sum = 0;
    int n = 0;
    bool cont = true;
    while(cont)
    {
        if(ist>>n) 
        {
            sum += n;
        }
        else if(ist.eof())
        {
            cont = false;
        }
        else 
        {
            skip_to_int(ist);
        }
    }
    return sum;
}

string get_input() 
{
    string s;
    cout<<"Please enter the name of the input file: ";
    cin>>s;

    return s;
}


int main()
try {
    string iname = get_input();

    int sum_of_file = sum_file(iname);

    cout<<"The sum of integers in "<<iname<<" is "<<sum_of_file<<'\n';
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