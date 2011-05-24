/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_DOMAIN_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_DOMAIN_HPP_INCLUDED

#include <boost/proto/proto.hpp>
#include <nt2/extension/parameters.hpp>
#include <nt2/core/container/dsl/domain.hpp>
#include <nt2/core/container/dsl/grammar.hpp>
#include <nt2/core/container/dsl/generator.hpp>

////////////////////////////////////////////////////////////////////////////////
// Define tag for table_ related domain specialization
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace tag
{
  struct table_ { typedef void nt2_container_tag; };
} }

////////////////////////////////////////////////////////////////////////////////
// Tell proto that in the container::domain, all expressions should be
// wrapped in container::expr<> using container::generator. Moreover, build the
// relationship between domains with respect to the value of the dimension.
// Table of dimension N are living in a domain which is upward-compatible with
// table of dimension N+1, adn thus up to NT2_MAX_DIMENSIONS
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace containers
{
  template<std::size_t Dim>
  struct  domain<tag::table_, boost::mpl::size_t<Dim> >
        : boost::proto::domain< containers::generator < tag::table_
                                                      , boost::mpl::size_t<Dim>
                                                      >
                              , containers::grammar<tag::table_>
                              , domain<tag::table_,boost::mpl::size_t<Dim+1> >
                              >
  {};

  template<>
  struct  domain<tag::table_, boost::mpl::size_t<NT2_MAX_DIMENSIONS> >
        : boost::proto::
          domain< containers::generator < tag::table_
                                        , boost::mpl::
                                          size_t<NT2_MAX_DIMENSIONS>
                                        >
                , containers::grammar<tag::table_>
                >
  {};
} }

#endif
