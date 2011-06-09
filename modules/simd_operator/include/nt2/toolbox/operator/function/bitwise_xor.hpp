//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_BITWISE_XOR_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/operator/include.hpp>
#include <nt2/toolbox/operator/specific/common.hpp>

#include <boost/proto/tags.hpp>

namespace nt2
{
  namespace tag
  {
    typedef boost::proto::tag::bitwise_xor bitwise_xor_;
  }
  
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::bitwise_xor_      , bitwise_xor     , 2 )
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::bitwise_xor_      , b_xor           , 2 )
}

#include <nt2/toolbox/operator/function/scalar/bitwise_xor.hpp>
#include <nt2/toolbox/operator/function/simd/all/bitwise_xor.hpp>

#endif
