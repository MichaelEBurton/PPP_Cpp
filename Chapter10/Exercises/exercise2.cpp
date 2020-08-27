/*
    Write a program that creates a file of data in the form of the temperature Reading type defined in section 10.5. For testing, 
    fill the file with at least 50 "temperature readings." Call this program store_temps.cpp and the file it creates raw_temps.txt.
*/

#include "../../../std_lib_facilities.h"

struct Reading {        // a temperature reading
    int hour;           // hour after midnight [0:23]
    double temperature; // in Farenheit

    Reading(int hh, double tt)
        : hour(hh), temperature(tt) {};
};

ostream& operator<<(ostream& os, const Reading& r)
{
    return os<<r.hour<<' '
             <<r.temperature;
}

int main()
{
    string oname = "raw_temps.txt";
    ofstream ofs{oname};        // ofs writes to a file named oname
    if(!ofs) error("can't open output file ", oname);
    
    ofs<<Reading(0, 59.9)<<'\n'
       <<Reading(1, 61.2)<<'\n'
       <<Reading(2, 62.0)<<'\n'
       <<Reading(2, 62.4)<<'\n'
       <<Reading(3, 62.7)<<'\n'
       <<Reading(4, 63.1)<<'\n'
       <<Reading(5, 63.7)<<'\n'
       <<Reading(6, 64.2)<<'\n'
       <<Reading(7, 64.999)<<'\n'
       <<Reading(8, 65.1)<<'\n'
       <<Reading(9, 65.8)<<'\n'
       <<Reading(10, 66.5)<<'\n'
       <<Reading(11, 67.7)<<'\n'
       <<Reading(12, 70.0)<<'\n'
       <<Reading(13, 72.2)<<'\n'
       <<Reading(14, 72.8)<<'\n'
       <<Reading(15, 73.3)<<'\n'
       <<Reading(16, 73.6)<<'\n'
       <<Reading(17, 72.9)<<'\n'
       <<Reading(18, 72.7)<<'\n'
       <<Reading(19, 71.2)<<'\n'
       <<Reading(20, 69.6)<<'\n'
       <<Reading(21, 67.9)<<'\n'
       <<Reading(22, 64.8)<<'\n'
       <<Reading(23, 63.2)<<'\n'
       <<Reading(0, 59.9)<<'\n'
       <<Reading(1, 61.2)<<'\n'
       <<Reading(2, 62.0)<<'\n'
       <<Reading(2, 62.4)<<'\n'
       <<Reading(3, 62.7)<<'\n'
       <<Reading(4, 63.1)<<'\n'
       <<Reading(5, 63.7)<<'\n'
       <<Reading(6, 64.2)<<'\n'
       <<Reading(7, 64.999)<<'\n'
       <<Reading(8, 65.1)<<'\n'
       <<Reading(9, 65.8)<<'\n'
       <<Reading(10, 66.5)<<'\n'
       <<Reading(11, 67.7)<<'\n'
       <<Reading(12, 70.0)<<'\n'
       <<Reading(13, 72.2)<<'\n'
       <<Reading(14, 72.8)<<'\n'
       <<Reading(15, 73.3)<<'\n'
       <<Reading(16, 73.6)<<'\n'
       <<Reading(17, 72.9)<<'\n'
       <<Reading(18, 72.7)<<'\n'
       <<Reading(19, 71.2)<<'\n'
       <<Reading(20, 69.6)<<'\n'
       <<Reading(21, 67.9)<<'\n'
       <<Reading(22, 64.8)<<'\n'
       <<Reading(23, 63.2)<<'\n';
    return 0;
}