/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_MAXLEFTSHIFT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_MAXLEFTSHIFT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Base class for generating signmask constant
////////////////////////////////////////////////////////////////////////////////
#include <nt2/simd_sdk/meta/from_bits.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/simd_sdk/meta/adapted_traits.hpp>
#include <nt2/simd_sdk/functor/preprocessor/call.hpp>

BOOST_SIMD_REGISTER_DISPATCH ( tag::max_left_shift_
                      , tag::cpu_,(A0)
                      , (target_< arithmetic_<A0> > )
                      )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::max_left_shift_(tag::target_<tag::arithmetic_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)>
        : meta::as_integer<typename meta::strip<Target>::type::type,signed> {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      typedef typename  BOOST_SIMD_RETURN_TYPE(1)::type  type;
      typedef typename meta::scalar_of<type>::type base_t;
      BOOST_STATIC_CONSTANT(std::size_t, value = sizeof(base_t)*CHAR_BIT-1 );
      return splat<type>(value);
    }
  };
} } }

#endif
