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
    // Callable Object conformance
    //==========================================================================
    template<class Position>
    typename boost::
    lazy_enable_if< boost::fusion::traits::is_sequence<Position>
                  , meta::call<tag::value_at_(container const&,Position)>
                  >::type
    operator()(Position const& p) const
    {
      return nt2::value_at( *this, p );
    }

    template<class Position>
    typename boost::
    lazy_enable_if< boost::fusion::traits::is_sequence<Position>
                  , meta::call<tag::value_at_(container&,Position)>
                  >::type
    operator()(Position const& p)
    {
      return nt2::value_at( *this, p );
    }

    //==========================================================================
    // MultiCollection conformance
    //==========================================================================
    typedef std::size_t                             size_type;
    typedef size_type                               base_type;
    typedef std::ptrdiff_t                          difference_type;

    //==========================================================================
    /*! Validate a Position inside the current extent expression.
     *
     * \param p A \fusionras containinga position inside curent extent
     * \return \c true if \c p can be used safely to access an element of the
     * extent, \c false otherwise
     */
    //==========================================================================
    template<class Position> inline
    bool validate( Position const& p ) const
    {
      return validate(p, typename boost::mpl::size<Position>::type() );
    }

    protected:
    template<class Position> inline
    bool validate( Position const& p, boost::mpl::size_t<1> const& ) const
    {
      return  boost::fusion::front(p) <= static_dimensions
          ||  boost::fusion::front(p) >= 1;
    }

    template<class Position> inline
    bool validate( Position const& p, boost::mpl::size_t<2> const& ) const
    {
      return  boost::fusion::at_c<0>(p) == 1
          &&  (   boost::fusion::at_c<1>(p) <= static_dimensions
              ||  boost::fusion::at_c<1>(p) >= 1
              );
    }

    template<std::size_t N, class Position> inline
    bool validate( Position const& p, boost::mpl::size_t<N> const& ) const
    {
      return  boost::fusion::at_c<N-1>(p) == 1
          &&  validate(p,boost::mpl::size_t<N-1>());
    }

    public:
    //==========================================================================
    /*! Return the number of dimensions stored in the extent.                 */
    //==========================================================================
    inline size_type size() const { return static_dimensions; }

    //==========================================================================
    /*! Return if an \ref extent is empty.                                    */
    //==========================================================================
    inline bool empty() const { return (size() == 0); }

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
    inline base_type lower(std::size_t i) const { return 1; }

    //==========================================================================
    /*!
     * Return the highest valid index to access the ith dimension of current \ref
     * extent.
     *
     * \param i Dimension to retrieve the lower index from.
     * \return The highest valid index of the \ref extent along this dimension.
     *
     * \see Container
     */
    //==========================================================================
    inline difference_type upper(std::size_t i) const
    {
      return (i==2 && static_dimensions) ? static_dimensions : 1;
    }

    //==========================================================================
    /*!
     * Return the value of the size of current \ref extent along the ith
     * dimension.
     *
     * \param i Dimension to retrieve the size from.
     * \return The size of the \ref extent along this dimension.
     */
    //==========================================================================
    inline size_type  size(std::size_t i) const
    {
      return (i==2 && static_dimensions) ? static_dimensions : 1;
    }

    #define NT2_ACCESS_CONST
    //#include <nt2/core/container/details/access.hpp>

  };
} }

#endif
