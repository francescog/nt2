/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_GENERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_GENERATOR_HPP_INCLUDED

namespace nt2 { namespace containers
{
  //////////////////////////////////////////////////////////////////////////////
  // Container Expression check if their size are compatible before being built
  // Depending on tag and types, a static or runtime assertion can be triggered
  //////////////////////////////////////////////////////////////////////////////
  template<class Dimension>
  struct generator<tag::table_, Dimension>
  {
    template<class Sig> struct result;
    template<class This, class Expr>
    struct result<This(Expr)>
    {
      typedef container<Expr,tag::table_,Dimension> type;
    };

    template<class Expr>
    typename result<generator(Expr)>::type const
    operator()(Expr const &xpr) const
    {
      typename result<generator(Expr)>::type const that(xpr);
      return that;
    }
  };
} }

#endif
