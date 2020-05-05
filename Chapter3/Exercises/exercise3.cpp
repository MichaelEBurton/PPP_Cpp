// This file doesn't do anything
// It is used to illustrate how the compiler reacts to illegal names

#include "../../../std_lib_facilities.h"

int main()
{
    int double = 0;

    //double string = 2.7; This is legal because string is a user defined type and thus is not a reserved keyword.

    int happy = 4;

    string 3words = "This is educational";

    bool _illegal_ = true;

    double cobra = 3.141592;
}