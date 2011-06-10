/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_COMPLEMENT_HPP_INCLUDED

#include <nt2/simd_sdk/meta/strip.hpp>
#include <nt2/include/functions/bitwise_xor.hpp>
#include <nt2/include/constants/true.hpp>

////////////////////////////////////////////////////////////////////////////////
// Overloads implementation
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::complement_, tag::cpu_, (A0)(X)
                      , ((simd_<arithmetic_<A0>,X>))
                      );

namespace boost { namespace simd { namespace ext
{
  //////////////////////////////////////////////////////////////////////////////
  // Implement ~ using xor
  //////////////////////////////////////////////////////////////////////////////
  template<class X, class Dummy>
  struct  call< tag::complement_( tag::simd_<tag::arithmetic_,X>  )
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig>           struct result;
    template<class This,class A0>
    struct result<This(A0)> : meta::strip<A0> {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return b_xor(True<A0>(), a0);
    }
  };
} } }

#endif
