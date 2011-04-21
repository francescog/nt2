/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_PACK_EXPRESSION_HPP_INCLUDED
#define NT2_SDK_SIMD_PACK_EXPRESSION_HPP_INCLUDED

#include <nt2/sdk/details/type_id.hpp>
#include <boost/proto/proto.hpp>
#include <nt2/sdk/dsl/category.hpp>
#include <nt2/sdk/dsl/is_assignment_expression.hpp>

namespace nt2 { namespace container
{
  ////////////////////////////////////////////////////////////////////////////
  // Here is the domain-specific expression wrapper for table_ expression
  ////////////////////////////////////////////////////////////////////////////
  template<class Expr, class Tag, class Dims>
  struct  expression
        : boost::proto::extends < Expr
                                , expression<Expr,Tag,Dims>
                                , domain<Tag,Dims>
                                >
  {
    ////////////////////////////////////////////////////////////////////////////
    // Internal proto related types
    ////////////////////////////////////////////////////////////////////////////
    typedef boost::proto::extends < Expr
                                  , expression<Expr,Tag,Dims>
                                  , domain<Tag,Dims>
                                  >                                     parent;

    ////////////////////////////////////////////////////////////////////////////
    // expression hierarchy and semantic of container:::expression
    ////////////////////////////////////////////////////////////////////////////
    typedef typename
    details::hierarchy_of_expr<expression>::type nt2_hierarchy_tag;

    BOOST_PROTO_EXTENDS_USING_ASSIGN(expression)

    ////////////////////////////////////////////////////////////////////////////
    // Default explicit constructor
    ////////////////////////////////////////////////////////////////////////////
    explicit  expression( Expr const& xpr = Expr() )
            : parent(xpr)
            , is_silent(!meta::is_assignment_expression<Expr>::value)
    {
      silence(xpr,typename meta::is_assignment_expression<Expr>::type());
    }

    ////////////////////////////////////////////////////////////////////////////
    // Destructor performs evaluation if required
    ////////////////////////////////////////////////////////////////////////////
    ~expression()
    {
      if(!is_silent) (*this)();
    }

    ////////////////////////////////////////////////////////////////////////////
    // container expression are read-only Ranges
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // container expression have a nullary operator() that evaluates itself
    ////////////////////////////////////////////////////////////////////////////
    void operator()()
    {
      // current_target::evaluate(*this);
    }

    ////////////////////////////////////////////////////////////////////////////
    // External accessor for evaluation trigger
    ////////////////////////////////////////////////////////////////////////////
    void silence() const { is_silent = true; }

    protected:
    ////////////////////////////////////////////////////////////////////////////
    // Trigger for non-evaluation at destruction-time.
    ////////////////////////////////////////////////////////////////////////////
    void silence(Expr const& xpr, boost::mpl::true_  const&) const
    {
      boost::proto::right(*this).silence();
    }

    void silence(Expr const&, boost::mpl::false_ const&) const {}

    mutable bool is_silent;
  };
} }

#endif
