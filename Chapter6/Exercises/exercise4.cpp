// Checked Bjarne's solutions

#include "../../../std_lib_facilities.h"

class Name_value {
    public:
        string name;
		int value;
};

int main()
{
	vector<Name_value> nv;

    string n;
    int v;

    cout<<"Enter names and scores: \n";

    while (cin>>n>>v && n!="NoName") {	// read string int pair

		for (int i=0; i<nv.size(); ++i)
			if (n == nv[i].name) error("duplicate: ",n); // chek for duplicate
		nv.push_back(Name_value{n ,v});
	}

	for (int i=0; i<nv.size(); ++i)
			cout << '(' << nv[i].name << ',' << nv[i].value << ")\n";

}