/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_LOGICAL_OR_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_COMMON_LOGICAL_OR_HPP_INCLUDED

#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_not_equal.hpp>
#include <nt2/include/functions/bitwise_or.hpp>
#include <nt2/include/constants/digits.hpp>

BOOST_SIMD_REGISTER_DISPATCH ( tag::logical_or_, tag::cpu_, (A0)(A1)(X)
                      , ((simd_<arithmetic_<A0>,X>))
                        ((simd_<arithmetic_<A1>,X>))
                      );

namespace boost { namespace simd { namespace ext
{
  template<class X,class Dummy>
  struct  call< tag::logical_or_( tag::simd_<tag::arithmetic_,X> 
                                , tag::simd_<tag::arithmetic_,X> 
                                )
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0)> : meta::strip<A0> {};

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return boost::simd::neq( (a0 | a1), boost::simd::Zero<A0>() );
    }
  };
} } }

#endif
