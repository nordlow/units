#pragma once

#ifndef __UNITS_SI_HPP__
#define __UNITS_SI_HPP__

#include "units.hpp"

/* See also https://en.wikipedia.org/wiki/International_System_of_Units
 */
namespace lego {

namespace units {

// define a base system
#define UNITS_BASE_DIMENSIONS 7

UNITS_MAKE_BASE_DIMENSION(length,_m,1);
template<> inline std::string name_string(const quantity<length>&) { return "Length"; }
template<> inline std::string unit_string(const quantity<length>&) { return "meter"; }
template<> inline std::string symbol_string(const quantity<length>&){ return "m"; }
UNITS_MAKE_BASE_DIMENSION(mass,_kg,2);
template<> inline std::string name_string(const quantity<mass>&) { return "Mass"; }
template<> inline std::string unit_string(const quantity<mass>&) { return "kilogram"; }
template<> inline std::string symbol_string(const quantity<mass>&){ return "kg"; }

UNITS_MAKE_BASE_DIMENSION(time,_s,3);
template<> inline std::string name_string(const quantity<time>&) { return "Time"; }
template<> inline std::string unit_string(const quantity<time>&) { return "second"; }
template<> inline std::string symbol_string(const quantity<time>&){ return "s"; }

UNITS_MAKE_BASE_DIMENSION(current,_A,4);
template<> inline std::string name_string(const quantity<current>&) { return "Current"; }
template<> inline std::string unit_string(const quantity<current>&) { return "Ampere"; }
template<> inline std::string symbol_string(const quantity<current>&){ return "A"; }
UNITS_MAKE_BASE_DIMENSION(temperature,_K,5);
template<> inline std::string name_string(const quantity<temperature>&) { return "Temperature"; }
template<> inline std::string unit_string(const quantity<temperature>&) { return "Kelvin"; }
template<> inline std::string symbol_string(const quantity<temperature>&){ return "K"; }
UNITS_MAKE_BASE_DIMENSION(amount_of_substance,_mol,6);
template<> inline std::string name_string(const quantity<amount_of_substance>&) { return "Amount of Substance"; }
template<> inline std::string unit_string(const quantity<amount_of_substance>&) { return "Molar"; }
template<> inline std::string symbol_string(const quantity<amount_of_substance>&){ return "mol"; }

UNITS_MAKE_BASE_DIMENSION(luminous_intensity,_cd,7);
template<> inline std::string name_string(const quantity<luminous_intensity>&) { return "Luminous Intensity"; }
template<> inline std::string unit_string(const quantity<luminous_intensity>&) { return "Candela"; }
template<> inline std::string symbol_string(const quantity<luminous_intensity>&){ return "cd"; }

UNITS_MAKE_SCALAR_DIMENSION(scalar);
inline std::string name_string(const quantity<scalar>&) { return "Scalar"; }
inline std::string unit_string(const quantity<scalar>&) { return "Dimensionless"; }
inline std::string symbol_string(const quantity<scalar>&){ return "N/A"; }

/* See also: https://en.wikipedia.org/wiki/International_System_of_Units#Derived_units
 */

UNITS_MAKE_DERIVED_DIMENSION(area,_m2,_m*_m);
template<> inline std::string name_string(const quantity<area>&) { return "Area"; }
template<> inline std::string unit_string(const quantity<area>&) { return "squaremeter"; }
template<> inline std::string symbol_string(const quantity<area>&){ return "m^2"; }
UNITS_MAKE_DERIVED_DIMENSION(volume,_m3,_m*_m*_m);
template<> inline std::string name_string(const quantity<volume>&) { return "Volume"; }
template<> inline std::string unit_string(const quantity<volume>&) { return "cubicmeter"; }
template<> inline std::string symbol_string(const quantity<volume>&){ return "m^3"; }

UNITS_MAKE_DERIVED_DIMENSION(angle_rad,_rad,_m/_m);
// TODO: Delay reduction until use
template<> inline std::string name_string(const quantity<angle_rad>&) { return "Angle"; }
template<> inline std::string unit_string(const quantity<angle_rad>&) { return "Radian"; }
template<> inline std::string symbol_string(const quantity<angle_rad>&){ return "rad"; }

/*! Degrees to Radians Conversion Factor. */
#define M_DEG2RAD (0.0174532925199433)
/*! Radians to Degrees Conversion Factor. */
#define M_RAD2DEG (57.2957795130823)

// Degrees need special handling
constexpr quantity<angle_rad> operator"" _deg( const long double value ) {
    return quantity<angle_rad>(value*M_DEG2RAD);
}
const quantity<angle_rad> _deg(M_DEG2RAD);

// TODO: Need special type and Delay reduction until use
/* UNITS_MAKE_DERIVED_DIMENSION(solid_angle,_sr,_m2/_m2); */
/* template<> inline std::string name_string(const quantity<solid_angle>&) { return "Solid Angle"; } */
/* template<> inline std::string unit_string(const quantity<solid_angle>&) { return "Sterdian"; } */
/* template<> inline std::string symbol_string(const quantity<solid_angle>&){ return "st"; } */

UNITS_MAKE_DERIVED_DIMENSION(density,_dens,_kg/_m3);
template<> inline std::string name_string(const quantity<density>&) { return "Density"; }
template<> inline std::string unit_string(const quantity<density>&) { return "kg/m3"; }
template<> inline std::string symbol_string(const quantity<density>&){ return "kg/m3"; }

UNITS_MAKE_DERIVED_DIMENSION(velocity,_mps,_m/_s);
template<> inline std::string name_string(const quantity<velocity>&) { return "Velocity"; }
template<> inline std::string unit_string(const quantity<velocity>&) { return "meters per second"; }
template<> inline std::string symbol_string(const quantity<velocity>&){ return "m/s"; }
UNITS_MAKE_DERIVED_DIMENSION(acceleration,_mps2,_m/(_s*_s));
template<> inline std::string name_string(const quantity<acceleration>&) { return "Acceleration"; }
template<> inline std::string unit_string(const quantity<acceleration>&) { return "meters per second squared"; }
template<> inline std::string symbol_string(const quantity<acceleration>&){ return "m/s^2"; }
UNITS_MAKE_DERIVED_DIMENSION(force,_N,_kg*_mps2);
template<> inline std::string name_string(const quantity<force>&) { return "Force"; }
template<> inline std::string unit_string(const quantity<force>&) { return "Newton"; }
template<> inline std::string symbol_string(const quantity<force>&){ return "N"; }
UNITS_MAKE_DERIVED_DIMENSION(energy,_J,_N*_m);
template<> inline std::string name_string(const quantity<energy>&) { return "Energy"; }
template<> inline std::string unit_string(const quantity<energy>&) { return "Joule"; }
template<> inline std::string symbol_string(const quantity<energy>&){ return "J"; }

/* Electric Potential in Volt */
UNITS_MAKE_DERIVED_DIMENSION(electric_potential,_V,_kg*(_m*_m)/(_s*_s*_s*_A));

/* UNITS_MAKE_DERIVED_DIMENSION(voltage,_V,_W/_A); */

UNITS_MAKE_DERIVED_DIMENSION(pressure,_Pa,_N/_m2);
template<> inline std::string name_string(const quantity<pressure>&) { return "Pressure"; }
template<> inline std::string unit_string(const quantity<pressure>&) { return "Pascal"; }
template<> inline std::string symbol_string(const quantity<pressure>&){ return "Pa"; }

UNITS_MAKE_DERIVED_DIMENSION(power,_W,_J/_s);
template<> inline std::string name_string(const quantity<power>&) { return "Power"; }
template<> inline std::string unit_string(const quantity<power>&) { return "Watt"; }
template<> inline std::string symbol_string(const quantity<power>&){ return "W"; }

UNITS_MAKE_DERIVED_DIMENSION(frequency,_Hz,1/_s);
inline std::string name_string(const quantity<frequency>&) { return "Frequency"; }
inline std::string unit_string(const quantity<frequency>&) { return "Hertz"; }
inline std::string symbol_string(const quantity<frequency>&){ return "Hz"; }

UNITS_MAKE_DERIVED_DIMENSION(electric_resistance,_Ohm,_V/_A);
template<> inline std::string name_string(const quantity<electric_resistance>&) { return "Electric Resistance"; }
template<> inline std::string unit_string(const quantity<electric_resistance>&) { return "Ohm"; }
template<> inline std::string symbol_string(const quantity<electric_resistance>&){ return "Ω"; }

UNITS_MAKE_DERIVED_DIMENSION(charge,_C,_s*_A);
template<> inline std::string name_string(const quantity<charge>&) { return "Electric Charge"; }
template<> inline std::string unit_string(const quantity<charge>&) { return "Coulomb"; }
template<> inline std::string symbol_string(const quantity<charge>&){ return "C"; }

UNITS_MAKE_DERIVED_DIMENSION(capacitance,_F,_C/_V);
template<> inline std::string name_string(const quantity<capacitance>&) { return "Electric Capacitance"; }
template<> inline std::string unit_string(const quantity<capacitance>&) { return "Farad"; }
template<> inline std::string symbol_string(const quantity<capacitance>&){ return "F"; }

UNITS_MAKE_DERIVED_DIMENSION(conductance,_S,_A/_V);
template<> inline std::string name_string(const quantity<conductance>&) { return "Electric Conductance"; }
template<> inline std::string unit_string(const quantity<conductance>&) { return "Siemens"; }
template<> inline std::string symbol_string(const quantity<conductance>&){ return "S"; }

/* See also: https://en.wikipedia.org/wiki/Weber_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(magnetic_flux,_Wb,_V*_S); // Weber
inline std::string name_string(const quantity<magnetic_flux>&) { return "Weber"; }
inline std::string unit_string(const quantity<magnetic_flux>&) { return "Weber"; }
inline std::string symbol_string(const quantity<magnetic_flux>&){ return "Wb"; }

/* See also: https://en.wikipedia.org/wiki/Tesla_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(magnetic_flux_density,_T,_Wb/_m2);
inline std::string name_string(const quantity<magnetic_flux_density>&) { return "Magnetic Flux"; }
inline std::string unit_string(const quantity<magnetic_flux_density>&) { return "Tesla"; }
inline std::string symbol_string(const quantity<magnetic_flux_density>&){ return "T"; }

/* See also: https://en.wikipedia.org/wiki/Henry_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(inductance,_H,_Ohm/_s); // Henry
inline std::string name_string(const quantity<inductance>&) { return "Inductance"; }
inline std::string unit_string(const quantity<inductance>&) { return "Henry"; }
inline std::string symbol_string(const quantity<inductance>&){ return "H"; }

UNITS_MAKE_DERIVED_DIMENSION(temperature_Celsius,_Celsius,1*_K); // Temperature relative to 273.15 K. TODO: Offset from 273.15
inline std::string name_string(const quantity<temperature_Celsius>&) { return "Temperature"; }
inline std::string unit_string(const quantity<temperature_Celsius>&) { return "Celsius"; }
inline std::string symbol_string(const quantity<temperature_Celsius>&){ return "C"; }

/* TODO: Activate when _sr type is is fixed. */
/* UNITS_MAKE_DERIVED_DIMENSION(lumen,_lm,_cd*_sr); */
/* inline std::string name_string(const quantity<lumen>&) { return "Lumen"; } */
/* inline std::string unit_string(const quantity<lumen>&) { return "Lumen"; } */
/* inline std::string symbol_string(const quantity<lumen>&){ return "T"; } */

/* TODO: Activate when _lm type is is fixed. */
/* UNITS_MAKE_DERIVED_DIMENSION(illuminance,_lx,_lm/_m2); */
/* inline std::string name_string(const quantity<illuminance>&) { return "Illuminance"; } */
/* inline std::string unit_string(const quantity<illuminance>&) { return "Lux"; } */
/* inline std::string symbol_string(const quantity<illuminance>&){ return "lx"; } */

UNITS_MAKE_DERIVED_DIMENSION(becquerel,_Bq,1/_s);
// TODO: This collides with Herz. Need explicit extra class for this
/* inline std::string name_string(const quantity<becquerel>&) { return "Decays per second"; } */
/* inline std::string unit_string(const quantity<becquerel>&) { return "Becquerel"; } */
/* inline std::string symbol_string(const quantity<becquerel>&){ return "Bq"; } */

UNITS_MAKE_DERIVED_DIMENSION(absorbed_dose,_Gy,_J/_kg);
inline std::string name_string(const quantity<absorbed_dose>&) { return "Absorbed Dose (of ionizing radiation)"; }
inline std::string unit_string(const quantity<absorbed_dose>&) { return "Gray"; }
inline std::string symbol_string(const quantity<absorbed_dose>&){ return "Gy"; }

UNITS_MAKE_DERIVED_DIMENSION(sievert,_Sv,_J/_kg); // Absorbed does (of ionizing radiation)
// TODO: This collides with Gray. Need explicit extra class for this
/* inline std::string name_string(const quantity<absorbed_dose>&) { return "Absorbed Dose (of ionizing radiation)"; } */
/* inline std::string unit_string(const quantity<absorbed_dose>&) { return "Sievert"; } */
/* inline std::string symbol_string(const quantity<absorbed_dose>&){ return "Sv"; } */

UNITS_MAKE_DERIVED_DIMENSION(catality_activity,_kat,_mol/_s);
inline std::string name_string(const quantity<catality_activity>&) { return "Illuminance"; }
inline std::string unit_string(const quantity<catality_activity>&) { return "Lux"; }
inline std::string symbol_string(const quantity<catality_activity>&){ return "lx"; }

}
}

#endif
