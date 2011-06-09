/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_EXTENSIONS_VMX_ALTIVEC_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_EXTENSIONS_VMX_ALTIVEC_HPP_INCLUDED

#include <nt2/simd_sdk/error/warning.hpp>

////////////////////////////////////////////////////////////////////////////////
// No SIMD extensions have been found yet
////////////////////////////////////////////////////////////////////////////////
#if !defined(BOOST_SIMD_DETECTED) && defined(BOOST_HAS_VMX_SUPPORT)

////////////////////////////////////////////////////////////////////////////////
// Check for active Altivec extension
////////////////////////////////////////////////////////////////////////////////
#if defined(__ALTIVEC__) || defined(__VEC__)

////////////////////////////////////////////////////////////////////////////////
// Report discovery of Altivec support
////////////////////////////////////////////////////////////////////////////////
BOOST_WARNING(AltiVec SIMD extension detected)

////////////////////////////////////////////////////////////////////////////////
// Include the proper intrinsic include. Depending of the option used by the
// compiler (-faltivec or -maltivec), we need to include altivec.h or not.
////////////////////////////////////////////////////////////////////////////////
  #if defined( __GNUC__ )
    #if (__APPLE_CC__ <= 1)
      #include <altivec.h>
      #undef bool
      #undef pixel
      #undef vector
    #endif
  #endif

////////////////////////////////////////////////////////////////////////////////
// Altivec PPC extensions flags
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_DETECTED
#define BOOST_SIMD_ALTIVEC
#define BOOST_SIMD_STRING             "Altivec"
#define BOOST_SIMD_STRING_LIST        "Altivec"
#define BOOST_SIMD_VMX_FAMILY
#define BOOST_SIMD_BYTES              16
#define BOOST_SIMD_BITS               128
#define BOOST_SIMD_CARDINALS          (4)(8)(16)
#define BOOST_SIMD_TAG_SEQ            (::boost::simd::tag::altivec_)
#define BOOST_SIMD_DEFAULT_EXTENSION  ::boost::simd::tag::altivec_
#define BOOST_SIMD_DEFAULT_SITE       ::boost::simd::tag::altivec_

#include <nt2/simd_sdk/simd/extensions/meta/altivec.hpp>

#endif
#endif
#endif
