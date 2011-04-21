//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_OF_SIZE_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_OF_SIZE_HPP_INCLUDED

#include <nt2/core/container/extent.hpp>

namespace nt2
{
  //////////////////////////////////////////////////////////////////////////////
  // Return an empty extent
  //////////////////////////////////////////////////////////////////////////////
  extent<1> of_size() { return extent<1>(); }

  #define M0(z,n,t)                                             \
  template<BOOST_PP_ENUM_PARAMS(n,class D)>                     \
  extent<n> of_size(BOOST_PP_ENUM_BINARY_PARAMS(n,const D, &d)) \
  {                                                             \
    extent<n> that(BOOST_PP_ENUM_PARAMS(n,d));                  \
    return that;                                                \
  }                                                             \
  /**/

  //////////////////////////////////////////////////////////////////////////////
  // Builds of_size overload up to NT2_MAX_DIMENSIONS
  //////////////////////////////////////////////////////////////////////////////
  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

  #undef M0
}

#endif
