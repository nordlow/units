#pragma once

#ifndef __UNITS_HPP__
#define __UNITS_HPP__

#include <cmath>
#include "list.hpp"
#include "rationals.hpp"
#include "cc_features.h"

// ---------------------------------------------------------------------------
namespace lego { namespace units {
// ---------------------------------------------------------------------------

using namespace lego::meta::list;
using namespace lego::meta::rationals;

// generate dimension lists
template <int BaseDims, int N>
using make_base_dimension
    = typename append_n<
            typename append_n<
                typename append_n<
                    list<>, N-1, rational<0,1>
                >::type, 1, rational<1,1>
            >::type, BaseDims-N, rational<0,1>
        >::type;


template <int BaseDims>
using make_scalar_dimension
    = typename append_n< list<>, BaseDims, rational<0,1> >::type;


// get dimension type from quantity
template <typename Quantity>
struct get_dimension {};
template <template <typename,typename> class Q, typename D, typename T>
struct get_dimension< Q<D,T> >
{ using type = D; };


// requires UNITS_BASE_DIMENSIONS to be set to the number of dimensions
#define UNITS_MAKE_BASE_DIMENSION(name,unit,id) \
    using name = make_base_dimension< UNITS_BASE_DIMENSIONS, id >; \
    constexpr quantity<name> operator"" unit( long double value ) \
    { return quantity<name>(value); }; \
    const quantity<name> unit(1.0);
// end UNITS_MAKE_BASE_DIMENSION
// need to be called after UNITS_BASE_DIMENSIONS has been defined
#define UNITS_MAKE_SCALAR_DIMENSION(name) \
    using name = make_scalar_dimension< UNITS_BASE_DIMENSIONS >; \
    template <typename T> \
    struct quantity<name,T> \
    { \
        constexpr quantity() : _value() {} \
        constexpr quantity( T x ) : _value(x) {} \
    /* implicit conversion to T operator */ \
        operator T() const { return value(); } \
        T value() const { return _value; } \
    private: \
        T _value;\
    }; \
// end UNITS_MAKE_SCALAR_DIMENSION

#define UNITS_MAKE_DERIVED_DIMENSION(name,unit,base_units) \
    using name = typename get_dimension< decltype(base_units) >::type; \
    constexpr quantity<name> operator"" unit( const long double value ) \
    { return quantity<name>(value); } \
    const quantity<name> unit( 1.0 );
// end UNITS_MAKE_DERIVED_DIMENSION


// the main class for a thing with a unit
// [WARNING!!!] use the macros as is will not nessesarily compile with gcc,
// if UNITS_MAKE_SCALAR_DIMENSION is called in another namespace than this
// class declaration. -fpermissive solves that.
template <typename Dimension, typename T=double>
struct quantity
{
    constexpr quantity() : _value() {}
    constexpr explicit quantity( T x )
       : _value(x)
    {}

