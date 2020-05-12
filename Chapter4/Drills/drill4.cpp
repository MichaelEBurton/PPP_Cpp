// Drill for chapter 4
// Write a program that consists of writing a while-loop that reads in a double and it's unit of measurement (cm,m,in,ft), and prints the largest value, smallest value, number of values,
//   sum of values, and all values entered in meters.
//   Exit the program when a  terminating '|' is entered.
//   This is the drill through step 11.

#include "../../../std_lib_facilities.h"

int main()
{
    double num = 0.0;
    string unit = "";

    double smallest;
    double largest;
    char c;
    
    const double cm_to_m = .01;                                                // Conversion Factors
    const double in_to_cm = 2.54;
    const double ft_to_in = 12.0;
    
    double sum = 0;                                                       
    int number_of_values = 0;
    
    vector<double> entries;
    int i = 0;                                                                  // initialize constructor variable
    while(i < 3){                                                               // Condition that will never be met

        cout<<"Please enter a double value with a unit (cm, m, ft, in)\n(to exit enter '|')\n";              // Instructions to user

        if (cin>>num){                                                           // Executes as long as the user enters a numeric value
            cin>>unit;                                                           // Read in the units
            
            if(unit == "|")
                break;
            else if(unit != "cm" && unit != "m" && unit != "ft" && unit != "in")
                cout<<"illegal representation of units\n";
            else 
                cout<<"Number entered: "<<num<<" "<<unit<<"\n";
                
                if(unit == "in") num = num * in_to_cm * cm_to_m;
                else if(unit == "ft") num = num * ft_to_in * in_to_cm * cm_to_m;
                else if(unit == "cm") num = num * cm_to_m;
                
                cout<<"this is equivalent to "<<num<<" meters\n";

                if(i == 0){                                                        // Only run the first iteration, so we can intialize the smallest 
                    cout<<"The smallest and largest so far \n";                    //   and largest values.
                    smallest = num;
                    largest = num;
                    ++i;                                                           // Increment i, so we never access this block of code again.
                }

                if(num < smallest){                                                // Store the smallest number so far
                    smallest = num;
                    cout<<"the smallest so far \n";
                }
                else if(num > largest) {                                           // Store the largest number so far
                    largest = num;
                    cout<<" largest so far \n";
                }
                
                entries.push_back(num);                                           // Store all entries in a vector
                sum += num;                                                       // Total the entries
                ++number_of_values;                                               // Count the number of entries
        }
        else {                                                                    // Instructions when a non numeric value is entered.
            cin.clear();                                                          //Unsure as to why this is necessary found it in similar solution online.
            cin>>c;
            if(c == '|')                                                          // Break the loop when this character is entered.
                break;
            else
                cout<<"Entry was invalid, try again"<<"\n";
        }

    }

    cout<<"The largest distance was "<<largest<< " meters.\n"
        <<"The smallest distance was "<<smallest<<" meters.\n"
        <<"The number of values entered was "<<number_of_values<<".\n"
        <<"The sum of all distances entered is "<<sum<<" meters.";
    
    cout<<"The values (in meters) you entered are: \n";

    sort(entries);
    for(int j = 0; j < entries.size(); ++j){
        cout<<entries[j]<<" ";
    }
}