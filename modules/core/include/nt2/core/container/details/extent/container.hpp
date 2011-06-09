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
 * \brief Implements the container behavior for extent and extent expressions
 */

#include <boost/fusion/include/make_vector.hpp>

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
    typedef std::size_t                             size_type;
    typedef std::size_t                             difference_type;

    //==========================================================================
    /*!
     * Return the lowest valid index to access the ith dimension of current \ref
     * extent.
     *
     * \param i Dimension to retrieve the lower index from.
     * \return The lowest valid index of the \ref extent along this dimension.
     *
     * \see Container
     */
    //==========================================================================
    static inline base_type lower(std::size_t i) { return 1; }

    //==========================================================================
    /*! Return the number of dimensions stored in the extent.                */
    //==========================================================================
    static inline size_type size() { return static_dimensions; }

    //==========================================================================
    /*! Return if an \ref extent is empty.                                   */
    //==========================================================================
    static inline bool empty() { return (size() == 0); }

    #define NT2_ACCESS_CONST
    //#include <nt2/core/container/details/access.hpp>

    template<class Position>
    const_reference operator()(Position const& p) const
    {
      return nt2::value_at( *this, p );
    }
  };
} }

#endif
