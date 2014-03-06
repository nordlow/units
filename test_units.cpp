
#include <iostream>
#include <cmath>
#include "units_eV-K-nm-fs-e0.hpp"

using namespace std;

using namespace lego::units;
namespace units = lego::units;
// using namespace lego::meta::rationals;

template < typename D, typename T >
void print_type( quantity< D, T > qty )
{
    cout << D()
         << " ("
         << size(D())
         << ")" <<endl;
}

int main ()
{
    quantity<_energy> e1 = 0.5_eV, e2 = 2.0_eV;
    quantity<_time>   t1 = 1.0_fs;

    auto c = e1 / e2 * t1;
    cout << get_dimension< decltype(c) >::type() << endl;
    print_type( c );
    cout << c << endl;

    auto d = sqrt( c );
    cout << d << endl;
    print_type( d );

    // auto d = e1 + t1; // compiler-error: energy + time  = invalid

    cout << "done." << endl;
    return 0;
}
// eof
