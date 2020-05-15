//Read a sequence of double values and treat each value as the distance between two cities along a given route
//  1. Compute and print the total distance
//  2. Print the smallest distance
//  3. Print the largest distance
//  4. Print the mean distance


#include "../../../std_lib_facilities.h"

int main()
{
    vector<double> dists;                                                               // Create vector to store user entered distances
    
    cout<<"Please enter numbers representing the distance from one city to the next: \n";
    for(double number; cin>>number;){                                                      // Populate vector
        dists.push_back(number);
    }

    sort(dists);

    double total;

    for(int i = 0; i < dists.size(); ++i){
        total += dists[i];
    }
    
    cout<<"The total distance of the distances you entered is "<<total<<"\n"
        <<"The shortest distance is "<<dists[0]<<"\n"
        <<"The greatest distance is "<<dists[dists.size() - 1]<<"\n"
        <<"The mean distance is "<<total/dists.size()<<"\n";

}