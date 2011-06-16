//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//============================================================================== 
#ifndef BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_FALSE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_CONSTANT_CONSTANTS_FALSE_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/sdk/simd_constant/constant.hpp>
#include <nt2/toolbox/constant/include.hpp>
#include <nt2/sdk/simd_constant/common.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct false_  {};
  }
  
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::false_, False)
} }

#include <nt2/toolbox/constant/constants/scalar/false.hpp>
#include <nt2/toolbox/constant/constants/simd/all/false.hpp>

#endif
