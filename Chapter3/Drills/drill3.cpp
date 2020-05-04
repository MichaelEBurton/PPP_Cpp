#include "../../../std_lib_facilities.h"

int main()
{
    cout<<"Enter the name of the person you want to write to (followed by 'enter')\n";
    string first_name;
    cin>>first_name;
    
    cout<<"Please enter the name of another friend\n";
    string friend_name;
    cin>>friend_name;

    cout<<"Is this friend a male (m) or female (f)?";
    char friend_sex;
    cin>>friend_sex;
    
    cout<<"What is the recipients age?\n";
    int age=0;
    cin>>age;

    cout<<"Dear "<<first_name<<",\n"
        <<"\tHow are you? I am fine. I miss you and I'm so sorry"
        <<"I cannot sleep I cannot dream tonight, I need somebody and always.\n"
        <<"This sick strange darkness comes creeping on so haunting every time\n"
        <<"Have you seen "<<friend_name<<" lately?\n";

    if (friend_sex == 'm')
        cout<<"If you see "<<friend_name<<" please ask him to call me.\n";
     
    if (friend_sex == 'f')
        cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
     
    cout<<"I hear you just had a birthday and you are "<<age<<" years old.\n";
    
    if (age < 0 | age >= 110)
	    simple_error("You're kidding!");
     
    else if (age < 12)
	    cout<<"Next year you will be "<<age+1<<" years old.\n";
     
    else if (age == 17)
	    cout<<"Next year you will be able to vote\n";
     
    else if (age >=70)
	    cout<<"I hope you are enjoying retirement!\n";	
    

    cout<<"Yours sincerely, \n\n Michael";
}
