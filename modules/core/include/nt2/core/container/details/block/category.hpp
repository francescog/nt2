/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_BLOCK_CATEGORY_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_BLOCK_CATEGORY_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Basic category registration
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/types.hpp>
#include <nt2/sdk/meta/hierarchy_of.hpp>

////////////////////////////////////////////////////////////////////////////////
// Block types tag
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  namespace tag { template<class T,class S> struct block_ {}; }

  //////////////////////////////////////////////////////////////////////////////
  // simd types hierarchy
  //////////////////////////////////////////////////////////////////////////////
  namespace meta
  {
    template<class T,class S> struct block_ : block_<typename T::parent,S>
    {
      typedef block_<typename T::parent,S>     parent;
      typedef tag::block_<typename T::type,S>  type;
    };

    template<class T,class S> struct block_< unknown_<T>,S > : unknown_<T> {};
  }
}

#endif
