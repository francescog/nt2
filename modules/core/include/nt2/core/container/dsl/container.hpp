/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DSL_EXPRESSION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_EXPRESSION_HPP_INCLUDED

namespace nt2 { namespace containers
{
  ////////////////////////////////////////////////////////////////////////////
  // Here is the domain-specific expression wrapper for container expression
  ////////////////////////////////////////////////////////////////////////////
  template<class AST, class Tag, class Dims>
  struct  container
        : boost::proto::extends < AST
                                , container<AST,Tag,Dims>
                                , domain<Tag,Dims>
                                >
        , semantic< container<AST,Tag,Dims> >
  {
    ////////////////////////////////////////////////////////////////////////////
    // Internal proto related types
    ////////////////////////////////////////////////////////////////////////////
    typedef boost::proto::extends < AST
                                  , container<AST,Tag,Dims>
                                  , domain<Tag,Dims>
                                  >                                     parent;

    ////////////////////////////////////////////////////////////////////////////
    // expression hierarchy and semantic of container:::expression
    ////////////////////////////////////////////////////////////////////////////
    typedef typename
    details::hierarchy_of_expr<container>::type     nt2_hierarchy_tag;
    typedef semantic< container<AST,Tag,Dims> >     nt2_semantic_type;
    typedef typename nt2_semantic_type::fusion_tag  fusion_tag;

    BOOST_STATIC_CONSTANT(std::size_t, static_dimensions = Dims::value );

    ////////////////////////////////////////////////////////////////////////////
    // Default explicit constructor
    ////////////////////////////////////////////////////////////////////////////
    BOOST_PROTO_EXTENDS_USING_ASSIGN(container)

    explicit container( AST const& xpr = AST() ): parent(xpr) {}
  };
} }

#endif
