#pragma once

#ifndef __UNITS_SI_HPP__
#define __UNITS_SI_HPP__

#include "units.hpp"

namespace lego { namespace units {

// define a base system
#define UNITS_BASE_DIMENSIONS 7

UNITS_MAKE_BASE_DIMENSION(_length,_m,1);
UNITS_MAKE_BASE_DIMENSION(_mass,_kg,2);
UNITS_MAKE_BASE_DIMENSION(_time,_s,3);

UNITS_MAKE_BASE_DIMENSION(_current,_A,4);
UNITS_MAKE_BASE_DIMENSION(_temperature,_K,5);
UNITS_MAKE_BASE_DIMENSION(_amount_of_substance,_mol,6);
UNITS_MAKE_BASE_DIMENSION(_luminous_intensity,_cd,7);

UNITS_MAKE_SCALAR_DIMENSION(_scalar);

UNITS_MAKE_DERIVED_DIMENSION(_velocity,_mps,_m/_s);
UNITS_MAKE_DERIVED_DIMENSION(_acceleration,_mps2,_m/(_s*_s));
UNITS_MAKE_DERIVED_DIMENSION(_force,_N,_kg*_mps2);
UNITS_MAKE_DERIVED_DIMENSION(_energy,_J,_N*_m);
UNITS_MAKE_DERIVED_DIMENSION(_electric_potential,_V,_kg*(_m*_m)/(_s*_s*_s*_A));
UNITS_MAKE_DERIVED_DIMENSION(_resistance,_ohms,_V/_A);

} // end namespace lego::units
} // end namespace lego

#endif // ifndef __UNITS_SI_HPP__
