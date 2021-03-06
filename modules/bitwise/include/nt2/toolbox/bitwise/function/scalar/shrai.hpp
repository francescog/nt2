//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_SHRAI_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_SHRAI_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_bits.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::shrai_, tag::cpu_,
                       (A0)(A1),
                       (arithmetic_<A0>)(integer_<A1>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::shrai_(tag::arithmetic_,tag::integer_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
       struct result<This(A0,A1)> : meta::strip <A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a0 >> a1;
    }
  };
} }
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is unsigned_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::shrai_, tag::cpu_,
                       (A0)(A1),
                       (unsigned_<A0>)(integer_<A1>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::shrai_(tag::unsigned_,tag::integer_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
       struct result<This(A0,A1)> : meta::strip <A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a0 >> a1;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::shrai_, tag::cpu_,
                       (A0)(A1),
                       (real_<A0>)(integer_<A1>)
                      )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::shrai_(tag::real_,tag::integer_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
       struct result<This(A0,A1)> : meta::strip <A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename meta::as_bits<A0, signed>::type type;
      type that = {a0};
      that.bits >>= a1;
      return that.value;
    }
  };
} }

#endif
// modified by jt the 26/12/2010
