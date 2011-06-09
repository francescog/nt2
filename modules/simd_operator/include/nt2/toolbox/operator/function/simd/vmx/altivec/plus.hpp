/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_PLUS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// operator binary plus
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>

////////////////////////////////////////////////////////////////////////////////
// Overload registration
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::plus_, tag::cpu_, (A0)
                      , ((simd_<arithmetic_<A0>,tag::altivec_>))
                        ((simd_<arithmetic_<A0>,tag::altivec_>))
                      );

////////////////////////////////////////////////////////////////////////////////
// Overloads implementation
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::plus_( tag::simd_<tag::arithmetic_,tag::altivec_>
                          , tag::simd_<tag::arithmetic_,tag::altivec_>
                          )
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig>           struct result;
    template<class This,class A>  struct result<This(A,A)> : meta::strip<A> {};

    BOOST_SIMD_FUNCTOR_CALL(2) { A0 that = { vec_add(a0(),a1()) }; return that; }
  };
} } }

#endif
