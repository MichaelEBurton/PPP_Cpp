/*
    Exercise 16: Write a program to read a file or whitespace-separated numbers and output them in order (lowest value first),
                 one value per line. write a value only once and if it occurs more than once write the count of its occurences
                 on its line. For example, 7 5 5 7 3 117 5 should give
                   3
                   5    3
                   7    2
                   117
*/

#include "../../../std_lib_facilities.h"
//===================================================================================================================================
vector<double> read_numbers(ifstream& is)
// returns a sorted vector of doubles from an input stream
{
    vector<double> nums;
    while(!is.eof()) // yikes better not get a value that's not a number
    {
        double d;
        is>>d;
        nums.push_back(d);
    }
    sort(nums.begin(), nums.end());

    return nums;
}

void write_numbers(ifstream& is)
{
    vector<double> numbers = read_numbers(is);

    int count = 1;
    for(int i = 0; i < numbers.size(); ++i)
    {

        if(i == 0)
            cout<<numbers[i];
        else if(numbers[i-1] == numbers[i])
            count += 1;
        else if(count > 1)
        {
            cout<<'\t'<<count<<'\n';
            count = 1;
            cout<<numbers[i];
        }
        else 
            cout<<'\n'<<numbers[i];
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

    write_numbers(ist);

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