/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_SIGNMASK_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_DETAILS_SIGNMASK_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Base class for generating signmask constant
////////////////////////////////////////////////////////////////////////////////
#include <nt2/simd_sdk/meta/from_bits.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/simd_sdk/meta/adapted_traits.hpp>
#include <nt2/simd_sdk/meta/as_unsigned.hpp>
#include <nt2/simd_sdk/functor/preprocessor/call.hpp>

BOOST_SIMD_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< double_<A0>    > ) )
BOOST_SIMD_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< float_<A0>     > ) )
BOOST_SIMD_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< unsigned_<A0>  > ) )
BOOST_SIMD_REGISTER_DISPATCH(tag::signmask_,tag::cpu_,(A0), (target_< signed_<A0>    > ) )

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::signmask_(tag::target_<tag::double_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      meta::from_bits<double>::type const that = {0x8000000000000000LL};
      return splat<typename A0::type>(that.value);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_<tag::float_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      meta::from_bits<float>::type const that = {0x80000000};
      return splat<typename A0::type>(that.value);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_<tag::unsigned_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      typedef typename meta::scalar_of<typename A0::type>::type base;
      return splat<typename A0::type>(0);
    }
  };

  template<class Dummy>
  struct  call< tag::signmask_(tag::target_<tag::signed_>)
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class Target>
    struct result<This(Target)> : meta::strip<Target>::type {};

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      typedef typename meta::scalar_of<typename A0::type>::type base;
      typedef typename meta::as_unsigned<base>::type base_u;
      BOOST_STATIC_CONSTANT(base_u, value = base_u(1) << (sizeof(base_u)*CHAR_BIT-1) );
      return splat<typename A0::type>(base(value));
    }
  };
} } }

#endif
