/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_META_IS_CONTAINER_HPP_INCLUDED
#define NT2_CORE_CONTAINER_META_IS_CONTAINER_HPP_INCLUDED

#include <boost/mpl/bool.hpp>

namespace nt2 { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // Check if a given type is a nt2 container tag or not
  //////////////////////////////////////////////////////////////////////////////
  template< class T, class Enabled = void>
  struct  is_container_tag
        : boost::mpl::false_
  {};

  template<class T>
  struct  is_container_tag<T,typename T::nt2_container_tag>
        : boost::mpl::true_
  {};

  //////////////////////////////////////////////////////////////////////////////
  // Check if a given type is a nt2 container - cheap but effective
  //////////////////////////////////////////////////////////////////////////////
  template< class T, class Enabled = void>
  struct  is_container
        : boost::mpl::false_
  {};

  template<class T>
  struct  is_container<T,typename T::proto_is_expr_>
        : is_container_tag<typename T::proto_tag>
  {};
} }


#endif
