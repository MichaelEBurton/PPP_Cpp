#include "../../../std_lib_facilities.h"

int main()
{
    int number_of_words = 0;
    string previous = " "; // previous word; intialized to "not a word"
    string current;        // current word
    while(cin>>current){   // read a stream of words
        ++number_of_words;
	if(previous==current) // check if the word is the same as the last
            cout<<"word number "<<number_of_words
		<<" repeated: "<<current<<'\n';
	previous = current;
    }
}

