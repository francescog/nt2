/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_ZERO_EXTENT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_ZERO_EXTENT_HPP_INCLUDED

#include <nt2/core/container/details/extent/facade.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // 0D specialization for extent
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class Dummy>
  struct  extent< 0, T, Dummy >
        : facade< tag::extent_,T,boost::mpl::size_t<0> >::type
  {
    ////////////////////////////////////////////////////////////////////////////
    // Facade predefined types
    ////////////////////////////////////////////////////////////////////////////
    typedef facade< tag::extent_,T,boost::mpl::size_t<0> >  facade_type;
    typedef typename facade_type::type                      parent;
    typedef typename facade_type::data_type                 data_type;

    BOOST_STATIC_CONSTANT(std::size_t, static_dimension = 0);

    ////////////////////////////////////////////////////////////////////////////
    // Interface types
    ////////////////////////////////////////////////////////////////////////////
    typedef std::size_t      value_type;
    typedef std::size_t const_reference;

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor leads to a [0 1 ... 1] extents
    ////////////////////////////////////////////////////////////////////////////
    extent() : parent() {}
    extent( extent<0,T> const& src ) : parent() {}

    ////////////////////////////////////////////////////////////////////////////
    // Assignment from non-AST
    ////////////////////////////////////////////////////////////////////////////
    extent& operator=(extent const& src ) { return *this; }

    using parent::operator=;

    ////////////////////////////////////////////////////////////////////////////
    // raw access to the underlying data array
    ////////////////////////////////////////////////////////////////////////////
    data_type const&  data()  const { return boost::proto::value(*this); }

    ////////////////////////////////////////////////////////////////////////////
    // Elementwise access
    ////////////////////////////////////////////////////////////////////////////
    const_reference operator()(std::size_t i) const { return 1; }

    ////////////////////////////////////////////////////////////////////////////
    // Container API
    ////////////////////////////////////////////////////////////////////////////
    typedef std::size_t     size_type;
    typedef size_type       base_type;
    typedef std::ptrdiff_t  difference_type;

    inline size_type  size()  const { return 1; }
    inline bool       empty() const { return false; }

    ////////////////////////////////////////////////////////////////////////////
    // Size and Bases related accessor
    ////////////////////////////////////////////////////////////////////////////
    inline size_type        numel()               const { return 1; }
    inline size_type        size(std::size_t i)   const { return 1; }
    inline base_type        lower(std::size_t i)  const { return 1; }
    inline difference_type  upper(std::size_t i)  const { return 1; }
    inline std::size_t      nDims()               const { return 0; }
  };
} }


#endif
