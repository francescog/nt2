//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_NOT_GREATER_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_SSE_SSE2_IS_NOT_GREATER_EQUAL_HPP_INCLUDED

#include <nt2/toolbox/predicates/function/simd/common/is_not_greater_equal.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_greater_equal_, tag::cpu_,
                         (A0),
                         ((simd_<double_<A0>,tag::sse_>))
                         ((simd_<double_<A0>,tag::sse_>))
                        );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_greater_equal_(tag::simd_<tag::double_, tag::sse_> ,
                           tag::simd_<tag::double_, tag::sse_> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0, A0)> : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      A0 that =  { _mm_cmpnge_pd(a0,a1)}; return that;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_greater_equal_, tag::cpu_,
                         (A0),
                         ((simd_<float_<A0>,tag::sse_>))
                         ((simd_<float_<A0>,tag::sse_>))
                        );

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_greater_equal_(tag::simd_<tag::float_, tag::sse_> ,
                           tag::simd_<tag::float_, tag::sse_> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0, A0)> : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(2)
    {
      A0 that =  { _mm_cmpnge_ps(a0,a1)}; return that;
    }
  };
} }

#endif
// modified by mg the 04/04/2011
