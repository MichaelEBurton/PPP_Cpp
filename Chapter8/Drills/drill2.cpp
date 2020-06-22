/*
    Date 6/22/20
    Author: Michael B.

    Purpose: Write three functions swap_v(int, int), swap_r(int&, int&), swap_cr(const int&, const int&).
               Each should have the body {int temp; temp = a, a=b; b= temp;}

            Try calling each swap like this:  
                int x = 7;
                int y = 9;
                swap_?(x,y);             v compiled & didn't swap, r compiled and didn't swap, cr doesn't compile
                swap_?(7,9);             v compiled, r didn't compile, cr doesn't compile
                const int cx = 7;
                const int cy = 9;
                swap_?(cx, cy);
                swap_?(7.7, 9.9);
                double dx = 7.7;
                double dy = 9.9;
                swap_?(dx, dy);
                swap_?(7.7,9.9);

            After each swap that compiled print the value of the arguments to see if they were actually swapped.

            *swap_cr() will not compile for any since it tries to change constant references
            *swap_v() compiles for all cases, bur does not swap anything
            * You cannot swap constants like const int cx/cy
            * swap_r(dx, dy) does not compile
*/
#include "../../../std_lib_facilities.h"

void swap_v(int a, int b) {int temp; temp = a, a = b; b = temp;}

void swap_r(int& a, int& b) {int temp; temp = a, a = b; b = temp;}

//void swap_cr(const int& a, const int& b) {int temp; temp = a, a = b; b = temp;}

int main()
{
    double dx = 7.7;
    double dy = 9.9;
    swap_r(dx, dy);
    //swap_r(7.7,9.9);

    cout<<dx<<dy<<'\n';
}