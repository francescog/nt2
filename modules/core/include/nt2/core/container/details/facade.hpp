//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_FACADE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_FACADE_HPP_INCLUDED

/*!
 * \file
 * \brief Defines the facade extension point for container classes
 */

namespace nt2 { namespace ext
{
  //============================================================================
  /*! facade is an extension point in which all the required element of a
   * container class are agthered and processed to build the proper terminal
   * type using the class Tag, Settings and data Type.
   *
   * \tparam Tag Tag identifying the container domain
   * \tparam Type Data type used as a value type in the container
   * \tparam Settings User-defined options driving the container setup
   *
   */
  //============================================================================
  template<class Tag, class Type, class Settings> struct facade;
} }

#endif
