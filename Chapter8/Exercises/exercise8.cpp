/*
    Read an indefinite number of names into a vector<string> name, then prompt the user for the ages of the people named and store the ages in a vector<double> age....
*/

#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> name;
    vector<double> age;

    cout<<"Please enter as many names as you would like names: "<<'\n'
        <<"When you are done entering names, type 'done'"<<'\n';
    string s;
    while(cin>>s)
    {
        if(s == "done" || s == "Done" || s == "DONE") break;

        name.push_back(s);
    }

    cout<<"What are the ages of these people?"<<'\n';
    int ages;
    for(int i = 0; i < name.size(); ++i)
    {
        cin>>ages;
        age.push_back(ages);
    }

    for(int i = 0; i < name.size(); ++i)
    {
        cout<<"("<<name[i]<<", "<<age[i]<<")"<<'\n';
    }

    vector<string> name_copy = name;
    
    cout<<'\n'<<"Results after sorting: "<<'\n';

    sort(name.begin(),name.end());

    for(int j = 0; j < name.size(); ++j)
    {
        for(int i = 0; i < age.size(); ++i)
        {
            if(name[j] == name_copy[i])
            {
                cout<<"("<<name[j]<<", "<<age[i]<<")"<<'\n';
            }
        }
    }
}