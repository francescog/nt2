/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IMPL_DIVIDES_INT8_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_IMPL_DIVIDES_INT8_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Overloads implementation
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  //////////////////////////////////////////////////////////////////////////////
  // a/b use a bit preserving algorithm from vecLib by Apple
  //////////////////////////////////////////////////////////////////////////////
  template<class Dummy>
  struct  call< tag::divides_( tag::simd_<tag::ints8_,tag::altivec_>
                             , tag::simd_<tag::ints8_,tag::altivec_>
                             )
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig>           struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : meta::strip<A0> {};

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename BOOST_SIMD_RETURN_TYPE(2)::type type;    
    }
  };
} } }

#endif
