lego::units 
===========

lego::units is a mini library of C++ metafunctions that aims to handle
dimensional analysis of quantities with units at compile time. At the same time
there should not be a runtime performance penalty for using the library.

Motivation
----------

There are already libraries out there, which do exactly the same thing and do
it quite well (most prominent example Boost.Units). One of the most bothersome
things that come with using template metaprogramming in C++ is the increased
compile time that mostly stems from recursive template class instatiations. 

Now that we have C++11 there are a few new ways to solve the same problems
without using recursive template class instantiations. 

On the one hand, if numerical values are the results of metafunctions, then you
can get around template classes using _constexpr_ functions. They are still
recursive, but have much less overhead ([see article by Sumant Tambe](http://cpptruths.blogspot.de/2011/07/want-speed-use-constexpr-meta.html "Want speed? Use constexpr meta-programming!")).

On the other hand, for dimensional analysis all approaches I have seen use some
kind of compile time list type. Working with those lists requires recursion (do
something to the head of the list and forward the tail recursively to the same
function until all elements are processed). Each step along the way the
compiler will instantiate a seperate class with the apropiate template
parameters, so again there is a lot of overhead just to represent the
intermediate steps. With C++11 variadic templates you can not get rid of this
kind of recursion altogether, but don't need it for the 'do something to each
element'-stuff. What you can use is parameter pack expansion.

This library tries to use the new C++11 features to speed up the compilation
process while keeping the same zero-run-time-overhead goal.

Current status of the library
-----------------------------

At the moment the library implements the most important features, but cannot
compete with the flexibility of Boost.Units. It is to be seen as a
proof-of-concept (Yes it is possible to do it.), rather than a production build
library. There are no automated tests yet. Only very few manual tests have been
performed to show that the most common and most easy and trivial things appear
to work. 

It compiles using GCC 4.7.2.

Probably other C++11 compilers will work as well,
but I haven't tried any others yet. 

    g++ -std=c++11 -I<path/to/units.hpp> <cpp-file>

I've also added support in the Makefile for detection and C++1y return type deduction which are available in GCC-4.8.2 and Clang 3.3+.

    g++ -std=gnu++1y -I<path/to/units.hpp> <cpp-file>


Description of the library's files
----------------------------------

* *boost\_units.cpp* is the code taken from the Boost.Units [Quickstart 
                     guide](http://www.boost.org/doc/libs/1_53_0/doc/html/boost_units/Quick_Start.html). 
                     It represents the minimal functionality that this 
                     library does implement.

* *lego\_units.cpp*  is code with the same semantics of the above, but 
                     using lego::units instead of boost.  

* *list.hpp*         a small compile time lists library with just enough 
                     features that it is usable for lego::units.

* *rationals.hpp*    compile time rational numbers, not unlike boosts
                     [static\_rational](http://www.boost.org/doc/libs/1_53_0/boost/units/static_rational.hpp), 
                     but without the dependency on mpl. Instead it is 
                     implemented using constexpr functions.

* *test\_rationals.cpp* 
                     a non-automated usecase for the rational numbers 
                     and their operators as well as lists of rational
                     numbers

* *units.hpp*        this is where quantities with units are defined and
                     the operations on quantities (addition,subtraction,
                     multiplication,division and sqrt())

* *units\_SI.hpp*    defines dimension and unit names for the SI standard
                     unit system

* *units\_eV-K-nm-fs-e0.hpp* 
                     defines dimension and unit names for a different unit
                     system which is used i.e. in quantum physics

Using the library in a nutshell
-------------------------------

In short, you can use lego::units::quantity for a number that has a unit:

    using namespace lego::units;

    // for SI units this is 10 kg, not the clearest syntax
    quantity<mass> m( 10.0 );

    // the same thing but explicitly specifying the unit
    quantity<mass> m = 10.0_kg;

    // the same as above, but with type deduction
    auto m = 10.0_kg;

when you declared your quantities you can use them in calculations just as if 
they were numbers, except that dimensional analysis is done and an error will
be raised if the units don't match for addition or subtraction, or if you try 
to call a mathematical function like _exp()_ with unit arguments.

For an example see file *lego\_units.cpp*.



