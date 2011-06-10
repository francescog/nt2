//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_INCLUDE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_INCLUDE_HPP_INCLUDED
#include <nt2/simd_sdk/simd/preprocessor/include.hpp>

#define BOOST_SIMD_CONSTANT_BASE() nt2/toolbox/simdconstant/constants/scalar/
#define BOOST_SIMD_CONSTANT_RELATIVE() nt2/toolbox/simdconstant/constants/

#define BOOST_SIMD_CONSTANT_INCLUDE(F) BOOST_SIMD_SIMD_RELATIVE_INCLUDE(BOOST_SIMD_CONSTANT_RELATIVE, F)

#endif
