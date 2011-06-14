//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_DOMAIN_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_DOMAIN_HPP_INCLUDED

#include <nt2/extension/parameters.hpp>
#include <nt2/core/container/dsl/grammar.hpp>
#include <nt2/core/container/details/table/generator.hpp>

//==============================================================================
// Table of dimension N are living in a domain which is upward-compatible with
// table of dimension N+1, and thus up to NT2_MAX_DIMENSIONS with has no
// parent domain.
//==============================================================================
namespace nt2 { namespace containers
{
  template<std::size_t Dim, class Dummy>
  struct  domain<tag::table_, boost::mpl::size_t<Dim>, Dummy >
        : boost::proto::domain< containers::generator < tag::table_
                                                      , boost::mpl::size_t<Dim>
                                                      >
                              , containers::grammar<tag::table_>
                              , domain< tag::table_
                                      , boost::mpl::size_t<Dim+1>
                                      , Dummy
                                      >
                              >
  {};

  template<class Dummy>
  struct  domain<tag::table_, boost::mpl::size_t<NT2_MAX_DIMENSIONS>,Dummy>
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
