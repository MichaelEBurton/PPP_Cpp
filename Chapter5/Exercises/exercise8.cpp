
#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter the number of values you wish to sum: ";
    int no_of_values;
    cin>>no_of_values;
    
    if(no_of_values < 0) error("Error: You must enter a positive number of values you want summed.");

    cout<<"\nPlease enter some integers (press '|' to stop):";
    vector<int> values;
    for(int x; cin>>x;)
    {
        if(x == '|') break;
        values.push_back(x);
    }
    
    if(no_of_values < values.size()) error("Error: not enough values entered.");

    cout<<"The sum of the first "<< no_of_values<<" numbers (";
    int sum = 0;
    for(int i = 0; i < no_of_values; ++i){
        sum += values[i];
        cout<<values[i]<<" ";
    } 

    cout<<") is "<<sum<<".\n";
}