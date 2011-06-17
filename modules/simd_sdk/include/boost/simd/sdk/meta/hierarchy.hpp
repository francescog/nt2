/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_META_HIERARCHY_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_HIERARCHY_HPP_INCLUDED

// Hierarchy of built-in types
// See: http://nt2.metascale.org/sdk/meta/tags.html

#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/simd/sdk/details/preprocessor.hpp>
#include <boost/simd/sdk/meta/details/hierarchy.hpp>

#define BOOST_SIMD_HIERARCHY_CLASS(Name, Parent)     \
struct Name : Parent                          \
{                                             \
  typedef Parent    parent;                   \
  typedef tag::Name type;                     \
}                                             \
/**/

#define BOOST_SIMD_HIERARCHY_CLASS_TPL(Name, Parent) \
template<class T> struct Name : Parent        \
{                                             \
  typedef Parent    parent;                   \
  typedef tag::Name type;                     \
}                                             \
/**/

#define BOOST_SIMD_HIERARCHY_CLASS_TPL_META(Name, Parent)          \
template<class T> struct Name : BOOST_SIMD_PP_STRIP(Parent)::type  \
{                                                                  \
  typedef typename BOOST_SIMD_PP_STRIP(Parent)::type    parent;    \
  typedef tag::Name type;                                          \
}                                                                  \
/**/

namespace boost { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // Types hierarchy defines a partially order lattice of type familly
  // which helps categorizing a given type into all its potential enclosing type
  // sets. Hierarchies are template so they can use their root type to
  // select at each lattice node which ancestor to use.
  //////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////
  // The unknown_ hierarchy is the upper bound in our hierarchy lattice.
  // When a dispatch resovles on unknown_, it means no suitable overload has
  // been found.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> struct unknown_
  {
    typedef unknown_      parent;
    typedef tag::unknown_ type;
  };

  //////////////////////////////////////////////////////////////////////////////
  // The unspecified_ hierarchy is used for non-categorized type that will still
  // want to catch without error
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(unspecified_, unknown_<T> );

  /////////////////////////////////////////////////////////////////////////////
  // Upper level hierarchies:
  // fundamental_ gathers all native types
  // arithmetic_ gathers all native type except bool
  // integer_ gathers all native integer types
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(fundamental_, unspecified_<T> );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(arithmetic_ , fundamental_<T> );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(integer_    , arithmetic_<T>  );


  BOOST_SIMD_HIERARCHY_CLASS_TPL_META (signed_, (boost::mpl::if_< boost::is_integral<T>
                                                         , integer_<T>
                                                         , arithmetic_<T>
                                                         >
                                      )
                          );

  BOOST_SIMD_HIERARCHY_CLASS_TPL(unsigned_   , integer_<T>   );

  //////////////////////////////////////////////////////////////////////////////
  // Floating point types hierarchy
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(real_       , signed_<T>    );

  //////////////////////////////////////////////////////////////////////////////
  // Sign based hierarchy - gather integral types of a given signedness
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(int_        , signed_<T>    );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(uint_       , unsigned_<T>  );

  //////////////////////////////////////////////////////////////////////////////
  // Sizeof based hierarchy - gather type which sizeof is equal to a given value
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL_META (type8_, (boost::mpl::if_< boost::is_signed<T>
                                                        , int_<T>
                                                        , uint_<T>
                                                        >
                                    )
                          );

  BOOST_SIMD_HIERARCHY_CLASS_TPL_META (type16_, (boost::mpl::if_< boost::is_signed<T>
                                                         , int_<T>
                                                         , uint_<T>
                                                         >
                                    )
                          );

  BOOST_SIMD_HIERARCHY_CLASS_TPL_META (type32_
                          , (boost::mpl::if_<boost::is_floating_point<T>
                                            , real_<T>
                                            , typename
                                              boost::mpl::if_ < boost::is_signed<T>
                                                              , int_<T>
                                                              , uint_<T>
                                                              >::type
                                            >
                                    )
                          );

  BOOST_SIMD_HIERARCHY_CLASS_TPL_META (type64_
                          , (boost::mpl::if_<boost::is_floating_point<T>
                                            , real_<T>
                                            , typename
                                              boost::mpl::if_ < boost::is_signed<T>
                                                              , int_<T>
                                                              , uint_<T>
                                                              >::type
                                            >
                                    )
                          );

  //////////////////////////////////////////////////////////////////////////////
  // Sizeof based hierarchy of integers
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(ints8_        , type8_<T>       );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(ints16_       , type16_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(ints32_       , type32_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(ints64_       , type64_<T>      );

  //////////////////////////////////////////////////////////////////////////////
  // Sizeof based hierarchy of signed integers
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(int8_         , ints8_<T>       );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(int16_        , ints16_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(int32_        , ints32_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(int64_        , ints64_<T>      );

  //////////////////////////////////////////////////////////////////////////////
  // Sizeof based hierarchy of unsigned integers
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(uint8_        , ints8_<T>       );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(uint16_       , ints16_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(uint32_       , ints32_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(uint64_       , ints64_<T>      );

  //////////////////////////////////////////////////////////////////////////////
  // Native real types hierarchy
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(double_       , type64_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(float_        , type32_<T>      );
  BOOST_SIMD_HIERARCHY_CLASS_TPL(long_double_  , fundamental_<T> );

  //////////////////////////////////////////////////////////////////////////////
  // Boolean type hierarchy
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(bool_         , fundamental_<T> );

  //////////////////////////////////////////////////////////////////////////////
  // void type hierarchy
  //////////////////////////////////////////////////////////////////////////////
  BOOST_SIMD_HIERARCHY_CLASS_TPL(void_         , fundamental_<T> );
} }

#endif
