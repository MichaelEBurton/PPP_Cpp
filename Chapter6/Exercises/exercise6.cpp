#include "../../../std_lib_facilities.h"

class String_stream{
    public:
        string get();
        void putback(string s);
    private:
        bool full = false;
        string buffer = "";
};

void String_stream::putback(string s){
    if(full) error("putback() into a full buffer");
    buffer = s;
    full = true;
}

string String_stream::get(){
    if(full){
        full = false;
        return buffer;
    }

    string s;
    cin >> s;

    return s;
}

String_stream stream;

bool verb(string s){
    if(s == "rules" || s == "fly" || s == "swim") return true;
    return false;
}

bool noun(string s){
    if(s == "birds" || s == "fish" || s == "C++") return true;
    return false;
}

bool conjunction(string s){
    if(s == "and" || s == "or" || s == "but") return true;
    return false;
}

bool sentence()
{
	string s = stream.get();
	if (!noun(s)) return false;

	string s2 = stream.get();
	if (!verb(s2)) return false;

	string s3 = stream.get();
	if (s3 == ".") return true;	// end of sentence
	if (!conjunction(s3)) return false;	// not end of sentence and not conjunction
	return sentence();	// look for another sentence
}

int main()
try {
    cout << "enter a sentence of the simplified grammar (terminated by a dot):\n";

	while (cin) {
			bool b = sentence();
			if (b)
				cout << "OK\n";
			else
				cout << "not OK\n";
			cout << "Try again: ";
	}
}
catch(exception& e){
    cerr<<e.what();
    return 1;
}
catch(...){
    cerr<<"Oops, unknown exception";
    return 2;
}