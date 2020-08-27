/*
    Write a program that reads the data from raw_temps.txt created in exercise 2 into a vector and then calculates
    the mean and median temperatures in your data set. Call this program temp_stats.cpp
*/

#include "../../../std_lib_facilities.h"

constexpr int min_hour = 0;
constexpr int max_hour = 23;

struct Reading {        // a temperature reading
    int hour;           // hour after midnight [0:23]
    double temperature; // in Farenheit
};

ostream& operator<<(ostream& os, Reading& r)
{
    return os<<'('<<r.hour<<','
             <<r.temperature<<')';
}

double get_median(vector<double>& v)
{
    int l = v.size();                // length of vector

    if(l % 2 == 0)            // if length is even
    {
        int half = l / 2;
        int half_plus = half + 1;
        return (v[half] + v[half_plus]) / 2; // average the middle and next highest value
    }
    else 
    {
        return v[ceil(l/2)];
        int half = ceil(v.size()/2);
        return v[half];
    }
}
int main()
{
    string iname = "raw_temps.txt";
    ifstream ist{iname};        // ist reads from a file named oname
    if(!ist) error("can't open output file ", iname);

    vector<Reading> temps;  //store the readings here
    vector<double> temperatures;

    int hour;
    double temperature;
    double temp_sum = 0;    //sum temperatures here
    while(ist>>hour>>temperature)
    {
        if(hour < min_hour || max_hour < hour) error("hour out of range");
        temps.push_back(Reading{hour, temperature});
        temperatures.push_back(temperature);
        temp_sum += temperature;
    }

    //Perform calculations of summary statistics
    double temp_mean = temp_sum/temps.size();

    sort(temperatures.begin(), temperatures.end());
    double median = get_median(temperatures);
    

    cout<<"The mean equals "<<temp_mean<<'\n'
        <<"The median equals "<<median<<'\n';


}