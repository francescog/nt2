//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_ROR_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_ROR_HPP_INCLUDED
#include <nt2/sdk/meta/as_bits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/shri.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::ror_, tag::cpu_,
                     (A0)(A1),
                     (arithmetic_<A0>)(integer_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::ror_(tag::arithmetic_,tag::integer_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : meta::strip <A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return b_or(shri(a0, a1), shli(a0, (sizeof(A0)*CHAR_BIT-a1)));
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::ror_, tag::cpu_,
                     (A0)(A1),
                     (real_<A0>)(integer_<A1>)
                    )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::ror_(tag::real_,tag::integer_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : meta::strip <A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      typename meta::as_bits<A0>::type t0 = {a0};
      t0.bits = b_or(shri(t0.bits, a1), shli(t0.bits, (sizeof(A0)*CHAR_BIT-a1)));
      return t0.value;
    }
  };
} }

#endif
// modified by jt the 26/12/2010
