/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_MEMORY_PADDING_HPP_INCLUDED
#define BOOST_SIMD_SDK_MEMORY_PADDING_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Padding strategies and related functors
////////////////////////////////////////////////////////////////////////////////
#include <boost/simd/sdk/meta/hierarchy.hpp>

namespace boost { namespace simd
{
  namespace tag { template<class T> struct padding_ {}; }

  namespace meta
  {
    template<class T> struct padding_ : unspecified_<T>
    {
      typedef unspecified_<T>   parent;
      typedef tag::padding_<T>  type;
    };
  }
} }

#endif
