//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_CSC_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SIMD_COMMON_CSC_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/simd/meta/is_real_convertible.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/tofloat.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::csc_, tag::cpu_,
                      (A0)(X),
                      ((simd_<integer_<A0>,X>))
                     );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::csc_(tag::simd_<tag::integer_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :  meta::as_real<A0>{};

    NT2_FUNCTOR_CALL(1)
    {
      return b_or(rec(sin(tofloat(a0))), is_eqz(a0));
    }

  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::csc_, tag::cpu_,
                      (A0)(X),
                      ((simd_<real_<A0>,X>))
                     );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::csc_(tag::simd_<tag::real_, X> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :  meta::strip<A0>{};

    NT2_FUNCTOR_CALL(1)
    {
      return rec(sin(a0));
    }

  };
} }

#endif
// modified by jt the 05/01/2011
