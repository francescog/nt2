//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_J0_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_J0_HPP_INCLUDED
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/digits.hpp>

#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/cos.hpp>
#include <nt2/include/functions/is_inf.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for j0

  /////////////////////////////////////////////////////////////////////////////
  // Compute j0(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<j0_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      A0,
      (3, (float,double,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,  float)
    {
      typedef typename meta::scalar_of<A0>::type stype; 
      if (is_inf(a0)) return Zero<A0>(); 
      A0 x = nt2::abs(a0);
      if (x < 1.0e-3f) return oneminus(Quarter<A0>()*sqr(x));
      if (x <= Two<A0>())
        {
          A0 z = sqr(x);
          return (z-integral_constant<float,0x40b90fdc> ())*
            horner< NT2_HORNER_COEFF_T(stype, 5,
                   (0xb382511c,
              0x36d660a0,
              0xb9d01fb1,
              0x3c5a6271,
              0xbe3110a6
              ) ) > (z);
        }
      A0 q = rec(x);
      const A0 p3 = nt2::sqrt(q) *
        horner< NT2_HORNER_COEFF_T(stype, 8,
               (0xbd8c100e,
                0x3e3ef887,
                0xbe5ba616,
                0x3df54214,
                0xbb69539e,
                0xbd4b8bc1,
                0xb6612dc2,
                0x3f4c422a
                ) ) > (q);
            const A0 xn =  q*
              horner< NT2_HORNER_COEFF_T(stype, 8,
               (0x4201aee0,
                0xc2113945,
                0x418c7f6a,
                0xc09f3306,
                0x3f8040aa,
                0xbe46a57f,
                0x3d84ed6e,
                0xbdffff97
                ) ) > (sqr(q))-Pio_4<A0>();
      return p3*nt2::cos(xn+x);
    }

    NT2_FUNCTOR_CALL_EVAL_IF(1, double) {
      if (is_inf(a0)) return Zero<A0>(); 
      return ::j0(a0);
    }

    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return nt2::j0(type(a0));
    }
  };
} }


      
#endif