//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_META_ENABLE_IF_TYPE_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_ENABLE_IF_TYPE_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the nt2::meta::enable_if_type \metafunction
 */

namespace boost { namespace simd { namespace meta
{
  //============================================================================
  /*!
   * Provides a SFINAE context to test the existence of a given type.
   *
   * \tparam T Type to check existence of.
   * \tparam R Type to return if \c T is defined.
   *
   * \usage
   *
   * \include enable_if_type.cpp
   */
  //============================================================================
  template<class T, class R=void>  struct enable_if_type { typedef R type; };
} } }

#endif