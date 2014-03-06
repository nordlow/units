#pragma once

#ifndef __UNITS_SI_HPP__
#define __UNITS_SI_HPP__

#include "units.hpp"

/* See also https://en.wikipedia.org/wiki/International_System_of_Units
 */
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

/* See also: https://en.wikipedia.org/wiki/International_System_of_Units#Derived_units
 */

UNITS_MAKE_DERIVED_DIMENSION(_area,_m2,_m*_m);
UNITS_MAKE_DERIVED_DIMENSION(_volume,_m3,_m*_m*_m);

UNITS_MAKE_DERIVED_DIMENSION(_angle,_rad,_m/_m); // Radian
UNITS_MAKE_DERIVED_DIMENSION(_solid_angle,_sr,_m2*_m2); // Sterdian

UNITS_MAKE_DERIVED_DIMENSION(_density,_dens,_kg/_m3);

UNITS_MAKE_DERIVED_DIMENSION(_velocity,_mps,_m/_s);
UNITS_MAKE_DERIVED_DIMENSION(_acceleration,_mps2,_m/(_s*_s));
UNITS_MAKE_DERIVED_DIMENSION(_force,_N,_kg*_mps2); // Newton
UNITS_MAKE_DERIVED_DIMENSION(_energy,_J,_N*_m); // Joule

/* Electric Potential in Volt */
UNITS_MAKE_DERIVED_DIMENSION(_electric_potential,_V,_kg*(_m*_m)/(_s*_s*_s*_A));
/* UNITS_MAKE_DERIVED_DIMENSION(_voltage,_V,_W/_A); */

UNITS_MAKE_DERIVED_DIMENSION(_resistance,_ohms,_V/_A); // Volt

UNITS_MAKE_DERIVED_DIMENSION(_pressure,_Pa,_N/_m2); // Pascal

UNITS_MAKE_DERIVED_DIMENSION(_power,_W,_J/_s); // Watt

UNITS_MAKE_DERIVED_DIMENSION(_frequency,_Hz,1/_s); // Hertz

UNITS_MAKE_DERIVED_DIMENSION(_charge,_C,_s*_A); // Electric Charge: Coulomb
UNITS_MAKE_DERIVED_DIMENSION(_capacitance,_F,_C/_V); // Electric Capacitance: Farad
UNITS_MAKE_DERIVED_DIMENSION(_resistance,_Ohm,_V/_A); // Electric Resistance
UNITS_MAKE_DERIVED_DIMENSION(_conductance,_S,_A/_V); // Siemens
UNITS_MAKE_DERIVED_DIMENSION(_weber,_Wb,_V*_S); // Weber
UNITS_MAKE_DERIVED_DIMENSION(_tesla,_T,_Wb/_m2); // Magnetic Flux: Tesla
UNITS_MAKE_DERIVED_DIMENSION(_inductance,_H,_Wb/_A); // Henry
UNITS_MAKE_DERIVED_DIMENSION(_deegree_Celsius,_Celsius,1*_K); // Temperature relative to 273.15 K. TODO: Offset from 273.15
UNITS_MAKE_DERIVED_DIMENSION(_lumen,_lm,_cd*_sr);
UNITS_MAKE_DERIVED_DIMENSION(_illuminance,_lx,_lm/_m2);
UNITS_MAKE_DERIVED_DIMENSION(_becquerel,_Bq,1/_s); // Decays per second
UNITS_MAKE_DERIVED_DIMENSION(_gray,_Gy,_J/_kg); // Absorbed does (of ionizing radiation)
UNITS_MAKE_DERIVED_DIMENSION(_sievert,_Sv,_J/_kg); // Absorbed does (of ionizing radiation)
UNITS_MAKE_DERIVED_DIMENSION(_katal,_kat,_mol/_s); // Catalytic activity

}
}

#endif
