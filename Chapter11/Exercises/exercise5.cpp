/*
    Exercise 5: Write a program that reads strings and for each string outputs the character classification of
                each character as defined by the character classification functions presented in section
                11.6. Note that a character can have severl classifications. (e.g. x is both a letter and an
                alphanumeric).

    Note: Probably not the best output but it'll do?
*/

#include "../../../std_lib_facilities.h"

void printc(string& s)
{
    for(char c:s)
    {
        cout<<"Character "<<c<<" is a: \n";

        if(isspace(c)) cout<<"\tspace\n";
        if(isalpha(c)) cout<<"\tletter\n";
        if(isdigit(c)) cout<<"\tdecimal digit\n";
        if(isxdigit(c)) cout<<"\thexadecimal digit\n";
        if(isupper(c)) cout<<"\tupercase letter\n";
        if(islower(c)) cout<<"\tlowercase letter\n";
        if(isalnum(c)) cout<<"\tletter or decimal digit\n";
        if(iscntrl(c)) cout<<"\tcontrol character\n";
        if(ispunct(c)) cout<<"\tnot a letter, digit, whitespace, or invisible control character\n";
        if(isprint(c)) cout<<"\tprintable\n";
        if(isgraph(c)) cout<<"\tletter or digit or punctuation\n";
    }
}

int main()
try
{
    cout<<"Please enter as many strings as you'd like: ";


    while(cin) 
    {
        string s;
        cin>>s;

        printc(s);
    }
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