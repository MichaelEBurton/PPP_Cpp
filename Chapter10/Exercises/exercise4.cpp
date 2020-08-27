/*
    Modify the store_temps.cpp program to include a temperature suffix c for Celsius or f for Farenheit temperatures. Then modify the temp_stats.cpp program 
    to test each temperature, converting the Celsius readings to Fahrenheit before putting them into the vector.
*/

#include "../../../std_lib_facilities.h"

constexpr int min_hour = 0;
constexpr int max_hour = 23;

struct Reading {        // a temperature reading
    int hour;           // hour after midnight [0:23]
    double temperature; // in Farenheit
    char unit;

    Reading(int hh, double tt, char uu)
        : hour(hh), temperature(tt), unit(uu) {};
};

ostream& operator<<(ostream& os, const Reading& r)
{
    return os<<r.hour<<' '
             <<r.temperature<< ' '
             <<r.unit;
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

double celsius_to_farenheit(double c)
{
    return c*(9/5) + 32;
}

int main()
{
    string oname = "raw_temps.txt";
    ofstream ofs{oname};        // ofs writes to a file named oname
    if(!ofs) error("can't open output file ", oname);
    
    ofs<<Reading(0, 59.9,'f')<<'\n'
       <<Reading(1, 61.2,'f')<<'\n'
       <<Reading(2, 62.0,'f')<<'\n'
       <<Reading(2, 62.4,'f')<<'\n'
       <<Reading(3, 62.7,'f')<<'\n'
       <<Reading(4, 63.1,'f')<<'\n'
       <<Reading(5, 63.7,'f')<<'\n'
       <<Reading(6, 64.2,'f')<<'\n'
       <<Reading(7, 64.999,'f')<<'\n'
       <<Reading(8, 65.1,'f')<<'\n'
       <<Reading(9, 65.8,'f')<<'\n'
       <<Reading(10, 66.5,'f')<<'\n'
       <<Reading(11, 67.7, 'f')<<'\n'
       <<Reading(12, 70.0,'f')<<'\n'
       <<Reading(13, 72.2,'f')<<'\n'
       <<Reading(14, 72.8,'f')<<'\n'
       <<Reading(15, 73.3,'f')<<'\n'
       <<Reading(16, 73.6,'f')<<'\n'
       <<Reading(17, 72.9,'f')<<'\n'
       <<Reading(18, 72.7,'f')<<'\n'
       <<Reading(19, 71.2,'f')<<'\n'
       <<Reading(20, 69.6,'f')<<'\n'
       <<Reading(21, 67.9,'f')<<'\n'
       <<Reading(22, 64.8,'f')<<'\n'
       <<Reading(23, 63.2,'f')<<'\n'
       <<Reading(0, 20.1,'c')<<'\n'
       <<Reading(1, 22.1,'c')<<'\n'
       <<Reading(2, 23.1,'c')<<'\n'
       <<Reading(2, 24.1,'c')<<'\n'
       <<Reading(3, 25.1,'c')<<'\n'
       <<Reading(4, 26.1,'c')<<'\n'
       <<Reading(5, 27.1,'c')<<'\n'
       <<Reading(6, 28.1,'c')<<'\n'
       <<Reading(7, 29.1,'c')<<'\n'
       <<Reading(8, 30.1,'c')<<'\n'
       <<Reading(9, 31.1,'c')<<'\n'
       <<Reading(10, 32.1,'c')<<'\n'
       <<Reading(11, 33.1,'c')<<'\n'
       <<Reading(12, 34.1,'c')<<'\n'
       <<Reading(13, 36.1,'c')<<'\n'
       <<Reading(14, 37.1,'c')<<'\n'
       <<Reading(15, 38.1,'c')<<'\n'
       <<Reading(16, 38.1,'c')<<'\n'
       <<Reading(17, 38.1,'c')<<'\n'
       <<Reading(18, 36.1,'c')<<'\n'
       <<Reading(19, 34.1,'c')<<'\n'
       <<Reading(20, 32.1,'c')<<'\n'
       <<Reading(21, 30.1,'c')<<'\n'
       <<Reading(22, 29.1,'c')<<'\n'
       <<Reading(23, 27.1,'c')<<'\n';

    ofs.close();
    
    //=====================================================================================================
    // temp_stats.cpp

    string iname = "raw_temps.txt";
    ifstream ist{iname};        // ist reads from a file named oname
    if(!ist) error("can't open output file ", iname);

    vector<Reading> temps;  //store the readings here
    vector<double> temperatures;


    int hour;
    double temperature;
    char unit;
    double temp_sum = 0;    //sum temperatures here
    while(ist>>hour>>temperature>>unit)
    {
        if(hour < min_hour || max_hour < hour) error("hour out of range");
        if(unit != 'c' && unit != 'f') error("Invalid unit!");
    
        temps.push_back(Reading{hour, temperature, unit});

        temp_sum += temperature;
        temperatures.push_back(temperature);
    }

    //Perform calculations of summary statistics
    double temp_mean = temp_sum/temps.size();

    sort(temperatures.begin(), temperatures.end());

    double median = get_median(temperatures);
    

    cout<<"The mean equals "<<temp_mean<<'\n'
        <<"The median equals "<<median<<'\n';
    return 0;
    return 0;
}