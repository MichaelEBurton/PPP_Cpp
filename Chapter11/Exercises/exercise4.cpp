/*
    Exercise 4: Write a program called multi_input.cpp that prompts the user to enter several integers in any combination
                of octal, decimal, or hexadecimal, using the 0 and 0x base suffixes; interprets the numbers correctly; and 
                converts them to decimal form. Then your program should output the values in properly spaced columns like this:

                0x43 hexadecimal converts to 67 decimal
                0123 octal       converts to 83 decimal
                  65 decimal     converts to 65 decimal
*/

#include "../../../std_lib_facilities.h"
int main()
try{
    cout<<"Please enter several integers in either octal, decimal, or hexadecimal notation: ";

    while(cin)
    {
        string number;
        cin>>number;

        stringstream ss{number};
        ss.unsetf(ios::dec);
        ss.unsetf(ios::hex);
        ss.unsetf(ios::oct);
        cout<<showbase;

        int value;
        ss>>value;

        if(number[0] == '0' && number[1] == 'x')
            cout<<setw(12)<<hex<<value<<" hexadecimal "<<"converts to "<<dec<<setw(12)<<value<<" decimal\n";
        else if(number[0] == '0')
            cout<<setw(12)<<oct<<value<<" octal "<<setw(18)<<"converts to "<<dec<<setw(12)<<value<<" decimal\n";
        else
            cout<<setw(12)<<dec<<value<<" decimal "<<setw(16)<<"converts to "<<dec<<setw(12)<<value<<" decimal\n";
    }

    return 0;
}
catch(exception& e) {
    cerr<<"Error: "<<e.what()<<'\n';
    return 1;
}
catch(...){
    cerr<<"Oops, unknown error!";
    return 2;
}