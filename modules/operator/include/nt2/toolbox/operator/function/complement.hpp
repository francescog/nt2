//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_COMPLEMENT_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_COMPLEMENT_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/operator/include.hpp>
#include <nt2/toolbox/operator/specific/common.hpp>

#include <boost/proto/tags.hpp>

namespace nt2
{
  namespace tag
  {
    typedef boost::proto::tag::complement complement_;
  }
  
  NT2_FUNCTION_IMPLEMENTATION(tag::complement_ , complement  , 1 )
  NT2_FUNCTION_IMPLEMENTATION(tag::complement_ , bitwise_not , 1 )
  NT2_FUNCTION_IMPLEMENTATION(tag::complement_ , b_not       , 1 )
}

#include <nt2/toolbox/operator/function/scalar/complement.hpp>
#include <nt2/toolbox/operator/function/simd/all/complement.hpp>

#endif
