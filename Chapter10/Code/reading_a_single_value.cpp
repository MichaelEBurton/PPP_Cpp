#include "../../../std_lib_facilities.h"

void skip_to_int()
{
    if(cin.fail()) {    // we found something that wasn't an integer
        cin.clear();    // we'd like to look at the characters
        for(char ch; cin>>ch;) {    // throw away non-digits
            if(isdigit(ch) || ch == '-') {
                cin.unget();    // put the digit back
                                // so that we can read the number
                return;
            }
        }
    }
    error("no input");          // eof or bad: give up
}

int get_int()
{
    int n = 0;
    while(true) {
        if(cin>>n) return n;
        cout << "Sorry, that was not a number; please try again\n";
        skip_to_int();
    }
}

int get_int(int low, int high, const string& greeting, const string& sorry) {
    cout<<greeting<<": ["<<low<<':'<<high<<"]\n";
    
    while(true) {
        int n = get_int();
        if(low <= n && n <= high) return n;
        cout <<sorry<<": ["<<low<<':'<<high<<"]\n";
    }
}

int main(){
    int n = get_int(1,10, "Please enter an integer in range", "Please try again\n");
    cout<<"n: "<<n<<'\n';

    int m = get_int(2,300, "Please enter an integer in range", "Please try again\n");
    cout<<"m: "<<m<<'\n';
    // if we get here n is in [1:10]
}