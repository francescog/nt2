//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_MODULO_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_MODULO_HPP_INCLUDED

BOOST_SIMD_REGISTER_DISPATCH ( tag::modulo_     , tag::cpu_, (A0)(A1)
                      , (integer_<A0>)(integer_<A1>)
                      )

namespace boost { namespace simd { namespace ext
{
  //============================================================================
  // Modulo
  //============================================================================
  template<class Dummy>
  struct  call<tag::modulo_(tag::integer_,tag::integer_), tag::cpu_, Dummy>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>  struct
    result<This(A0,A1)>
    {
      static A0 a0; static A1 a1;
      BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested,a0%a1)
      typedef typename nested::type type;
    };

    BOOST_SIMD_FUNCTOR_CALL(2) { return a0 % a1; }
  };
} } }

#endif
