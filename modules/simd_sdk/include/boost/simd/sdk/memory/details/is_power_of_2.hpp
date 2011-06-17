/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_MEMORY_DETAILS_IS_POWER_OF_2_HPP_INCLUDED
#define BOOST_SIMD_SDK_MEMORY_DETAILS_IS_POWER_OF_2_HPP_INCLUDED

#include <boost/simd/sdk/meta/mpl.hpp>
#include <boost/simd/sdk/memory/details/category.hpp>
#include <boost/simd/sdk/functor/preprocessor/call.hpp>

////////////////////////////////////////////////////////////////////////////////
// is_power_of_2 on integers
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_power_of_2_, tag::cpu_
                             , (A0), (integer_<A0>)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_power_of_2_(tag::integer_), tag::cpu_, Dummy>
        : callable
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(1) { return (!(a0 & (a0 - 1)) && a0); }
  };

} } }

////////////////////////////////////////////////////////////////////////////////
// is_power_of_2 on mpl integral
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::is_power_of_2_, tag::cpu_
                             , (A0), (mpl_integral_< integer_<A0> >)
                             )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::is_power_of_2_(tag::mpl_integral_<tag::integer_>)
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(1) { return meta::is_power_of_2<A0>::value; }
  };
} } }

#endif
