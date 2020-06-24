/*
    Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages in a vector<double> age....
*/

#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> name(5);
    vector<double> age(5);

    cout<<"Please enter 5 names: "<<'\n';
    for(int i = 0; i < name.size(); ++i)
    {
        cin>>name[i];
    }

    cout<<"What are the ages of these people?"<<'\n';
    for(int i = 0; i < age.size(); ++i)
    {
        cin>>age[i];
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