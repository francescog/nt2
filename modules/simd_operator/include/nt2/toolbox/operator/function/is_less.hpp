//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_IS_LESS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_IS_LESS_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/simd_operator/include.hpp>
#include <nt2/toolbox/simd_operator/specific/common.hpp>

#include <boost/proto/tags.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    typedef boost::proto::tag::less is_less_;
  }
  
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::is_less_, is_less , 2 )
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::is_less_, lt      , 2 )
} }

#include <nt2/toolbox/simd_operator/function/scalar/is_less.hpp>
#include <nt2/toolbox/simd_operator/function/simd/all/is_less.hpp>

#endif
