#include "../../../std_lib_facilities.h"


// somewhere: make ist throw an exception if it goes bad:
ist.exceptions()|ios_base::badbit);

void end_of_loop(istream& is, char term, const string& message)
{
    if(ist.fail()) {    // use term as terminator and/or separator
        ist.clear();
        char ch;
        if(ist>>ch && ch == term) return;    // all is fine
        error(message);
    }
}

int main()
{
    // assume ist is in istream

    for(My_type var; ist>>var;) {    //read until end of file
        // maybe checck that var is valid
        // do something with var
    }
    end_of_loop(ist, '|', "bad termination of file");    // test if we can continue
    // carry on: we found end of file
}