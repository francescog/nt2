/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_DOMAIN_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_DOMAIN_HPP_INCLUDED

#include <nt2/extension/parameters.hpp>
#include <nt2/core/container/dsl/grammar.hpp>
#include <nt2/core/container/details/table/domain.hpp>
#include <nt2/core/container/details/extent/generator.hpp>

////////////////////////////////////////////////////////////////////////////////
// Extents are table of dimension 2
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace containers
{
  template<class D>
  struct  domain<tag::extent_,D>
        : boost::proto::domain< containers::generator<tag::extent_,D>
                              , containers::grammar<tag::extent_>
                              , domain<tag::table_,boost::mpl::size_t<2> >
                              >
  {};
} }

#endif
