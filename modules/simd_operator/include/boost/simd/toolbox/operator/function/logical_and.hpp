//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_LOGICAL_AND_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/simd/include/functor.hpp>
#include <boost/simd/toolbox/operator/include.hpp>
#include <boost/simd/toolbox/operator/specific/common.hpp>

#include <boost/proto/tags.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    typedef boost::proto::tag::logical_and logical_and_;
  }
  
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::logical_and_      , logical_and     , 2 )
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::logical_and_      , l_and           , 2 )
} }

#include <boost/simd/toolbox/operator/function/scalar/logical_and.hpp>
#include <boost/simd/toolbox/operator/function/simd/all/logical_and.hpp>

#endif
