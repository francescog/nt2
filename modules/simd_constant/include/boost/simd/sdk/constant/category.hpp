/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_CONSTANT_CATEGORY_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONSTANT_CATEGORY_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Category for constants
//* TODO:  Documentation: http://nt2.lri.fr/sdk/constant/meta/category.html
////////////////////////////////////////////////////////////////////////////////
#include <boost/simd/sdk/meta/as.hpp>
#include <boost/simd/sdk/meta/hierarchy_of.hpp>

////////////////////////////////////////////////////////////////////////////////
// constant_ wraps a constant type into a EDSL element and has its own hierarchy
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd {
{
  namespace tag { template<class ID> struct constant_ { typedef ID type; }; }
  namespace meta
  {
    template<class T> struct constant_ : unspecified_<T>
    {
      typedef unspecified_<T>   parent;
      typedef tag::constant_<T> type;
    };
  }
} }

namespace boost { namespace simd {
{
  template<class ID>
  struct constant_ { typedef meta::constant_<ID> nt2_hierarchy_tag; };
} }

#endif
