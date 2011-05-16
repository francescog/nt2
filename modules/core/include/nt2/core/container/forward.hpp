//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_FORWARD_HPP_INCLUDED
#define NT2_CORE_CONTAINER_FORWARD_HPP_INCLUDED

/*!
 * \file
 * Defines forward declarations for container classes
 */

/*!
 * \defgroup container NT2 Containers
 * Classes and function related to containers usage
 */


/*!
 * \ingroup container
 * \defgroup containerhelper Container helpers
 * Classes and function related to containers usage
 */
#include <nt2/sdk/dsl/call.hpp>
#include <boost/proto/proto.hpp>

//==============================================================================
/*!
 * \ingroup container
 * \namespace nt2::container
 * Namespace holding all NT2 container and container related classes
 */
//==============================================================================
namespace nt2 { namespace container
{
  template<class Tag, class Type, class Settings> struct facade;
  template<class Dimensions> struct  extent;
} }

#endif
