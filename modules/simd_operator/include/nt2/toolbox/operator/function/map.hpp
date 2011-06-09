//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_MAP_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTION_SIMD_MAP_HPP_INCLUDED

#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/operator/include.hpp>

namespace boost { namespace simd {
  namespace tag { struct map_ {}; }
}

namespace boost { namespace simd
{
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::map_,map,2)
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::map_,map,3)
  BOOST_SIMD_FUNCTION_IMPLEMENTATION(tag::map_,map,4)
} }

#include <nt2/toolbox/operator/function/simd/all/map.hpp>

#endif
