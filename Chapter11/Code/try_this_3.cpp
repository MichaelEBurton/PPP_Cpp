/*
    Write some code to print the number 1234567.89 three times, first using defaultfloat, then fixed, then scientific. Which
    output form presents the user with the most accurate representation? Explain why.

Results:
    1.23457e+06     general
    1234567.890000  fixed
    1.234568e+06    scientific

    The fixed format procides the most accurate representation since no rounding took place.

*/
#include "../../../std_lib_facilities.h"

const double num = 1234567.89;

int main()
{
    cout<<defaultfloat<<num<<"\tgeneral\n"
        <<fixed<<num<<"\tfixed\n"
        <<scientific<<num<<"\tscientific\n";
}