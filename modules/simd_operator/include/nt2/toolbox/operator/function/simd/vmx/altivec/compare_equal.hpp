/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_COMPARE_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_COMPARE_EQUAL_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Overload registration
////////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH ( tag::compare_equal_, tag::cpu_, (A0)
                      , ((simd_<arithmetic_<A0>,tag::altivec_>))
                        ((simd_<arithmetic_<A0>,tag::altivec_>))
                      );

////////////////////////////////////////////////////////////////////////////////
// Overloads implementation
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  template<class Dummy>
  struct  call< tag::compare_equal_ ( tag::simd_<tag::arithmetic_,tag::altivec_>
                                    , tag::simd_<tag::arithmetic_,tag::altivec_>
                                    )
              , tag::cpu_, Dummy
              >
        : callable
  {
    typedef bool result_type;
    NT2_FUNCTOR_CALL(2) { return vec_all_eq(a0(),a1()); }
  };
} }

#endif
