
#include "../../../std_lib_facilities.h"

class Name_pairs {
    public:
        int get_size() const {return age.size();}
        string get_name_i(int i) const {return name[i];}
        double get_age_i(int i) const {return age[i];}        

        void read_names();                                  // read a series of names
        void read_ages();                                   // read a series of ages
        void sort();                                        // Sort the name vector in alphabetical order and reorganizes the age vector

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

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    for(int i = 0; i < np.get_size(); ++i)
    {
        os<<'(' <<np.get_name_i(i) <<", " <<np.get_age_i(i) <<')' << '\n';
    }

    return os;
}

int main()
{

Name_pairs np;

np.read_names();
np.read_ages();
np.sort();
cout << np;
}