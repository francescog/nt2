/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_EXTENSIONS_SSE_SSE4A_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_EXTENSIONS_SSE_SSE4A_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// No SIMD extensions have been found yet
////////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_SIMD_DETECTED) && defined(BOOST_SIMD_HAS_SSE4A_SUPPORT)

////////////////////////////////////////////////////////////////////////////////
// Check for SSE4A
////////////////////////////////////////////////////////////////////////////////
#if defined(__SSE4A__) || defined(_MSC_VER)

////////////////////////////////////////////////////////////////////////////////
// Report  SSE4A discovery
////////////////////////////////////////////////////////////////////////////////
BOOST_SIMD_WARNING(SSE4A SIMD extension detected)

////////////////////////////////////////////////////////////////////////////////
//  SSE4A extensions flags
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_DETECTED
#define BOOST_SIMD_SSE4A
#define BOOST_SIMD_SSE_FAMILY
#define BOOST_SIMD_STRING             "SSE4A"
#define BOOST_SIMD_STRING_LIST        "SSE2 SSE3 SSSE3 SSE4A"
#define BOOST_SIMD_BYTES              16
#define BOOST_SIMD_BITS               128
#define BOOST_SIMD_CARDINALS          (2)(4)(8)(16)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::tag::sse_)
#define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::tag::sse_
#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::tag::sse4a_

extern "C"
{
  #include <ammintrin.h>
}

#include <nt2/simd_sdk/simd/extensions/meta/sse.hpp>

#endif
#endif
#endif
