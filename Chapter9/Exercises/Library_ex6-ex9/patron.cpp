#include "patron.h"

namespace Library_sys {

// ---------------------------------------------------------------------------
Patron::Patron(std::string nn, int cc, double ff)
    :n{nn}, c{cc}, f{ff}
{
}

void Patron::set_fees(double d)
{
    f = d;
}

}
