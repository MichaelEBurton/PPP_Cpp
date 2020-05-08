// Bleep out words you don't like
//Will not run on git bash
#include "../../../std_lib_facilities.h"

int main()
{
    string disliked = "Broccoli";

    vector<string> words;
    for(string i; cin>>i;) //read
        words.push_back(i); //put into vector
    cout<<"Number of words: "<<words.size()<<"\n";

    for(int i=0; i < words.size(); ++i){
        if(words[i] != disliked)
            cout<<words[i]<<"\n";
        else
            cout<<"BLEEP"<<"\n";
    }
}