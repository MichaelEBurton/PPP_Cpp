// Fix the program in 4.6.3 so that it always prints out a median 

#include "../../../std_lib_facilities.h"

int main(){

    vector<double> numbers;                                                               // Create vector to store user entered numbers
    
    cout<<"Please enter as many numbers as you would like: \n";
    for(double number; cin>>number;){                                                      // Populate vector
        numbers.push_back(number);
    }

    sort(numbers);                                                                        // Sort numbers
 
    double median;                                                                        // Create variable to hold value of the median

    if(numbers.size() % 2 == 0)                                                           // If the user entered an even number of numbers take the middle two and average them
        median = (numbers[numbers.size()/2] + numbers[numbers.size()/2 + 1]) / 2;
    else if (numbers.size() % 2 == 1)                                                     // If they entered an odd number, take the center value
        median = numbers[(numbers.size() - 1) / 2 + 1];
    
    cout<<"The sequence of numbers you entered: ";
    for(int i=0;i<numbers.size(); ++i){
        cout<<numbers[i]<<"\n";
    }
    
    cout<<"has a median of "<<median<<"\n";
}