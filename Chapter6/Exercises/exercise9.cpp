#include "../../../std_lib_facilities.h"



int main()
try {
    vector<int> digit;		// collect digits here
	vector<string> unit;	// unit names go here
	unit.push_back(" ones ");
	unit.push_back(" tens ");
	unit.push_back(" hundreds ");;
	unit.push_back(" thousands ");
    
    cout<< "Enter an integer up to four digits long, followed by a semicolon ';'\n";
    
    char ch;
    while(cin>>ch){
        if(ch<'0' || ch>'9') break;
        digit.push_back(ch - '0');
    }

    if (digit.size()==0) error("no digits");
	if (unit.size()<digit.size()) error("Sorry, cannot handle that many digits");

    //Write the number
    for(int i = 0; i < digit.size(); ++i)
        cout<<digit[i];
    
    cout << " is ";

    // write the digits with their units
	// also compute the integer value:
	int num = 0;
	for (int i = 0; i<digit.size(); ++i) {
		if (digit[i])	// don't mention a unit if its count is zero
			cout << digit[i] << unit[digit.size()-i-1];
	}

    return 0;
}
catch(exception& e){
    cerr<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops: Uknown exception!";
    return 2;
}