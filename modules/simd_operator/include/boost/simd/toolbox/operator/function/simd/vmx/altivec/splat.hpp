/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_VMX_ALTIVEC_SPLAT_HPP_INCLUDED

#include <boost/simd/sdk/simd/category.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/simd/sdk/functor/preprocessor/call.hpp>

////////////////////////////////////////////////////////////////////////////////
// Registers dispatches over splat_
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_REGISTER_DISPATCH ( tag::splat_, tag::cpu_, (A0)(A1)
                      , (fundamental_<A0>)
                        ((target_< simd_< arithmetic_<A1>, tag::altivec_ > >))
                      )

////////////////////////////////////////////////////////////////////////////////
// Implements dispatches over splat_
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  template<class Dummy>
  struct  call< tag::splat_ ( tag::fundamental_
                            , tag::target_<tag::simd_<tag::arithmetic, tag::altivec_>
			    >
                            )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This, class A0,class A1>
    struct result<This(A0,A1)> : meta::strip<A1>::type {};

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      typedef typename BOOST_SIMD_RETURN_TYPE(2)::type type;
      typename type::extraction_type v;
      v.s[0] = a0;
      type that = {vec_splat(v.v, 0)};
      return that;
    }
  };
} } }

#endif
