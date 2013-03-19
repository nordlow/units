#include <iostream>
#include <complex>

#include "units_SI.hpp"

using namespace lego::units;

quantity<_energy>
work(const quantity<_force>& F, const quantity<_length>& dx)
{
    return F * dx; // Defines the relation: work = force * distance.
}

int main()
{
    /// Test calculation of work.
    quantity<_force>     F = 2.0_N; // Define a quantity of force.
    quantity<_length>    dx = 2.0_m;       // and a distance,
    quantity<_energy>    E = work(F,dx);    // and calculate the work done.

    std::cout << "F  = " << F << std::endl
              << "dx = " << dx << std::endl
              << "E  = " << E << std::endl
              << std::endl;

    /// Test and check complex quantities.
    typedef std::complex<double> complex_type; // double real and imaginary parts.

    // Define some complex electrical quantities.
    quantity<_electric_potential, complex_type> v = complex_type(12.5, 0.0) * _V;
    quantity<_current, complex_type>            i = complex_type(3.0, 4.0) * _A;
    quantity<_resistance, complex_type>         z = complex_type(1.5, -2.0) * _ohms;

    std::cout << "V   = " << v << std::endl
              << "I   = " << i << std::endl
              << "Z   = " << z << std::endl
              // Calculate from Ohm's law voltage = current * resistance.
              << "I * Z = " << i * z << std::endl
              // Check defined V is equal to calculated.
              << "I * Z == V? " << std::boolalpha << (i * z == v) << std::endl
              << std::endl;
    return 0;
}