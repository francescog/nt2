//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_IS_GREATER_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SCALAR_IS_GREATER_EQUAL_HPP_INCLUDED

BOOST_SIMD_REGISTER_DISPATCH( tag::is_greater_equal_, tag::cpu_
                     , (A0)(A1)
                     , (fundamental_<A0>)(fundamental_<A1>)
                     );

namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call<tag::is_greater_equal_(tag::fundamental_,tag::fundamental_), tag::cpu_, Dummy>
        : callable
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      return a0 >= a1;
    }
  };
} } } 

#endif
