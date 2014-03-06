#pragma once

#ifndef __UNITS_SI_HPP__
#define __UNITS_SI_HPP__

#include "units.hpp"

/* See also https://en.wikipedia.org/wiki/International_System_of_Units
 */
namespace lego {

template<class T> inline std::string name_string(const T&) { return "unknown"; }
template<class T> inline std::string symbol_string(const T&) { return "unknown"; }

namespace units {

// define a base system
#define UNITS_BASE_DIMENSIONS 7

UNITS_MAKE_BASE_DIMENSION(length,_m,1);
UNITS_MAKE_BASE_DIMENSION(mass,_kg,2);

UNITS_MAKE_BASE_DIMENSION(time,_s,3);

UNITS_MAKE_BASE_DIMENSION(current,_A,4);
UNITS_MAKE_BASE_DIMENSION(temperature,_K,5);
UNITS_MAKE_BASE_DIMENSION(amount_of_substance,_mol,6);
UNITS_MAKE_BASE_DIMENSION(luminous_intensity,_cd,7);

UNITS_MAKE_SCALAR_DIMENSION(scalar);

/* See also: https://en.wikipedia.org/wiki/International_System_of_Units#Derived_units
 */

UNITS_MAKE_DERIVED_DIMENSION(area,_m2,_m*_m);
UNITS_MAKE_DERIVED_DIMENSION(volume,_m3,_m*_m*_m);

UNITS_MAKE_DERIVED_DIMENSION(angle,_rad,_m/_m); // Radian
UNITS_MAKE_DERIVED_DIMENSION(solid_angle,_sr,_m2*_m2); // Sterdian

UNITS_MAKE_DERIVED_DIMENSION(density,_dens,_kg/_m3);

UNITS_MAKE_DERIVED_DIMENSION(velocity,_mps,_m/_s);
UNITS_MAKE_DERIVED_DIMENSION(acceleration,_mps2,_m/(_s*_s));
UNITS_MAKE_DERIVED_DIMENSION(force,_N,_kg*_mps2); // Newton
UNITS_MAKE_DERIVED_DIMENSION(energy,_J,_N*_m); // Joule

/* Electric Potential in Volt */
UNITS_MAKE_DERIVED_DIMENSION(electric_potential,_V,_kg*(_m*_m)/(_s*_s*_s*_A));
/* UNITS_MAKE_DERIVED_DIMENSION(voltage,_V,_W/_A); */

UNITS_MAKE_DERIVED_DIMENSION(resistance,_Ohm,_V/_A); // Electric Resistance

UNITS_MAKE_DERIVED_DIMENSION(pressure,_Pa,_N/_m2); // Pascal

UNITS_MAKE_DERIVED_DIMENSION(power,_W,_J/_s); // Watt
/* inline std::string name_string(const _power&) { return "Power"; } */
/* inline std::string unit_string(const _power&) { return "Watt"; } */
/* inline std::string symbol_string(const _power::type&){ return "W"; } */

UNITS_MAKE_DERIVED_DIMENSION(frequency,_Hz,1/_s); // Hertz

UNITS_MAKE_DERIVED_DIMENSION(charge,_C,_s*_A); // Electric Charge: Coulomb
UNITS_MAKE_DERIVED_DIMENSION(capacitance,_F,_C/_V); // Electric Capacitance: Farad
UNITS_MAKE_DERIVED_DIMENSION(conductance,_S,_A/_V); // Siemens
UNITS_MAKE_DERIVED_DIMENSION(weber,_Wb,_V*_S); // Weber
UNITS_MAKE_DERIVED_DIMENSION(tesla,_T,_Wb/_m2); // Magnetic Flux: Tesla
UNITS_MAKE_DERIVED_DIMENSION(inductance,_H,_Wb/_A); // Henry
UNITS_MAKE_DERIVED_DIMENSION(deegree_Celsius,_Celsius,1*_K); // Temperature relative to 273.15 K. TODO: Offset from 273.15
UNITS_MAKE_DERIVED_DIMENSION(lumen,_lm,_cd*_sr);
UNITS_MAKE_DERIVED_DIMENSION(illuminance,_lx,_lm/_m2);
UNITS_MAKE_DERIVED_DIMENSION(becquerel,_Bq,1/_s); // Decays per second
UNITS_MAKE_DERIVED_DIMENSION(gray,_Gy,_J/_kg); // Absorbed does (of ionizing radiation)
UNITS_MAKE_DERIVED_DIMENSION(sievert,_Sv,_J/_kg); // Absorbed does (of ionizing radiation)
UNITS_MAKE_DERIVED_DIMENSION(katal,_kat,_mol/_s); // Catalytic activity

// gray and sievert are indistinguishable
/* inline std::string name_string(const reduce_unit<si::absorbed_dose>::type&) { return "gray"; } */
/* inline std::string symbol_string(const reduce_unit<si::absorbed_dose>::type&) { return "Gy"; } */

/* // activity and frequency are indistinguishable - would need a "decays" base unit */
/* //inline std::string name_string(const si::activity&) { return "becquerel"; } */
/* //inline std::string symbol_string(const si::activity&) { return "Bq"; } */

/* inline std::string name_string(const reduce_unit<si::capacitance>::type&)   { return "farad"; } */
/* inline std::string symbol_string(const reduce_unit<si::capacitance>::type&) { return "F"; } */

/* inline std::string name_string(const reduce_unit<si::catalytic_activity>::type&) { return "katal"; } */
/* inline std::string symbol_string(const reduce_unit<si::catalytic_activity>::type&) { return "kat"; } */

/* inline std::string name_string(const reduce_unit<si::conductance>::type&) { return "siemen"; } */
/* inline std::string symbol_string(const reduce_unit<si::conductance>::type&) { return "S"; } */

/* // gray and sievert are indistinguishable */
/* //inline std::string name_string(const si::dose_equivalent&) { return "sievert"; } */
/* //inline std::string symbol_string(const si::dose_equivalent&) { return "Sv"; } */

/* inline std::string name_string(const reduce_unit<si::electric_charge>::type&) { return "coulomb"; } */
/* inline std::string symbol_string(const reduce_unit<si::electric_charge>::type&) { return "C"; } */

/* inline std::string name_string(const reduce_unit<si::electric_potential>::type&) { return "volt"; } */
/* inline std::string symbol_string(const reduce_unit<si::electric_potential>::type&) { return "V"; } */

/* inline std::string name_string(const reduce_unit<si::energy>::type&) { return "joule"; } */
/* inline std::string symbol_string(const reduce_unit<si::energy>::type&) { return "J"; } */

/* inline std::string name_string(const reduce_unit<si::force>::type&) { return "newton"; } */
/* inline std::string symbol_string(const reduce_unit<si::force>::type&) { return "N"; } */

/* inline std::string name_string(const reduce_unit<si::frequency>::type&) { return "hertz"; } */
/* inline std::string symbol_string(const reduce_unit<si::frequency>::type&) { return "Hz"; } */

/* inline std::string name_string(const reduce_unit<si::illuminance>::type&) { return "lux"; } */
/* inline std::string symbol_string(const reduce_unit<si::illuminance>::type&) { return "lx"; } */

/* inline std::string name_string(const reduce_unit<si::inductance>::type&) { return "henry"; } */
/* inline std::string symbol_string(const reduce_unit<si::inductance>::type&) { return "H"; } */

/* inline std::string name_string(const reduce_unit<si::luminous_flux>::type&) { return "lumen"; } */
/* inline std::string symbol_string(const reduce_unit<si::luminous_flux>::type&) { return "lm"; } */

/* inline std::string name_string(const reduce_unit<si::magnetic_flux>::type&) { return "weber"; } */
/* inline std::string symbol_string(const reduce_unit<si::magnetic_flux>::type&) { return "Wb"; } */

/* inline std::string name_string(const reduce_unit<si::magnetic_flux_density>::type&) { return "tesla"; } */
/* inline std::string symbol_string(const reduce_unit<si::magnetic_flux_density>::type&) { return "T"; } */

/* inline std::string name_string(const reduce_unit<si::pressure>::type&) { return "pascal"; } */
/* inline std::string symbol_string(const reduce_unit<si::pressure>::type&) { return "Pa"; } */

/* inline std::string name_string(const reduce_unit<si::resistance>::type&) { return "ohm"; } */
/* inline std::string symbol_string(const reduce_unit<si::resistance>::type&) { return "Ohm"; } */


}
}

#endif
