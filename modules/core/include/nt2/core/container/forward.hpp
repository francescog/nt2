/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_FORWARD_HPP_INCLUDED
#define NT2_CORE_CONTAINER_FORWARD_HPP_INCLUDED

#include <nt2/sdk/dsl/call.hpp>
#include <boost/proto/proto.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // Container facade gather informations about a container terminal and builds
  // all the boilerplate involved.
  //////////////////////////////////////////////////////////////////////////////
  template<class Tag, class Type, class Settings> struct facade;

  //////////////////////////////////////////////////////////////////////////////
  // extent represnet the iteration space of a nD container
  //////////////////////////////////////////////////////////////////////////////
  template< std::size_t D
          , class T     = std::size_t
          , class Dummy = boost::proto::is_proto_expr
          >
  struct  extent;
} }

#endif
