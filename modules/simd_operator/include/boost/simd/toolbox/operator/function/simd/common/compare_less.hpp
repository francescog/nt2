/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_COMPARE_LESS_HPP_INCLUDED

#include <boost/simd/sdk/meta/cardinal_of.hpp>

////////////////////////////////////////////////////////////////////////////////
// Overload registration
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::compare_less_, tag::cpu_, (A0)(X)
                      , ((simd_<arithmetic_<A0>,X>))
                        ((simd_<arithmetic_<A0>,X>))
                      );

////////////////////////////////////////////////////////////////////////////////
// Overloads implementation
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  template<class X, class Dummy>
  struct  call< tag::compare_less_( tag::simd_<tag::arithmetic_,X>
                                  , tag::simd_<tag::arithmetic_,X>
                                  )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      for(std::size_t i=0;i<meta::cardinal_of<A0>::value;++i)
      {
        if (a0[i] < a1[i])  return true;
        if (a1[i] < a0[i])  return false;
      }
      return false;
    }
  };
} } }

#endif
