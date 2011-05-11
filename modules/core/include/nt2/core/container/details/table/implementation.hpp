/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_IMPLEMENTATION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_IMPLEMENTATION_HPP_INCLUDED

#include <nt2/core/container/forward.hpp>
#include <nt2/core/container/details/table/facade.hpp>

namespace nt2 { namespace container
{
  template< class Type
          , class Settings = nt2::settings()
          , class Dummy    = boost::proto::is_proto_expr
          >
  struct  table
        : facade<tag::table_,Type,Settings>::type
  {
    ////////////////////////////////////////////////////////////////////////////
    // Basic sub-types needed elsewhere
    ////////////////////////////////////////////////////////////////////////////
    typedef facade<tag::table_,Type,Settings>             facade_type;
    typedef typename facade_type::type                    parent;
    typedef typename facade_type::data_type               data_type;
    typedef typename data_type::sizes_type                sizes_type;
    typedef typename data_type::bases_type                bases_type;

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor - tries to initialize if Size is static
    ////////////////////////////////////////////////////////////////////////////
    table() : parent()
    {
      init( typename facade_type::size_::type()
          , typename facade_type::size_::is_static()
          );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from extent
    ////////////////////////////////////////////////////////////////////////////
    template<class D>
    table( extent<D> const& szs ) : parent()
    {
      NT2_STATIC_ASSERT ( (!facade_type::size_::is_static::value)
                        , NT2_STATIC_TABLE_CANT_BE_DYNAMICALLY_CONSTRUCTED
                        , "You tried to construct a static table instance using "
                          "a dynamic dimension set."
                        );
      init( szs, boost::mpl::true_() );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Assignment from non-AST
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Container API
    ////////////////////////////////////////////////////////////////////////////
    typedef typename data_type::size_type       size_type;
    typedef typename data_type::difference_type difference_type;

    inline size_type size()  const
    {
      return boost::proto::value(*this).size();
    }

    inline bool empty() const { return boost::proto::value(*this).empty(); }

    ////////////////////////////////////////////////////////////////////////////
    // Size and Bases related accessor
    ////////////////////////////////////////////////////////////////////////////
    inline size_type size(std::size_t i) const
    {
      return boost::proto::value(*this).size(i);
    }

    inline sizes_type const& sizes() const
    {
      return boost::proto::value(*this).sizes();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return the starting index on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    inline difference_type lower(std::size_t i) const
    {
      return boost::proto::value(*this).lower(i);
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return the ending index on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    inline difference_type upper(std::size_t i) const
    {
      return boost::proto::value(*this).upper(i);
    }

    using parent::operator=;

    protected:

    template<class Sizes>
    void init( Sizes const&, boost::mpl::false_ const& ) {}

    template<class Sizes>
    void init( Sizes const& szs, boost::mpl::true_ const& )
    {
      sizes_type s(szs);
      typename facade_type::index_::type  b;
      boost::proto::value(*this).restructure(b,s);
    }

    void init( sizes_type const& szs, boost::mpl::true_ const& )
    {
      typename facade_type::index_::type  b;
      boost::proto::value(*this).restructure( b, szs );
    }
  };
} }

#endif
