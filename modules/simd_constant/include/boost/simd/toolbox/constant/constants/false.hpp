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
#include <boost/simd/include/simd.hpp>
#include <boost/simd/sdk/simd_constant/constant.hpp>
#include <boost/simd/toolbox/constant/include.hpp>
#include <boost/simd/sdk/simd_constant/common.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct false_  {};
  }
  
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::false_, False)
} }

#include <boost/simd/toolbox/constant/constants/scalar/false.hpp>
#include <boost/simd/toolbox/constant/constants/simd/all/false.hpp>

#endif
