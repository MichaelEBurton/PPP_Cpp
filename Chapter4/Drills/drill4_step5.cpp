// Drill for chapter 4
// Write a program that consists of writing a while-loop that reads in two ints and prints them.
//   Exit the program whena  terminating '|' is entered.
//   This is the drill through step 5.

#include "../../../std_lib_facilities.h"

int main()
{
    double num1 = 0.0;
    double num2 = 0.0;
    char c;

    while(true){
        cout<<"Please enter two integer values (to exit enter '|')\n";
        
        if (cin>>num1>>num2){
            cout<<"Numbers Entered: "<<num1<<" "<<num2<<"\n\n";

            if (num2 == num1)
                cout<<"The numbers are equal\n";

            else if( (num2 - num1) < (1.0/100) && (num2 - num1) > (-1.0/100))
                cout<<"The numbers are almost equal\n";

            else if (num1 > num2)
                cout<<"The smaller value is: "<<num2<<", "
                    <<"the larger value is: "<<num1<<'\n';

            else 
                cout<<"The smaller value is: "<<num1<<", "
                    <<"the larger value is: "<<num2<<'\n';
        }

        else {
            cin.clear(); //Unsure as to why this is necessary found it in similar solution online.
            cin>>c;
            if(c == '|')
                break;
            else
                cout<<"Entry was invalid, try again"<<"\n";
        }

    }
}