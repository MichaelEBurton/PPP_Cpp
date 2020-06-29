/*
    Can we declare a non-reference function argument const (e.g., void f(const int);)? What might that mean? Why might we want to do
      that? Why don't people do that often? Try it; write a couple of small programs to see what works.

    Notes: You can. I think it just means you can't change the value of that argument (hence const). If might be useful when optimizing 
             a program? People may not do it often because the benfits may not be significant and the variables will just 'disappear'
             after the function finishes executing.
*/

#include "../../../std_lib_facilities.h"

void f(const int i)
{
    cout<<i<<'\n';
}

int main()
try
{
    f(3);
}
catch(exception& e)
{
    cerr<<e.what()<<'\n';
    return 1;
}
catch(...)
{
    cerr<<"Oops! Unknown exception.";
    return 2;
}
