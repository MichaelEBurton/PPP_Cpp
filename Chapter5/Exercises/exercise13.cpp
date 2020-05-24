// This is not working properly as of 5/24/20
// Not sure how to prevent repeating numbers

#include "../../../std_lib_facilities.h"

bool is_bull(vector<int> bc, int x, int index){
   if(bc[index] == x) return true;
   return false;
}

bool is_cow(vector<int> bc, int x, int index){
    for(int i = 0; i < bc.size(); ++i){
        if(i != index){
            if(bc[i] == x) return true;
        }
    }
    return false;
}

int main()
try{
    cout<<"Hello and welcome to Bulls and Cows! \n"
        <<"The game where you try and guess a four digit number (each digit is different) and only receive hints as to how many \"Bulls\" and \"Cow\" were in your guess\n"
        <<"\t + A Bull indicates that a number is in the correct position\n"
        <<"\t + A Cow indicates that you guess a correct number but it is in the wrong position\n\n"
        <<"Let's begin!\n";    

    int n = 0;
    cout<<"Please enter an integer to be used as a seed:\n";
    cin>>n;
    seed_randint(n);

    vector<int> bulls_and_cows;
    bulls_and_cows.push_back(randint(10));
    bulls_and_cows.push_back(randint(10));
    bulls_and_cows.push_back(randint(10));
    bulls_and_cows.push_back(randint(10));
    for(int x:bulls_and_cows){
        cout<<x;
    }
    char p = 'y';
    while(p == 'y'){
        vector<int> guesses;
        int cows = 0;
        int bulls = 0;
        int dummy = 0;
        cout<<"Please enter 4 integers in the range 0-9:\n";
        for(int i = 0; i < 4; ++i){                   // Get user to input 4 integers
            cin>>dummy;
            guesses.push_back(dummy);
            int dummy_bulls = 0;                                   // Dummy variable to store if the integer is a bull so it can't be a cow
            if(is_bull(bulls_and_cows, dummy, i)) {
                bulls += 1;
                dummy_bulls = 1;
            } else if(dummy_bulls == 0 && is_cow(bulls_and_cows, dummy, i)) cows += 1;
        }
        cout<<bulls<<" bulls and "<<cows<<" cows\n";
        if(bulls == 4){
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