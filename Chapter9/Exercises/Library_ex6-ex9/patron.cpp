#include "patron.h"

namespace Library_sys {

// ---------------------------------------------------------------------------
Patron::Patron(string nn, int cc, double ff)
    :n{nn}, c{cc}, f{ff}
{
}

void Patron::set_fees(double d)
{
    f = d;
}

bool Patron::owes_fees(Patron& p)
{
    if(p.fees() > 0.0) return true;
    return false;
}

}