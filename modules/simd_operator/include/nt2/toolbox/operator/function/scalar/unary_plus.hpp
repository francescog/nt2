//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_UNARY_PLUS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_UNARY_PLUS_HPP_INCLUDED

BOOST_SIMD_REGISTER_DISPATCH ( tag::unary_plus_ , tag::cpu_, (A0)
                      , (fundamental_<A0>)
                      )

namespace nt2 { namespace ext
{
  //============================================================================
  // Unary plus
  //============================================================================
  template<class Dummy>
  struct call<tag::unary_plus_(tag::fundamental_), tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>  struct
    result<This(A0)>
    {
      static A0 a0;
      BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested,+a0)
      typedef typename nested::type type;
    };

    BOOST_SIMD_FUNCTOR_CALL(1) { return +a0; }
  };
} }

#endif
