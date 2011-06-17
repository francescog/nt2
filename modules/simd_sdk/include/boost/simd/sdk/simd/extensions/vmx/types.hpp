/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_EXTENSIONS_VMX_TYPES_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_EXTENSIONS_VMX_TYPES_HPP_INCLUDED

#include <boost/simd/sdk/config/type_lists.hpp>

#define BOOST_SIMD_TYPES  (float)(nt2::uint32_t)(nt2::int32_t)  \
                          (nt2::uint16_t)(nt2::int16_t)         \
                          (nt2::uint8_t)(nt2::int8_t)           \
/**/

#define BOOST_SIMD_REAL_TYPES (float)
/**/

#define BOOST_SIMD_UNSIGNED_TYPES (nt2::uint32_t)(nt2::uint16_t)(nt2::uint8_t)  \
/**/

#define BOOST_SIMD_INTEGRAL_TYPES (nt2::uint32_t)(nt2::uint16_t)(nt2::uint8_t)  \
                                  (nt2::int32_t)(nt2::int16_t)(nt2::int8_t)     \
/**/

#define BOOST_SIMD_SIGNED_TYPES (nt2::int32_t)(float)(nt2::int16_t)(nt2::int8_t)  \
/**/

#define BOOST_SIMD_INTEGRAL_UNSIGNED_TYPES  (nt2::uint32_t)(nt2::uint16_t)(nt2::uint8_t)  \
/**/

#define BOOST_SIMD_INTEGRAL_SIGNED_TYPES  (nt2::int32_t)(nt2::int16_t)(nt2::int8_t) \
/**/

#define BOOST_SIMD_REAL_CONVERTIBLE_TYPES  (nt2::int32_t)(nt2::uint32_t)(float) \
/**/

#endif
