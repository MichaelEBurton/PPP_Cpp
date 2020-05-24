
#include "../../../std_lib_facilities.h"

int main()
try {
    cout<<"Please enter the number of values you wish to sum: ";
    int no_of_values;
    cin>>no_of_values;
    
    if(no_of_values < 0) error("Error: You must enter a positive number of values you want summed.");

    cout<<"\nPlease enter some integers (press '|' to stop):";
    double sum = 0;
    int i = 0;
    vector<double> values;
    for(double x; cin>>x;)
    {
        if(x == '|') break;
        values.push_back(x);
        if(i < no_of_values) sum += values[i];
        ++i;
    }

    if(int(sum) != sum) error("Error: Sum is not able to be represented as an integer.");
    if(values.size() < no_of_values) error("Error: not enough values entered.");

    cout<<"The sum of the first "<< no_of_values<<" numbers (";
    for(int i = 0; i < no_of_values; ++i){
        cout<<values[i]<<" ";
    } 
    cout<<") is "<<sum<<".\n";
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