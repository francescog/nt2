//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//============================================================================== 
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SPLAT_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/simd/toolbox/operator/include.hpp>
#include <boost/simd/sdk/meta/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct splat_  {};
  }
  
  template<class T, class A0> inline
  typename meta::enable_call<tag::splat_(A0, meta::as_<T>)>::type
  splat(A0 const& a0)
  {
    typename make_functor<tag::splat_, A0>::type callee;
    return callee(a0, meta::as_<T>() );
  }
} }

#include <boost/simd/toolbox/operator/function/scalar/splat.hpp>
#include <boost/simd/toolbox/operator/function/simd/all/splat.hpp>

#endif
