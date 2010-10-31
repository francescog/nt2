//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_LIBC_FUNCTION_SCALAR_TAN_HPP_INCLUDED
#define NT2_TOOLBOX_LIBC_FUNCTION_SCALAR_TAN_HPP_INCLUDED

namespace nt2 { namespace functors
{

  /////////////////////////////////////////////////////////////////////////////
  // Compute tan(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<libc::tan_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH( 1, A0, (4, (long double,double,float,arithmetic_)) )

    NT2_FUNCTOR_CALL_EVAL_IF(1, long double) { return ::tanl(a0);  }
    NT2_FUNCTOR_CALL_EVAL_IF(1, double) { return ::tan(a0);  }
    NT2_FUNCTOR_CALL_EVAL_IF(1, float)  { return ::tanf(a0); }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type;
      return nt2::libc::tan(type(a0));
    }
  };
} }


      
#endif