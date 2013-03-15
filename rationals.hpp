#ifndef __RATIONALS_HPP__
#define __RATIONALS_HPP__

#include <iostream>

// ---------------------------------------------------------------------------
namespace lego
{   namespace meta
    {   namespace rationals
        {
// ---------------------------------------------------------------------------

// denominator needs to be positive or bad things might happen!
// BUT, somehow static cast is not a constexpr (WTF!), so use ints and hope
template <int N, int D>
struct rational
{
    static constexpr int numerator()
    {
        return N;
    }
    static constexpr int denominator()
    {
        return D;
    }
};

constexpr int abs( const int a )
{
    return a < 0 ? (-a) : (a);
}

// gives the greatest common devisor of a and b. 
// note: gcd(0,b) = gcd(a,0) = 1
constexpr int gcd( const int a, const int b )
{
    // base cases: one of the inputs is zero, or they are equal.
    // technically base cases with zero input should return 1, but i want
    // rationals 0/anything to be reduced to 0/1
    return a == 0 ?  b
            : b == 0 ? a 
            : a == b ? a : ( a > b ? gcd(a-b,b) : gcd(a, b-a) );
}

constexpr int reduceN( const int N, const int D )
{
    return N/(gcd(abs(N),D));
}
constexpr int reduceD( const int N, const int D )
{
    return D/(gcd(abs(N),D));
}

// --- reduce ----------------------------------------------------------------
template <typename R>
struct reduce_rational {};

template <template <int,int> class R, int N, int D>
struct reduce_rational< R<N,D> >
{
    using type = R< reduceN(N,D), reduceD(N,D) >;
};
// --- end reduce ------------------------------------------------------------


// --- add_rationals ---------------------------------------------------------
template< typename R1, typename R2 >
struct add_rationals {};

template <template <int, int> class R, 
          int N1, int D1, int N2, int D2>
struct add_rationals< R<N1,D1>, R<N2,D2> >
{
    using type = typename reduce_rational< R<N1*D2 + N2*D1, D1*D2> >::type; 
};
// --- end add_rationals -----------------------------------------------------

// --- subtract_rationals ----------------------------------------------------
template< typename R1, typename R2 >
struct subtract_rationals {};

template <template <int, int> class R, 
          int N1, int D1, int N2, int D2>
struct subtract_rationals< R<N1,D1>, R<N2,D2> >
{
    using type = typename add_rationals< R<N1,D1>, R<-N2,D2> >::type; 
};
// --- subtract_rationals ----------------------------------------------------

// --- multiply_rationals ----------------------------------------------------
template< typename R1, typename R2 >
struct multiply_rationals {};

template <template <int, int> class R, 
          int N1, int D1, int N2, int D2>
struct multiply_rationals< R<N1,D1>, R<N2,D2> >
{
    using type = typename reduce_rational< R<N1*N2,D1*D2> >::type;
};
// --- end multiply_rationals ------------------------------------------------

// --- divide_rationals ------------------------------------------------------
template< typename R1, typename R2 >
struct divide_rationals {};

template <template <int, int> class R, 
          int N1, int D1, int N2, int D2>
struct divide_rationals< R<N1,D1>, R<N2,D2> >
{
    using type = typename multiply_rationals< R<N1,D1>, R<D2,N2> >::type; 
};
// --- end divide_rationals --------------------------------------------------

// --- operators +-*/ --------------------------------------------------------
template <typename R1, typename R2>
constexpr auto operator+( R1, R2 ) 
    ->  typename add_rationals< R1, R2 >::type
{
    return typename add_rationals< R1, R2 >::type();
}

template <typename R1, typename R2>
constexpr auto operator-( R1, R2 ) 
    ->  typename subtract_rationals< R1, R2 >::type
{
    return typename subtract_rationals< R1, R2 >::type();
}

template <typename R1, typename R2>
constexpr auto operator*( R1, R2 ) 
    ->  typename multiply_rationals< R1, R2 >::type
{
    return typename multiply_rationals< R1, R2 >::type();
}

template <typename R1, typename R2>
constexpr auto operator/( R1, R2 ) 
    ->  typename divide_rationals< R1, R2 >::type
{
    return typename divide_rationals< R1, R2 >::type();
}

// just a debug function for printing compile time rationals
template <int N, int D>
void print( std::ostream &os, rational<N,D> r )
{
    os << r;
}

template <int N, int D>
std::ostream &operator<<( std::ostream &out, rational<N,D> )
{
    out << N;
    if ( D > 1 ) { out << "/" << D; }

    return out;
}

// ---------------------------------------------------------------------------
        } // end namespace lego::meta::rationals
    } // end namespace lego::meta
} // end namespace lego
// ---------------------------------------------------------------------------


#endif // ifndef __RATIONALS_HPP__
// eof rationals.hpp
