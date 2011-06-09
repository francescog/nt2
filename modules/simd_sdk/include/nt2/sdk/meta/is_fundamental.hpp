/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_META_IS_FUNDAMENTAL_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_IS_FUNDAMENTAL_HPP_INCLUDED

#include <nt2/simd_sdk/meta/hierarchy_of.hpp>
#include <boost/type_traits/is_base_of.hpp>

namespace boost { namespace simd { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // Is T a fundamental type ?
  //////////////////////////////////////////////////////////////////////////////
  template<class T>
  struct  is_fundamental
        : boost::is_base_of < meta::fundamental_<T>
                            , typename meta::hierarchy_of<T>::type
                            >
  {};
} } }

#endif
