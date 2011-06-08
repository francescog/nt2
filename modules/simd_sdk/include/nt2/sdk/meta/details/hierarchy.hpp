//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_META_DETAILS_HIERARCHY_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_DETAILS_HIERARCHY_HPP_INCLUDED

namespace boost { namespace simd { namespace tag
{
  //============================================================================
  // Tag for unknown types
  //============================================================================
  struct unknown_     {};

  //============================================================================
  // Tag for unspecified types
  //============================================================================
  struct unspecified_ {};

  //============================================================================
  // Tag for void
  //============================================================================
  struct void_        {};

  //============================================================================
  // Tag for native boolean types
  //============================================================================
  struct bool_        {};

  //============================================================================
  // Tag for native types and native arithmetic types
  //============================================================================
  struct fundamental_ {}; struct arithmetic_  {};

  //============================================================================
  // Tag for all native integral types and qll native floating point types
  //============================================================================
  struct integer_     {}; struct real_        {};

  //============================================================================
  // Tag for native signed adn unsigned types
  //============================================================================
  struct signed_      {}; struct unsigned_    {};

  //============================================================================
  // Tag for native integral types sorted by signedness
  //============================================================================
  struct int_         {}; struct uint_        {};

  //============================================================================
  // Tag for native types sorted by byte size
  //============================================================================
  struct type8_       {}; struct type16_      {};
  struct type32_      {}; struct type64_      {};

  //============================================================================
  // Tag for native floating point types sorted by byte size
  //============================================================================
  struct float_       {}; struct double_      {};
  struct long_double_ {};
  //============================================================================
  // Tag for native integral types sorted by byte size
  //============================================================================
  struct ints8_       {}; struct ints16_      {};
  struct ints32_      {}; struct ints64_      {};

  //============================================================================
  // Tag for native signed integral types sorted by byte size
  //============================================================================
  struct int8_        {}; struct int16_       {};
  struct int32_       {}; struct int64_       {};

  //============================================================================
  // Tag for native unsigned integral types sorted by byte size
  //============================================================================
  struct uint8_       {}; struct uint16_      {};
  struct uint32_      {}; struct uint64_      {};
} } }

#endif
