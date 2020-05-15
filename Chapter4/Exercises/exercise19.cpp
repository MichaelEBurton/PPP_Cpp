// Checked Bjarne's solutions

#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> names;
    vector<int> scores;

    string n;
    int v;

    cout<<"Enter names and scores: \n";

    while (cin>>n>>v && n!="NoName") {	// read string int pair
		for (int i=0; i<names.size(); ++i)
			if (n==names[i]) error("duplicate: ",n); // chek for duplicate
		names.push_back(n);
		scores.push_back(v);
	}

	for (int i=0; i<names.size(); ++i)
			cout << '(' << names[i] << ',' << scores[i] << ")\n";

}