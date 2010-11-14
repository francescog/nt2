//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_NEXTPOW2_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTION_SCALAR_NEXTPOW2_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <boost/fusion/tuple.hpp>

#include <nt2/include/functions/frexp.hpp>
#include <nt2/include/functions/tofloat.hpp>
#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/abs.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for nextpow2

  /////////////////////////////////////////////////////////////////////////////
  // Compute nextpow2(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is real_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<nextpow2_,tag::scalar_(tag::arithmetic_),real_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
      struct result<This(A0)> :
      meta::as_integer<typename boost::result_of<meta::floating(A0)>::type, signed>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::as_integer<A0, signed>::type int_type;
      A0 m;
      int_type p;
      boost::fusion::tie(m, p) = nt2::frexp(nt2::abs(a0));
      return (m == Half<A0>())  ? minusone(p) :  p;
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<nextpow2_,tag::scalar_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
      struct result<This(A0)> :
      meta::as_integer<typename boost::result_of<meta::floating(A0)>::type, signed>{};

    NT2_FUNCTOR_CALL(1)
    {
      return nt2::nextpow2(tofloat(a0));
    }
  };

} }

#endif
/// Revised by jt the 13/11/2010
