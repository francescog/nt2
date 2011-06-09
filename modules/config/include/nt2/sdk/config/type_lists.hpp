/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/


#ifndef BOOST_SIMD_SDK_CONFIG_TYPE_LISTS_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_TYPE_LISTS_HPP_INCLUDED


#if !defined(BOOST_SIMD_TYPES)
#define BOOST_SIMD_TYPES  (nt2::uint64_t)    \
    (nt2::int64_t)(double)		     \
    (nt2::uint32_t)(nt2::int32_t)(float)     \
    (nt2::uint16_t)(nt2::int16_t)	     \
    (nt2::uint8_t) (nt2::int8_t)	     \
/**/
#endif

#if !defined(BOOST_SIMD_REAL_TYPES)
#define BOOST_SIMD_REAL_TYPES	     \
  (double)			     \
  (float)			     \
/**/
#define BOOST_SIMD_REAL BOOST_SIMD_REAL_TYPES
#endif

#if !defined(BOOST_SIMD_REAL_CONVERTIBLE_TYPES)
#define BOOST_SIMD_REAL_CONVERTIBLE_TYPES    \
  (nt2::uint64_t)(nt2::int64_t)(double)	     \
    (nt2::uint32_t)(nt2::int32_t)(float)     \
/**/
#endif

#if !defined(BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
#define BOOST_SIMD_INTEGRAL_SIGNED_TYPES  (nt2::int64_t) \
    (nt2::int32_t)					 \
    (nt2::int16_t)					 \
    (nt2::int8_t)					 \
/**/
#endif

#if !defined(BOOST_SIMD_UNSIGNED_TYPES)
#define BOOST_SIMD_UNSIGNED_TYPES  (nt2::uint64_t) \
    (nt2::uint32_t)			           \
    (nt2::uint16_t)			           \
    (nt2::uint8_t)			           \
/**/
#endif

#if !defined(BOOST_SIMD_INTEGRAL_TYPES)
#define BOOST_SIMD_INTEGRAL_TYPES  (nt2::uint64_t)      \
    (nt2::int64_t)(nt2::uint32_t)			\
    (nt2::int32_t)(nt2::uint16_t)(nt2::int16_t)		\
    (nt2::int8_t)(nt2::uint8_t)				\
/**/
#endif

#if !defined(BOOST_SIMD_SIGNED_TYPES)
#define BOOST_SIMD_SIGNED_TYPES (nt2::int64_t)(double) \
    (nt2::int32_t)(float)			       \
    (nt2::int16_t)				       \
    (nt2::int8_t)				       \
/**/
#endif

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of type_lists.hpp
// /////////////////////////////////////////////////////////////////////////////
