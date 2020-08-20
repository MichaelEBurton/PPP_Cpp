
#include <string>

namespace Library_sys {

class Patron {
public:

    Patron(std::string n, int c, double f);
    Patron();

    std::string name() const {return n;}
    int card_number() const {return c;}
    double fees() const {return f;}

    void set_fees(double d);
    bool owes_fees() const {return f > 0.0;}

private:
    std::string n;
    int c;
    double f;
};

}