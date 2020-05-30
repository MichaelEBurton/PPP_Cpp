#include "../../../std_lib_facilities.h"

bool is_bull(vector<char> bc, char x, int index){
   if(bc[index] == x) return true;
   return false;
}

bool is_cow(vector<char> bc, char x, int index){
    for(int i = 0; i < bc.size(); ++i){
        if(i != index){
            if(bc[i] == x) return true;
        }
    }
    return false;
}

int main()
try{
    vector<char> bulls_and_cows = {'a', 'h', 'q', 'z'};
    cout<<"Hello and welcome to Bulls and Cows! \n"
        <<"The game where you try and guess a four letter string (each letter is different)"
        <<" and only receive hints as to how many \"Bulls\" and \"Cow\" were in your guess\n"
        <<"\t + A Bull indicates that a number is in the correct position\n"
        <<"\t + A Cow indicates that you guessed a correct letter but it is in the wrong position\n\n"
        <<"Let's begin!\n";    
    
    char p = 'y';
    while(p == 'y'){
        vector<char> guesses;
        int cows = 0;
        int bulls = 0;
        char dummy;
        cout<<"Please enter 4 alphabetic characters (a-z):\n";
        for(int i = 0; i < 4; ++i){                   // Get user to input 4 integers
            cin>>dummy;
            guesses.push_back(dummy);
            int dummy_bulls = 0;                                   // Dummy variable to store if the integer is a bull so it can't be a cow
            if(is_bull(bulls_and_cows, dummy, i)) {
                bulls += 1;
                dummy_bulls = 1;
            } else if(dummy_bulls == 0){                          // If not a bull check for cow
                if(is_cow(bulls_and_cows, dummy, i)) cows += 1;
            }
        }
        cout<<bulls<<" bulls and "<<cows<<" cows\n";
        if(bulls != 4){
            cout<<"Would you like to play again (y or n): ";
            cin>>p;
        } 
        else {
            cout<<"Congratulations, you've guess the correct number: ";
            for(int x:bulls_and_cows){
                cout<<x;
            }
            p = 'n';
        }
    }
    return 0;
}
catch(exception& e){
    cerr<<"error: "<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops: unknown exception!";
    return 2;
}