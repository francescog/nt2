/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_DSL_TERMINAL_OF_HPP_INCLUDED
#define NT2_SDK_DSL_TERMINAL_OF_HPP_INCLUDED

#include <boost/proto/traits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <boost/mpl/placeholders.hpp>

namespace nt2 { namespace ext
{
  //////////////////////////////////////////////////////////////////////////////
  // By default we just return the type itself
  //////////////////////////////////////////////////////////////////////////////
  template< class Expr, class Domain >
  struct terminal_of_impl : boost::mpl::_1
  {};
} }

////////////////////////////////////////////////////////////////////////////////
// For a given proto expression type, acts as a meta-function able to build a
// terminal suitable for its domain
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template< class Expr >
  struct  terminal_of
        : ext::terminal_of_impl < typename strip<Expr>::type
                                , typename boost::proto::domain_of<Expr>::type
                                >
  {};
} }

#endif
