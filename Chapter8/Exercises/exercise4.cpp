// Approximate the maximum value an integer can hold usinig the fibonacci() function.
// From the results we have 1,836,311,903

#include "../../../std_lib_facilities.h"

void print(string label, vector<int>& v)
{
   cout<<label<<'\n';

   for(int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<'\n';
    }
}

void fibonacci(int x, int y, vector<int>& v, int n)
  //Creates a sequence of fibonacci numbers and store them in an empty vector v
  //  v[0] will be x, v[1] will be y, n is the number of elements you 
  //  want in the sequence
  // We use a reference to the vector so we can change it.
{
    v[0] = x;
    v[1] = y;

    for(int i = 0; i < n - 2; ++i)
    {

        v[i + 2] = v[i] + v[i + 1];
    }
}

int main()
{
    int n = 100;
    vector<int> v(n);
    int x = 1;
    int y = 1;

    fibonacci(x,y, v,n);

    string label = "First 10 fibonacci numbers";

    print(label, v);
}