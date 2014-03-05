#include <iostream>
#include <complex>
#include <cmath>

#include "units_SI.hpp"

using namespace std;
using namespace lego::units;

quantity<_energy>
work(const quantity<_force>& F, const quantity<_length>& dx)
{
    return F * dx; // Defines the relation: work = force * distance.
}

int main()
{
    /// Test calculation of work.
    quantity<_force>  F = 2.0*_N; // Define a quantity of force.
    return 0;
}
