/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_DETAILS_NATIVE_META_HIERARCHY_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_DETAILS_NATIVE_META_HIERARCHY_OF_HPP_INCLUDED

#include <nt2/simd_sdk/meta/hierarchy_of.hpp>

namespace boost { namespace simd { namespace meta
{
  template<class Scalar,class Extension>
  struct hierarchy_of< simd::native<Scalar,Extension> >
  {
    typedef meta::simd_ < typename meta::hierarchy_of<Scalar>::type
                        , Extension
                        >                                   type;
  };
} } }

#endif
