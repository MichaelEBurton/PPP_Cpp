#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> numeric = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string user_input = "";

    cout<<"Please enter a number (either spelled out or in numeric form):\n";

    cin>>user_input;

    bool is_numeric;

    for(int i; i < 10; ++i){
        if(user_input == digits[i]){
            is_numeric = false;
            cout<<"The number you entered ("<<user_input<<") in numeric form is: "<<i;
        } else if(user_input == numeric[i])
            cout<<"The number you entered ("<<user_input<<") spelled out is: "<<digits[i];
    }

    

}