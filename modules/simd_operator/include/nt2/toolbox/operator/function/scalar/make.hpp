/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_MAKE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_MAKE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// make for scalar types
////////////////////////////////////////////////////////////////////////////////
#include <nt2/simd_sdk/meta/as.hpp>
#include <nt2/simd_sdk/functor/preprocessor/call.hpp>
#include <nt2/simd_sdk/details/ignore_unused.hpp>

BOOST_SIMD_REGISTER_DISPATCH ( tag::make_
                      , tag::cpu_
                      , (A0)
                      , (target_< fundamental_<A0> >)
                      );

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::make_(tag::target_<tag::fundamental_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;

    template<class This, class A0>
    struct result<This(A0)> : meta::strip<A0> {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };
} } }

#endif
