#include "../../../std_lib_facilities.h"

void print(string label, vector<int>& v)
{
   cout<<label<<'\n';

   for(int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\n';
    }
}

int main()
{
    vector<int> test = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    string lab = "First twenty numbers";

    print(lab, test);
}