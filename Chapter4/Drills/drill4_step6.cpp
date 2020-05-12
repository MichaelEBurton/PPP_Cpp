// Drill for chapter 4
// Write a program that consists of writing a while-loop that reads in two ints and prints them.
//   Exit the program whena  terminating '|' is entered.
//   This is the drill through step 6.

#include "../../../std_lib_facilities.h"

int main()
{
    double num = 0.0;
    double smallest;
    double largest;
    char c;
    
    int i = 0;                                                                  // initialize constructor variable
    while(i < 3){                                                               // Condition that will never be met
        cout<<"Please enter a double value (to exit enter '|')\n";              // Instructions to user

        if (cin>>num){                                                          // Executes as long as the user enters a numeric value
            cout<<"Number entered: "<<num<<" ";

            if(i == 0){                                                         // Only run the first iteration, so we can intialize the smallest 
                cout<<" the smallest and largest so far \n";                    //   and largest values.
                smallest = num;
                largest = num;
                ++i;                                                            // Increment i, so we never access this block of code again.
            }

            if(num < smallest){
                smallest = num;
                cout<<"the smallest so far \n";
            }
            else if(num > largest) {
                largest = num;
                cout<<" largest so far \n";
            }
        }
        else {                                                                 // Instructions when a non numeric value is entered.
            cin.clear();                                                       //Unsure as to why this is necessary found it in similar solution online.
            cin>>c;
            if(c == '|')                                                       // Break the loop when this character is entered.
                break;
            else
                cout<<"Entry was invalid, try again"<<"\n";
        }

    }
}