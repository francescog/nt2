//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_COMPARE_EQUAL_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/simd/include/functor.hpp>
#include <boost/simd/toolbox/operator/include.hpp>
#include <boost/simd/toolbox/operator/specific/common.hpp>

#include <boost/simd/toolbox/operator/specific/compare_tags.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::compare_equal_, compare_equal , 2 )
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::compare_equal_, compare_eq    , 2 )
} }

#include <boost/simd/toolbox/operator/function/scalar/compare_equal.hpp>
#include <boost/simd/toolbox/operator/function/simd/all/compare_equal.hpp>

#endif
