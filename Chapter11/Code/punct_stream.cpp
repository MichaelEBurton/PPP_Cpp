/*
    Code from section 11.7.
    
    Punct_stream class for treating punctuation as whitespace.

*/

#include "../../../std_lib_facilities.h"

class Punct_stream {  // like an istream, but the user can add to
                      // the set of whitespace characters
public:
    Punct_stream(istream& is)
        : source{is}, sensitive{true} {}
    
    void whitespace(const string& s)      // make s the whitespace set
        {white = s;}
    void add_white(char c) {white += c;}  // add to the whitespace set
    bool is_whitespace(char c);
    void case_sensitive(bool b) {sensitive = b;}
    bool is_case_sensitive() {return sensitive;}

    Punct_stream& operator>>(string& s);
    operator bool();
private:
    istream& source;        // character source
    istringstream buffer;   // we let buffer do our formatting
    string white;           // characters considered "whitespace"
    bool sensitive;         // is the stream case-sensitive?
};

//==================================================================================================================================
// Punct_stream.cpp
Punct_stream& Punct_stream::operator>>(string& s)
{
    while(!(buffer>>s)) {                // try to read from buffer
        if(buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source, line);           // get a line from source

        // do character replacement as needed:
        for(char& ch:line)
            if(is_whitespace(ch))
                ch = ' ';                // to space
            else if(!sensitive)
                ch = tolower(ch);        // to lower case
            
        buffer.str(line);                // put string into stream
    }
    return *this;
}

bool Punct_stream::is_whitespace(char c)
{
    for(char w:white)
        if(c==w) return true;
    return false;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && buffer.good();
}
//==================================================================================================================================
// main.cpp

int main()
try{
    Punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");    // note \" means " in string
    ps.case_sensitive(false);

    cout<<"please enter words\n";
    vector<string> vs;
    for(string word; ps>>word;)
        vs.push_back(word);        // read words
    
    sort(vs.begin(), vs.end());    // sort in lexicographical order
    for(int i=0; i<vs.size(); ++i)
        if(i==0 || vs[i] != vs[i-1]) cout<< vs[i] <<'\n';
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