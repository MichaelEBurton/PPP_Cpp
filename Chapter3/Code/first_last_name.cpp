//read and write a first name
#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Please enter your first and last name followed by your age\n";
    string first_name = "???"; //string variable
    string last_name = "???"; 
    double age=0;           //integer variable  
    cin>>first_name>>last_name; //read a string
    cin>>age;          // read an integer
    age = age*12;
    cout<<"Hello, " <<first_name<<"  "<<last_name<<"(age in months"<<age<<")\n";
}
