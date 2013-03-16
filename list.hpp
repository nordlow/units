#ifndef __META_LIST_HPP__
#define __META_LIST_HPP__

#include <iostream>
#include <typeinfo>


// ---------------------------------------------------------------------------
namespace lego
{   namespace meta
    {   namespace list
        {
// ---------------------------------------------------------------------------

// --- list class ------------------------------------------------------------
// a type list class, the goal is that any typelist l<...> will work
template<typename... Elements>
struct list {};
// --- end list class --------------------------------------------------------

// --- size() ----------------------------------------------------------------
// get the size of a list easily
template< template <typename...> class List, typename... Elements>
constexpr size_t size( List<Elements...> )
{
    return sizeof...(Elements);
}
// --- end size() ------------------------------------------------------------

// integer as a type. if you want to put ints in a typelist
template <int I>
struct _int {};


// most important thing for debugging: print the list
// --- printing functions ----------------------------------------------------
// default base case for printing
template<typename T>
void print( std::ostream &os, T t )
{
    os << "("<< typeid(T).name() << ")";
}

// special cases
// _int class
template <int I>
std::ostream &operator<<( std::ostream &os, _int<I> )
{
    os << "_int<" << I << ">";
    return os;
}

template <int I>
void print( std::ostream &os, _int<I> i )
{
    os << i;
}

// list arguments, recurse
template<typename T, typename... Ts>
void print( std::ostream &os, T t, Ts... ts )
{
    
    print(os,t);
    if (sizeof...(Ts) > 0 )
    {
        os << ",";
    }
    print(os,ts...);
}

template < template <typename...> class List, typename... Elements >
void print( std::ostream &os, List<Elements...> l )
{
    os << l;
}

template < template <typename...> class List, typename... Elements >
std::ostream &operator<<( std::ostream &os, List<Elements...> )
{
    os << "<"; 
    print( os, Elements()... );
    os << ">";
    return os;
}
// --- end printing functions ------------------------------------------------

// make a range:
// append_range< list<es...>, min,max>::type = list<es...,min,min+1,...,max>
template <typename List, int Min, int Max>
struct append_range
{};

template <template <typename...> class List, int Min, int Max, typename... Es>
struct append_range<List<Es...>,Min,Max>
{
    using type = typename append_range<
                        List<Es...,_int<Min>>,
                        Min+1,
                        Max
                    >::type; // end append_range<>
};

template <template <typename...> class List, int Max, typename... Es>
struct append_range<List<Es...>,Max,Max>
{
    using type = List<Es...,_int<Max>>;
};
// --- end append_range ------------------------------------------------------

// append element n times
// append_n< list<es...>, N, Element > = list<es...,Element,...,Element>
//                                                           ^ n times

template <typename List, int N, typename Element>
struct append_n
{};

template <template <typename...> class List, int N, typename Element, 
          typename... Es>
struct append_n<List<Es...>,N,Element>
{
    using type = typename append_n< List<Es...,Element>, N-1, Element >::type;
};

template <template <typename...> class List, typename Element, typename... Es>
struct append_n<List<Es...>,0,Element>
{
    using type = List<Es...>;
};
// --- end append_n ----------------------------------------------------------


// --- element wise add, subtract, multiply, divide --------------------------
// little helper typedef
template <typename A, typename B>
using sum_type = decltype(A() + B());

template <typename A, typename B>
using difference_type = decltype(A() - B());

template <typename A, typename B>
using product_type = decltype(A() * B());

template <typename A, typename B>
using quotient_type = decltype(A() / B());

// --- add_list_elements -----------------------------------------------------
template <typename List1, typename List2>
struct add_list_elements {};

template <template <typename...> class List, 
          typename... Elements1, typename... Elements2>
struct add_list_elements< List<Elements1...>,List<Elements2...> >
{
    using type = List< sum_type<Elements1,Elements2>... >;
};
// --- end add_list_elements -------------------------------------------------

// --- subtract_list_elements ------------------------------------------------
template <typename List1, typename List2>
struct subtract_list_elements {};

template <template <typename...> class List, 
          typename... Elements1, typename... Elements2>
struct subtract_list_elements< List<Elements1...>,List<Elements2...> >
{
    using type = List< difference_type<Elements1,Elements2>... >;
};
// --- end subtract_list_elements --------------------------------------------


// --- multiply_list_elements ------------------------------------------------
template <typename List1, typename List2>
struct multiply_list_elements {};

template <template <typename...> class List, 
          typename... Elements1, typename... Elements2>
struct multiply_list_elements< List<Elements1...>,List<Elements2...> >
{
    using type = List< product_type<Elements1,Elements2>... >;
};
// --- end multiply_list_elements --------------------------------------------


// --- divide_list_elements --------------------------------------------------
template <typename List1, typename List2>
struct divide_list_elements {};

template <template <typename...> class List, 
          typename... Elements1, typename... Elements2>
struct divide_list_elements< List<Elements1...>,List<Elements2...> >
{
    using type = List< quotient_type<Elements1,Elements2>... >;
};
// --- end divide_list_elements ----------------------------------------------



// ---------------------------------------------------------------------------
        } // end namespace lego::meta::list
    } // end namespace lego::meta
} // end namespace lego
// ---------------------------------------------------------------------------


#endif // ifndef __META_LIST_HPP__
