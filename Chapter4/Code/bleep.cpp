// Bleep out words you don't like
//Will not run on git bash
#include "../../../std_lib_facilities.h"

bool bleep(vector<string> bad_words, string word)
{
    for(int i =0; i < bad_words.size();++i){
        if(word == bad_words[i]) return true;
    }
    return false;
}

int main()
{
    vector<string>disliked = {"Broccoli", "Pear", "Banana", "Tomato"};
    vector<string> words;

    cout<<"Please enter your favorite words:\n";
    for(string i; cin>>i;) //read
        words.push_back(i); //put into vector

    cout<<"Number of words: "<<words.size()<<"\n";

    int c = 0;
    for(int i=0; i < words.size(); ++i){

        if(bleep(disliked, words[i])){
            cout<<"BLEEP"<<"\n";
        } else
        {
            cout<<words[i]<<"\n";
        }
    }
}