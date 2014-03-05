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
    quantity<_force>  F = 2.0_N; // Define a quantity of force.
    quantity<_length> dx = 2.0_m;       // and a distance,
    quantity<_energy> E = work(F,dx);    // and calculate the work done.

    const auto vel_ = 1.0_mps;
    const auto velx_ = 1.0_m / 1.0_s;
    const auto acc_ = 9.0_mps2;
    const auto area_ = 1.0_m2;
    const auto len_ = sqrt(area_);
    const auto area2_ = sqr(len_);
    const auto volume_ = 1.0_m3;
    const auto pressure_ = 1.0_N;
    const auto power_ = 1.0_W;

    const auto angle_ = 1.0_rad;
    const auto solid_angle_ = 1.0_sr;
    const auto y = std::sin(angle_);

    std::cout << "F  = " << F << std::endl
              << "dx = " << dx << std::endl
              << "E  = " << E << std::endl
              << std::endl;

    /// Test and check complex quantities.
    typedef std::complex<double> C; // double real and imaginary parts.

    // Define some complex electrical quantities.
    quantity<_electric_potential, C> v = C(12.5, 0.0) * _V;
    quantity<_current, C>            i = C(3.0, 4.0) * _A;
    quantity<_resistance, C>         z = C(1.5, -2.0) * _ohms;

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
