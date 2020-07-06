
#include "../../../std_lib_facilities.h"

class Name_pairs {
    public:
        void read_names(); // read a series of names
        void read_ages();  // read a series of ages
        void print();      // prints (name, age) pairs
        void sort();       // Sort the name vector in alphabetical order and reorganizes the age vector
    private:
        vector<string> name;
        vector<double> age; 
};

void Name_pairs::read_names()
{
    cout<<"Please enter a series of names (type \"done\" when finished): \n";

    for(string s; cin>>s;){
        if(s == "DONE" || s == "done") break;
        name.push_back(s);
    }

}

void Name_pairs::read_ages()
{
    cout<<"Please enter a series of ages: \n";

    double d;

    for(int i = 0; i < name.size(); ++i)
    {
        cin>>d;
        age.push_back(d);
    }

}

void Name_pairs::print()
{
    for(int i = 0; i < name.size(); ++i)
    {
        cout<<'(' <<name[i] <<", " <<age[i] <<')' << '\n';
    }

}

void Name_pairs::sort()
{
    vector<string> name_copy = name;
    vector<double> age_copy = age;

    std::sort(name.begin(), name.end());

    for(int j = 0; j < name.size(); ++j)
    {
        for(int i = 0; i < age.size(); ++i)
        {
            if(name[j] == name_copy[i])
            {
                age[j] = age_copy[i];
            }
        }
    }
}

int main()
{

Name_pairs np;

np.read_names();
np.read_ages();
np.sort();
np.print();
}