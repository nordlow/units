#ifndef __UNITS_EV_K_NM_FS_E0_HPP__
#define __UNITS_EV_K_NM_FS_E0_HPP__

#include "units.hpp"

namespace lego
{   namespace units
    {

// define a base system
#define UNITS_BASE_DIMENSIONS 5

UNITS_MAKE_BASE_DIMENSION(_energy,_eV,1);
UNITS_MAKE_BASE_DIMENSION(_temperature,_K,2);
UNITS_MAKE_BASE_DIMENSION(_length,_nm,3);
UNITS_MAKE_BASE_DIMENSION(_time,_fs,4);
UNITS_MAKE_BASE_DIMENSION(_charge,_e0,4);

UNITS_MAKE_SCALAR_DIMENSION(_scalar);
    } // end namespace lego::units
} // end namespace lego

#endif // ifndef __UNITS_EV_K_NM_FS_E0_HPP__
