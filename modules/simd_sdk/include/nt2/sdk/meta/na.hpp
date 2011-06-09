//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_META_NA_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_NA_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the nt2::meta::na_ type
 */

namespace boost { namespace simd { namespace meta
{
  //============================================================================
  /*!
   * Empty type used to represent empty elements in compile-time containers.
   * nt2::meta::na_ is used in \nt2 to prevent some ADL issues with Boost.MPL.
   */
  //============================================================================
  struct na_ { typedef na_ type; };
} } }

#endif