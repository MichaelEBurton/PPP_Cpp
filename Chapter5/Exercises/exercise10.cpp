
#include "../../../std_lib_facilities.h"

int main()
try {
    cout<<"Please enter the number of values you wish to sum: ";
    int no_of_values;
    cin>>no_of_values;
    
    if(no_of_values < 0) error("Error: You must enter a positive number of values you want summed.");

    cout<<"\nPlease enter some integers (press '|' to stop):";

    double sum = 0;
    int i = 0;                                 //Control variable
    vector<double> values;                     //Vector to store user entered values
    vector<double> differences;                //Vector to store differences
    for(double x; cin>>x;)                     // Loop to populate vector and calculate differences
    {
        if(x == '|') break;
        values.push_back(x);

        if(i < no_of_values) {
            sum += values[i];
            if(i > 0) differences.push_back(values[i] - values[i-1]);
        }
        ++i;
    }

    if(values.size() < no_of_values) error("Error: not enough values entered.");

    cout<<"The sum of the first "<< no_of_values<<" numbers (";
    for(int i = 0; i < no_of_values; ++i){
        cout<<values[i]<<" ";
    } 
    cout<<") is "<<sum<<".\n";

    cout<<"The differences between adjacent cells are:";
    for(int i = 0; i < differences.size(); ++i){
        cout<<" "<<differences[i];
    }
    
    return 0;
}
catch(exception& e){
    cerr<<"error: "<<e.what()<<'\n';
    return 1;
}
catch(...){
    cerr<<"Oops: Unknown exceptions!\n";
    return 2;
}