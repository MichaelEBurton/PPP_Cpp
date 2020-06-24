/*
  Write two functions that reverse the order of elements in a vector<int>
    > The first reverse function should produce a new vector with the reversed sequence, leaving its 
        original vector unchanged.
    > The second reverse function should reverse the elements of its vector without using any other vectors (hint:swap).
*/

#include "../../../std_lib_facilities.h"

vector<string> reverse1(vector<string>& v)
{
    vector<string> vr(v.size());

    for(int i = 0; i < v.size(); ++i)
    {
        vr[i] = v[v.size() - 1 - i];
    }

    return vr;
}

void reverse2(vector<string>& v)
{
    for(int j = 0; j < v.size()/2; ++j)
    {
        swap(v[j], v[v.size() - 1 - j]);
    }

}

void print(string label, vector<string>& v)
{
   cout<<label<<'\n';

   for(int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\n';
    }
}

int main()
{
    vector<string> v = {"a","b", "c", "d", "e", "f","g","h", "i", "j"};
    
    vector<string> v2 = reverse1(v);

    string label = "Testing reverse1()";

    print(label, v2);

    reverse2(v);

    string label2 = "Testing reverse2()";

    print(label2, v);
}