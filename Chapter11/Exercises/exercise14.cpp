/*
    Exercise 14: Write a program that reads a text file and writes out how many characters of each character classification
                 are in the file.
*/

#include "../../../std_lib_facilities.h"
//===================================================================================================================================
// classify characters
void classify_characters(string fname)
{
    ifstream is{fname};
    if(!is) error("Cannot open file ", fname);

    // Initialize counters
    int space = 0;
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    int number_of_characters = 0;
    while(!is.eof())
    {
        char c;
        is>>c;

        number_of_characters += 1;

        if(isspace(c)) space += 1;
        if(isalpha(c)) alpha += 1;
        if(isdigit(c)) digit += 1;
        if(isxdigit(c)) xdigit += 1;
        if(isupper(c)) upper += 1;
        if(islower(c)) lower += 1;
        if(isalnum(c)) alnum += 1;
        if(iscntrl(c)) cntrl += 1;
        if(ispunct(c)) punct += 1;
        if(isprint(c)) print += 1;
        if(isgraph(c)) graph += 1;
    }

    cout<<"File: "<<fname<<'\n'
        <<"  Total Number of Characters: "<<number_of_characters<<'\n'
        <<"\t# whitespace characters: "<<space<<'\n'
        <<"\t# letters: "<<alpha<<'\n'
        <<"\t# decimal digits: "<<digit<<'\n'
        <<"\t# hexadecimal digits: "<<xdigit<<'\n'
        <<"\t# uppercase letters: "<<upper<<'\n'
        <<"\t# lowercase letters: "<<lower<<'\n'
        <<"\t# letters or decimal digits: "<<alnum<<'\n'
        <<"\t# control characters: "<<cntrl<<'\n'
        <<"\t# punctuation characters: "<<punct<<'\n'
        <<"\t# printable characters: "<<print<<'\n'
        <<"\t# letters, digits, or punctuation characters: "<<graph<<'\n';
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
//===================================================================================================================================

int main()
try{

    string iname = get_input_file();
    classify_characters(iname);

    return 0;
}
catch(exception& e)
{
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...){
    cerr<<"Oops, unknown error!"<<'\n';
    return 2;
}