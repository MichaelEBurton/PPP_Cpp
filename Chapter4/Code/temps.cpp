#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> words;
    for(string temp; cin>>temp;) //read
        words.push_back(temp); //put into vector
    cout<<"Number of words: "<<words.size()<<"\n";
    
    sort(words);

    for(int i=0; i < words.size(); ++i){
        if(i == 0 || words[i-1] != words[i])
            cout<<words[i]<<"\n";
    }
}