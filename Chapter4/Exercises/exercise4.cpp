// Create a progrm that guesses a number between one and 100
// Inspirtation from 0p3r4t4 and Jtaim on github
// Program currently does not meet the 7 question maximum (example: 42)

#include "../../../std_lib_facilities.h"

int main()
{
    int question = 0;
    int first = 1;
    int last = 100;
    int guess;

    char answer;

    cout<<"Think of a number between 1 and 100\n";

    while(first != last){
    
        if(last - first == 1) 
            guess = last;
        else 
            guess = (first + last)/2;

        cout<<"Is your number less than "<<guess<<"\n"
            <<"Enter y (yes) or n (no): ";
        cin>>answer;
        ++question;

        if(answer == 'y') last = guess - 1;
        else if(answer == 'n') first = guess;
    }

    cout<<"Your number is "<<last<<" it only took me "<<question<<" questions.";
}