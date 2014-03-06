
#ifdef __clang__
typedef struct { double x, y; } __float128;
extern "C" { extern char *gets(char *__s) { return 0; }; }
#endif

#include <iostream>
#include <complex>
#include <cmath>
#include <cassert>

#include "units_SI.hpp"

using namespace std;
using namespace lego::units;

quantity<energy>
work(const quantity<force>& F,
     const quantity<length>& dx)
{
    return F * dx; // Defines the relation: work = force * distance.
}

int main()
{
    /// Test calculation of work.
    quantity<force>  F = 2.0_N; // Define a quantity of force.
    quantity<length> dx = 2.0_m;       // and a distance,
    quantity<energy> E = work(F,dx);    // and calculate the work done.

    const auto vel_ = 1.0_mps;
    cout << vel_ << endl;

    const auto velx_ = 1.0_m / 1.0_s;
    cout << velx_ << endl;

    const auto acc_ = 9.0_mps2;
    cout << acc_ << endl;

    const auto area_ = 1.0_m2;
    cout << area_ << endl;

    const auto len_ = sqrt(area_);
    cout << len_ << endl;

    const auto area2_ = sqr(len_);
    cout << area2_ << endl;

    const auto volume_ = 1.0_m3;
    cout << volume_ << endl;

    const auto vlen_ = cbrt(volume_);
    cout << vlen_ << endl;

    const auto pressure_ = 1.0_N;
    cout << pressure_ << endl;

    const auto power_ = 1.0_W;
    cout << power_ << endl;

    const auto angle_ = 1.0_rad + 1.0_rad;
    cout << angle_ << endl;
    assert(angle_ == 2);

    const auto angle_deg_ = 360.0_deg;
    assert(angle_deg_ == 360.0*_deg);
    cout << angle_deg_ << endl;

    /* TODO: Activate */
    /* const auto solid_angle_ = 1.0_sr; */
    /* cout << solid_angle_ << endl; */

    /* Trigonometry */
    cout << sin(angle_) << endl;
    cout << cos(angle_) << endl;
    cout << tan(angle_) << endl;

    /* const auto xxx = area_ + len_; */

    cout << "F  = " << F << endl
         << "dx = " << dx << endl
         << "E  = " << E << endl
         << endl;

    /// Test and check complex quantities.
    typedef std::complex<double> C; // double real and imaginary parts.

    // Define some complex electrical quantities.
    auto v = C(12.5, 0.0) * _V;
    auto i = C(3.0, 4.0) * _A;
    auto z = C(1.5, -2.0) * _Ohm;

    cout << "V   = " << v << endl
         << "I   = " << i << endl
         << "Z   = " << z << endl
        // Calculate from Ohm's law voltage = current * resistance.
         << "I * Z = " << i * z << endl
        // Check defined V is equal to calculated.
         << "I * Z == V: " << std::boolalpha << (i * z == v) << endl
         << endl;
    return 0;
}
