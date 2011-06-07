//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_CONTAINER_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_CONTAINER_HPP_INCLUDED

/*!
 * \file
 * \brief Implemets the container behavior for extent and extent expressions
 */

#include <boost/fusion/include/single_view.hpp>

namespace nt2 { namespace containers
{
  //============================================================================
  // Domain-specific expression wrapper for extent expression
  //============================================================================
  template<class AST, class Dims>
  struct  container<AST,tag::extent_,Dims>
        : boost::proto::extends < AST
                                , container<AST,tag::extent_,Dims>
                                , domain<tag::extent_,Dims>
                                >
  {
    //==========================================================================
    // Internal proto related types
    //==========================================================================
    typedef boost::proto::extends < AST
                                  , container<AST,tag::extent_,Dims>
                                  , domain<tag::extent_,Dims>
                                  >                                     parent;

    //==========================================================================
    // Hierarchy and semantic of container:::expression
    //==========================================================================
    typedef typename
    details::hierarchy_of_expr<container>::type     nt2_hierarchy_tag;

    BOOST_STATIC_CONSTANT(std::size_t, static_dimensions = Dims::value );

    //==========================================================================
    // Proto required interface
    //==========================================================================
    explicit container( AST const& xpr = AST() ): parent(xpr) {}
    BOOST_PROTO_EXTENDS_USING_ASSIGN(container)

    //==========================================================================
    // Sequence conformance
    //==========================================================================
    typedef std::size_t                             value_type;
    typedef std::size_t                             const_reference;
    typedef std::size_t                             reference;

    const_reference operator()(std::size_t i) const
    {
      return nt2::value_at( *this, boost::fusion::single_view<int>(i) );
    }
  };
} }

#endif
