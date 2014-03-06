#pragma once

#ifndef __UNITS_SI_HPP__
#define __UNITS_SI_HPP__

#include "units.hpp"

/** See also https://en.wikipedia.org/wiki/International_System_of_Units
 */
namespace lego {

namespace units {

/** SI Base Units
 */
#define UNITS_BASE_DIMENSIONS 7

UNITS_MAKE_BASE_DIMENSION(length,_m,1);
template<> inline std::string name_string(const quantity<length>&) { return "Length"; }
template<> inline std::string unit_string(const quantity<length>&) { return "metre"; }
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

/** Derived SI Units
    See also: https://en.wikipedia.org/wiki/International_System_of_Units#Derived_units
    See also: https://en.wikipedia.org/wiki/SI_derived_unit
 */

UNITS_MAKE_DERIVED_DIMENSION(area,_m2,_m*_m);
template<> inline std::string name_string(const quantity<area>&) { return "Area"; }
template<> inline std::string unit_string(const quantity<area>&) { return "square metre"; }
template<> inline std::string symbol_string(const quantity<area>&){ return "m^2"; }
UNITS_MAKE_DERIVED_DIMENSION(volume,_m3,_m*_m*_m);
template<> inline std::string name_string(const quantity<volume>&) { return "Volume"; }
template<> inline std::string unit_string(const quantity<volume>&) { return "cubic metre"; }
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
constexpr quantity<angle_rad> operator"" _deg(const long double value) { return quantity<angle_rad>(value*M_DEG2RAD); } const quantity<angle_rad> _deg(M_DEG2RAD);

// TODO: Need special type and Delay reduction until use
/** UNITS_MAKE_DERIVED_DIMENSION(solid_angle,_sr,_m2/_m2); */
/** emplate<> inline std::string name_string(const quantity<solid_angle>&) { return "Solid Angle"; } */
/** emplate<> inline std::string unit_string(const quantity<solid_angle>&) { return "Sterdian"; } */
/** emplate<> inline std::string symbol_string(const quantity<solid_angle>&){ return "st"; } */

UNITS_MAKE_DERIVED_DIMENSION(area_density,_areadens,_kg/_m2);
template<> inline std::string name_string(const quantity<area_density>&) { return "Area Density"; }
template<> inline std::string unit_string(const quantity<area_density>&) { return "kg/m2"; }
template<> inline std::string symbol_string(const quantity<area_density>&){ return "kg/m2"; }

UNITS_MAKE_DERIVED_DIMENSION(volume_density,_dens,_kg/_m3);
template<> inline std::string name_string(const quantity<volume_density>&) { return "Volume/Mass Density"; }
template<> inline std::string unit_string(const quantity<volume_density>&) { return "kg/m3"; }
template<> inline std::string symbol_string(const quantity<volume_density>&){ return "kg/m3"; }

UNITS_MAKE_DERIVED_DIMENSION(specific_volume,_specvol,_m3/_kg);
template<> inline std::string name_string(const quantity<specific_volume>&) { return "Specific Volume"; }
template<> inline std::string unit_string(const quantity<specific_volume>&) { return "m3/kg"; }
template<> inline std::string symbol_string(const quantity<specific_volume>&){ return "m3/kg"; }

UNITS_MAKE_DERIVED_DIMENSION(velocity,_mps,_m/_s);
template<> inline std::string name_string(const quantity<velocity>&) { return "Velocity"; }
template<> inline std::string unit_string(const quantity<velocity>&) { return "metres per second"; }
template<> inline std::string symbol_string(const quantity<velocity>&){ return "m/s"; }

UNITS_MAKE_DERIVED_DIMENSION(acceleration,_mps2,_m/(_s*_s));
template<> inline std::string name_string(const quantity<acceleration>&) { return "Acceleration"; }
template<> inline std::string unit_string(const quantity<acceleration>&) { return "metres per second squared"; }
template<> inline std::string symbol_string(const quantity<acceleration>&){ return "m/s^2"; }

UNITS_MAKE_DERIVED_DIMENSION(jerk,_mps3,_m/(_s*_s*_s));
template<> inline std::string name_string(const quantity<jerk>&) { return "Jerk/Jolt/Surge"; }
template<> inline std::string unit_string(const quantity<jerk>&) { return "metres per second cubed"; }
template<> inline std::string symbol_string(const quantity<jerk>&){ return "m/s^3"; }

UNITS_MAKE_DERIVED_DIMENSION(snap,_mps4,_m/(_s*_s*_s*_s));
template<> inline std::string name_string(const quantity<snap>&) { return "Snap/Jounce"; }
template<> inline std::string unit_string(const quantity<snap>&) { return "m/s^4"; }
template<> inline std::string symbol_string(const quantity<snap>&){ return "m/s^4"; }

UNITS_MAKE_DERIVED_DIMENSION(force,_N,_kg*_mps2);
template<> inline std::string name_string(const quantity<force>&) { return "Force"; }
template<> inline std::string unit_string(const quantity<force>&) { return "Newton"; }
template<> inline std::string symbol_string(const quantity<force>&){ return "N"; }

/** See also: https://en.wikipedia.org/wiki/Momentum */
UNITS_MAKE_DERIVED_DIMENSION(momentum,_Ns,_N*_s);
template<> inline std::string name_string(const quantity<momentum>&) { return "Momentum/Impulse"; }
template<> inline std::string unit_string(const quantity<momentum>&) { return "Newton second"; }
template<> inline std::string symbol_string(const quantity<momentum>&){ return "Ns"; }

/** See also: https://en.wikipedia.org/wiki/Angular_momentum */
UNITS_MAKE_DERIVED_DIMENSION(angular_momentum,_Nms,_N*_m*_s);
template<> inline std::string name_string(const quantity<angular_momentum>&) { return "Angular Momentum"; }
template<> inline std::string unit_string(const quantity<angular_momentum>&) { return "Newton metre second"; }
template<> inline std::string symbol_string(const quantity<angular_momentum>&){ return "Nms"; }

/** See also: https://en.wikipedia.org/wiki/Torque */
UNITS_MAKE_DERIVED_DIMENSION(torque,_Nm,_N*_m);
/* TODO: We need new something new in order for this not to collied with angular_momentum. */
/* template<> inline std::string name_string(const quantity<torque>&) { return "Torque"; } */
/* template<> inline std::string unit_string(const quantity<torque>&) { return "Newton metre"; } */
/* template<> inline std::string symbol_string(const quantity<torque>&){ return "Nm"; } */

UNITS_MAKE_DERIVED_DIMENSION(energy,_J,_N*_m);
template<> inline std::string name_string(const quantity<energy>&) { return "Energy"; }
template<> inline std::string unit_string(const quantity<energy>&) { return "Joule"; }
template<> inline std::string symbol_string(const quantity<energy>&){ return "J"; }

UNITS_MAKE_DERIVED_DIMENSION(action,_Js,_J*_s);
/* template<> inline std::string name_string(const quantity<action>&) { return "Action"; } */
/* template<> inline std::string unit_string(const quantity<action>&) { return "Joule second"; } */
/* template<> inline std::string symbol_string(const quantity<action>&){ return "J*s"; } */

UNITS_MAKE_DERIVED_DIMENSION(yank,_Nps,_N/_s);
template<> inline std::string name_string(const quantity<yank>&) { return "Jank"; }
template<> inline std::string unit_string(const quantity<yank>&) { return "Newton per second"; }
template<> inline std::string symbol_string(const quantity<yank>&){ return "N/s"; }

/** Electric Potential in Volt */
UNITS_MAKE_DERIVED_DIMENSION(electric_potential,_V,_kg*(_m*_m)/(_s*_s*_s*_A));

/** UNITS_MAKE_DERIVED_DIMENSION(voltage,_V,_W/_A); */

UNITS_MAKE_DERIVED_DIMENSION(pressure,_Pa,_N/_m2);
template<> inline std::string name_string(const quantity<pressure>&) { return "Pressure"; }
template<> inline std::string unit_string(const quantity<pressure>&) { return "Pascal"; }
template<> inline std::string symbol_string(const quantity<pressure>&){ return "Pa"; }

UNITS_MAKE_DERIVED_DIMENSION(power,_W,_J/_s);
template<> inline std::string name_string(const quantity<power>&) { return "Power"; }
template<> inline std::string unit_string(const quantity<power>&) { return "Watt"; }
template<> inline std::string symbol_string(const quantity<power>&){ return "W"; }

UNITS_MAKE_DERIVED_DIMENSION(wavenumber,_wavenumber,1/_m);
inline std::string name_string(const quantity<wavenumber>&) { return "Wavenumber"; }
inline std::string unit_string(const quantity<wavenumber>&) { return "reciprocal metre"; }
inline std::string symbol_string(const quantity<wavenumber>&){ return "1/m"; }

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

/** See also: https://en.wikipedia.org/wiki/Weber_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(magnetic_flux,_Wb,_V*_S); // Weber
inline std::string name_string(const quantity<magnetic_flux>&) { return "Weber"; }
inline std::string unit_string(const quantity<magnetic_flux>&) { return "Weber"; }
inline std::string symbol_string(const quantity<magnetic_flux>&){ return "Wb"; }

/** See also: https://en.wikipedia.org/wiki/Maxwell_(unit) */
constexpr quantity<magnetic_flux> operator"" _Mx( const long double value ) {
    return quantity<magnetic_flux>(1e-8*value);
}
const quantity<magnetic_flux> _Mx(1e-8);

/** See also: https://en.wikipedia.org/wiki/Tesla_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(magnetic_flux_density,_T,_Wb/_m2);
inline std::string name_string(const quantity<magnetic_flux_density>&) { return "Magnetic Flux"; }
inline std::string unit_string(const quantity<magnetic_flux_density>&) { return "Tesla"; }
inline std::string symbol_string(const quantity<magnetic_flux_density>&){ return "T"; }

/** See also: https://en.wikipedia.org/wiki/Henry_(unit) */
UNITS_MAKE_DERIVED_DIMENSION(inductance,_H,_Ohm/_s); // Henry
inline std::string name_string(const quantity<inductance>&) { return "Inductance"; }
inline std::string unit_string(const quantity<inductance>&) { return "Henry"; }
inline std::string symbol_string(const quantity<inductance>&){ return "H"; }

UNITS_MAKE_DERIVED_DIMENSION(temperature_Celsius,_Celsius,1*_K); // Temperature relative to 273.15 K. TODO: Offset from 273.15
inline std::string name_string(const quantity<temperature_Celsius>&) { return "Temperature"; }
inline std::string unit_string(const quantity<temperature_Celsius>&) { return "Celsius"; }
inline std::string symbol_string(const quantity<temperature_Celsius>&){ return "C"; }

/** ODO: Activate when _sr type is is fixed. */
/** UNITS_MAKE_DERIVED_DIMENSION(lumen,_lm,_cd*_sr); */
/** inline std::string name_string(const quantity<lumen>&) { return "Lumen"; } */
/** inline std::string unit_string(const quantity<lumen>&) { return "Lumen"; } */
/** inline std::string symbol_string(const quantity<lumen>&){ return "T"; } */

/** ODO: Activate when _lm type is is fixed. */
/** UNITS_MAKE_DERIVED_DIMENSION(illuminance,_lx,_lm/_m2); */
/** inline std::string name_string(const quantity<illuminance>&) { return "Illuminance"; } */
/** inline std::string unit_string(const quantity<illuminance>&) { return "Lux"; } */
/** inline std::string symbol_string(const quantity<illuminance>&){ return "lx"; } */

UNITS_MAKE_DERIVED_DIMENSION(becquerel,_Bq,1/_s);
// TODO: This collides with Herz. Need explicit extra class for this
/** inline std::string name_string(const quantity<becquerel>&) { return "Decays per second"; } */
/** inline std::string unit_string(const quantity<becquerel>&) { return "Becquerel"; } */
/** inline std::string symbol_string(const quantity<becquerel>&){ return "Bq"; } */

UNITS_MAKE_DERIVED_DIMENSION(absorbed_dose,_Gy,_J/_kg);
inline std::string name_string(const quantity<absorbed_dose>&) { return "Absorbed Dose (of ionizing radiation)"; }
inline std::string unit_string(const quantity<absorbed_dose>&) { return "Gray"; }
inline std::string symbol_string(const quantity<absorbed_dose>&){ return "Gy"; }

UNITS_MAKE_DERIVED_DIMENSION(sievert,_Sv,_J/_kg); // Absorbed does (of ionizing radiation)
// TODO: This collides with Gray. Need explicit extra class for this
/** inline std::string name_string(const quantity<absorbed_dose>&) { return "Absorbed Dose (of ionizing radiation)"; } */
/** inline std::string unit_string(const quantity<absorbed_dose>&) { return "Sievert"; } */
/** inline std::string symbol_string(const quantity<absorbed_dose>&){ return "Sv"; } */

UNITS_MAKE_DERIVED_DIMENSION(catality_activity,_kat,_mol/_s);
inline std::string name_string(const quantity<catality_activity>&) { return "Illuminance"; }
inline std::string unit_string(const quantity<catality_activity>&) { return "Lux"; }
inline std::string symbol_string(const quantity<catality_activity>&){ return "lx"; }

/** Non-SI units mentioned in the SI
   https://en.wikipedia.org/wiki/Non-SI_units_accepted_for_use_with_SI
*/
constexpr quantity<time>   operator"" _minute(const long double value) { return quantity<time>  (value/60); }   const quantity<time> _minute(1.0/60);
constexpr quantity<time>   operator"" _hour  (const long double value) { return quantity<time>  (value/3600); } const quantity<time> _hour(1.0/3600);
constexpr quantity<time>   operator"" _day  (const long double value) { return quantity<time>  (value/(3600*24)); } const quantity<time> _day(1.0/(3600*24));

/** See also: https://en.wikipedia.org/wiki/Litre */
constexpr quantity<volume> operator"" _litre (const long double value) { return quantity<volume>(value*1e-3); }   const quantity<volume> _litre(1e-3);
/** See also: https://en.wikipedia.org/wiki/Tonne */
constexpr quantity<mass>   operator"" _tonne (const long double value) { return quantity<mass>  (value*1e+3); }   const quantity<volume> _tonne(1e+3);

/* See also: https://en.wikipedia.org/wiki/Electronvolt */
constexpr quantity<energy>   operator"" _eV  (const long double value) { return quantity<energy>  (value*1.60217656535e-19); } const quantity<energy> _eV(1.60217656535e-19);

/* See also: https://en.wikipedia.org/wiki/Foot_(unit) */
constexpr quantity<length>   operator"" _ft  (const long double value) { return quantity<length>  (value*0.3048); } const quantity<length> _ft(0.3048);

/* See also: https://en.wikipedia.org/wiki/Yard */
constexpr quantity<length>   operator"" _yd  (const long double value) { return quantity<length>  (value*0.9144); } const quantity<length> _yd(0.9144);

}
}

#endif
