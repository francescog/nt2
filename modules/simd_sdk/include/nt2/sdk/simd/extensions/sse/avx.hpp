/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_EXTENSIONS_SSE_AVX_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_EXTENSIONS_SSE_AVX_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// No SIMD extensions have been found yet
////////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_SIMD_DETECTED) && defined(BOOST_SIMD_HAS_AVX_SUPPORT)

////////////////////////////////////////////////////////////////////////////////
// Check for AVX
////////////////////////////////////////////////////////////////////////////////
#if defined(__AVX__) || defined(_MSC_VER)

////////////////////////////////////////////////////////////////////////////////
// Report AVX discovery
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_WARNING(AVX SIMD extension detected)

////////////////////////////////////////////////////////////////////////////////
// AVX extensions flags
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_DETECTED
#define BOOST_SIMD_AVX
#define BOOST_SIMD_SSE_FAMILY
#define BOOST_SIMD_STRING             "AVX"
#define BOOST_SIMD_STRING_LIST        "SSE2 SSE3 SSSE3 SSE4_1 SSE4_2 AVX"
#define BOOST_SIMD_BYTES              32
#define BOOST_SIMD_BITS               256
#define BOOST_SIMD_CARDINALS          (2)(4)(8)(16)(32)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::tag::avx_)(::boost::simd::tag::sse_)
#define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::tag::avx_
#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::tag::avx_

extern "C"
{
  #include <immintrin.h>
}

#include <nt2/simd_sdk/simd/extensions/meta/sse.hpp>
#include <nt2/simd_sdk/simd/extensions/meta/avx.hpp>

#endif
#endif
#endif
