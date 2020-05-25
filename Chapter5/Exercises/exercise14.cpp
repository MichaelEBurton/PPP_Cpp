
#include "../../../std_lib_facilities.h"

// Returns what day the user entered value is
string what_day(string s){
    vector<string> m = {"Monday", "monday", "Mon", "mon"};
    vector<string> tu = {"Tuesday", "tuesday", "Tue", "tue"};
    vector<string> w = {"Wednesday", "wednesday", "Wed", "wed"};
    vector<string> th = {"Thursday", "thursday", "Thu", "thu"};
    vector<string> f = {"Friday", "friday", "Fri", "fri"};
    vector<string> sa = {"Saturday", "saturday", "Sat", "sat"};
    vector<string> su = {"Sunday", "sunday", "Sun","sun"};

    for(int i = 0; i < m.size(); ++i) if(s == m[i]) return "monday";
    for(int i = 0; i < tu.size(); ++i) if(s == tu[i]) return "tuesday";
    for(int i = 0; i < w.size(); ++i) if(s == w[i]) return "wednesday";
    for(int i = 0; i < th.size(); ++i) if(s == th[i]) return "thursday";
    for(int i = 0; i < f.size(); ++i) if(s == f[i]) return "friday";
    for(int i = 0; i < sa.size(); ++i) if(s == sa[i]) return "saturday";
    for(int i = 0; i < su.size(); ++i) if(s == su[i]) return "sunday";
    return "rejected";
}

int main()
try {
    //Vectors to store weekday values
    vector<int> mon;
    vector<int> tue;
    vector<int> wed;
    vector<int> thu;
    vector<int> fri;
    vector<int> sat;
    vector<int> sun;

    //Create counter's to sum values
    int m = 0;
    int tu = 0;
    int w = 0;
    int th = 0;
    int f = 0;
    int sa = 0;
    int su = 0;

    string day = "";
    int v = 0;
    int r = 0;
    cout<<"Please enter a day-of-the-week value pair (day-of-the-week, value) [to stop enter \"|\" twice]: ";
    
    while(cin>>day>>v){
        if(what_day(day) == "monday"){
            mon.push_back(v);
            m += v;
        }
        else if(what_day(day) == "tuesday"){
            tue.push_back(v);
            tu += v;
        }
        else if(what_day(day) == "wednesday"){
            wed.push_back(v);
            w += v;
        }
        else if(what_day(day) == "thursday"){
            thu.push_back(v);
            th += v;
        }
        else if(what_day(day) == "friday"){
            fri.push_back(v);
            f += v;
        }
        else if(what_day(day) == "saturday"){
            sat.push_back(v);
            sa += v;
        }
        else if(what_day(day) == "sunday"){
            sun.push_back(v);
            su += v;
        }
        else ++r;                                             //count the number of rejected values.
    }

    cout<<"Sum of all Monday values: "<< m <<'\n'
        <<"Sum of all Tuesday values: "<< tu <<'\n'
        <<"Sum of all Wednesday values: "<< w <<'\n'
        <<"Sum of all Thursday values: "<< th <<'\n'
        <<"Sum of all Friday values: "<< f <<'\n'
        <<"Sum of all Saturday values: "<< sa <<'\n'
        <<"Sum of all Sunday values: "<< su <<'\n'
        <<"Number of rejected values: "<< r <<'\n';
    return 0;
}
catch(exception& e){
    cerr<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops unkown exception!";
    return 2;
}