    T value() const
    {
        return _value;
    }

private:
    T _value;

};

// print the quantity = print the value
template <typename D, typename T>
std::ostream &operator<<( std::ostream &os, quantity<D,T> qty )
{
    os << qty.value();
    return os;
}

// now the operators on quantities
// compare: only for same dimensions
template <typename T1, typename T2, typename D>
bool operator< ( quantity<D,T1> a, quantity<D,T2> b )
{
    return a.value() < b.value();
}

template <typename T1, typename T2, typename D>
bool operator<= ( quantity<D,T1> a, quantity<D,T2> b )
{
    return a.value() <= b.value();
}

template <typename T1, typename T2, typename D>
bool operator> ( quantity<D,T1> a, quantity<D,T2> b )
{
    return a.value() > b.value();
}

template <typename T1, typename T2, typename D>
bool operator>= ( quantity<D,T1> a, quantity<D,T2> b )
{
    return a.value() >= b.value();
}

template <typename T1, typename T2, typename D>
bool operator== ( quantity<D,T1> a, quantity<D,T2> b )
{
    return a.value() == b.value();
}

// add and subtract: only allow for the same dimension,
//                   and if the types can be added

template <typename T1, typename T2, typename D>
auto operator+ ( quantity<D,T1> a, quantity<D,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity<D,decltype( a.value() + b.value() )>
#endif
{
    return quantity<D,decltype(a.value()+b.value())>(a.value() + b.value());
}

template <typename T1, typename T2, typename D>
auto operator- ( quantity<D,T1> a, quantity<D,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity<D,decltype( a.value() - b.value() )>
#endif
{
    return quantity<D,decltype(a.value()-b.value())>(a.value() - b.value());
}


template <typename T1, typename T2, typename D1, typename D2>
auto operator*( quantity<D1,T1> a, quantity<D2,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< typename add_list_elements< D1, D2 >::type,
                 decltype(a.value()*b.value()) >
#endif
{
    using return_type
        = quantity<
                typename add_list_elements< D1, D2 >::type,
                decltype(a.value()*b.value())
            >;

    return return_type(a.value()*b.value());
}


template <typename T1, typename T2, typename D1, typename D2>
auto operator/( quantity<D1,T1> a, quantity<D2,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< typename subtract_list_elements< D1, D2 >::type,
                 decltype(a.value()/b.value()) >
#endif
{
    using return_type
        = quantity<
                typename subtract_list_elements< D1, D2 >::type,
                decltype(a.value()/b.value())
            >;

    return return_type(a.value()/b.value());
}

// scalars
template <typename T1, typename T2, typename D>
auto operator*( quantity<D,T1> a, T2 b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< D, decltype(a.value()* b) >
#endif
{
    using return_type = quantity< D, decltype(a.value()* b) >;

    return return_type(a.value() * b);
}

template <typename T1, typename T2, typename D>
auto operator*( T1 a, quantity<D,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< D, decltype(a * b.value()) >
#endif
{
    using return_type = quantity< D, decltype(a * b.value()) >;

    return return_type(a * b.value());
}

template <typename T1, typename T2, typename D>
auto operator/( quantity<D,T1> a, T2 b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< D, decltype(a.value()/ b) >
#endif
{
    using return_type = quantity< D, decltype(a.value()/ b) >;

    return return_type(a.value() / b);
}

template <typename T1, typename T2, typename D>
auto operator/( T1 a, quantity<D,T2> b )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity< D, decltype(a / b.value()) >
#endif
{
    using return_type = quantity< D, decltype(a / b.value()) >;

    return return_type(a / b.value());
}


// square root function gives the unit a factor 1/2
template <typename T, typename D>
auto sqrt( quantity<D,T> x )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity<
            typename multiply_list_elements<
                D,
                typename append_n< list<>, size( D() ), rational<1,2> >::type
            >::type,
            T
        >
#endif
{
    // list with same length as D and all entries 1/2
    using halfs = typename append_n< list<>, size( D() ), rational<1,2> >::type;
    using return_dim = typename multiply_list_elements< D, halfs >::type;
    return quantity< return_dim, T >( std::sqrt(x.value()) );
}

// cube root function gives the unit a factor 1/2
template <typename T, typename D>
auto cbrt( quantity<D,T> x )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity<
    typename multiply_list_elements<
    D,
    typename append_n< list<>, size( D() ), rational<1,3> >::type
                                                            >::type,
    T
    >
#endif
{
    // list with same length as D and all entries 1/3
    using halfs = typename append_n< list<>, size( D() ), rational<1,3> >::type;
    using return_dim = typename multiply_list_elements< D, halfs >::type;
    return quantity< return_dim, T >( std::cbrt(x.value()) );
}

// Square function gives the unit a factor
template <typename T, typename D>
auto sqr( quantity<D,T> x )
#ifndef HAVE_CXX1Y_RETURN_TYPE_DEDUCTION
    -> quantity<
        typename multiply_list_elements<
    D,
    typename append_n< list<>, size( D() ), rational<2,1> >::type
                                                            >::type,
    T
    >
#endif
{
    // list with same length as D and all entries 1/2
    using twice = typename append_n< list<>, size( D() ), rational<2,1> >::type;
    using return_dim = typename multiply_list_elements< D, twice >::type;
    return quantity< return_dim, T >( x.value()*x.value() );
}

// ---------------------------------------------------------------------------
    } // end namespace lego::units
} // end namespace lego
// ---------------------------------------------------------------------------

#define __UNITS_HPP__
#endif // ifndef __UNITS_HPP__
