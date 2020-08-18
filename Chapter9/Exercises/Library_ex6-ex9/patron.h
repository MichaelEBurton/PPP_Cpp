#include "../../../../std_lib_facilities.h"

namespace Library_sys {

class Patron {
public:

    Patron(string n, int c, double f);
    Patron();

    string name() const {return n;}
    int card_number() const {return c;}
    double fees() const {return f;}

    void set_fees(double d);
    bool owes_fees(Patron& p);
private:
    string n;
    int c;
    double f;
};

}