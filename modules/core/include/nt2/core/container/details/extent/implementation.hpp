/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_IMPLEMENTATION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_IMPLEMENTATION_HPP_INCLUDED

#include <boost/array.hpp>
#include <nt2/sdk/meta/assign.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/include/is_sequence.hpp>
#include <nt2/core/container/details/access.hpp>
#include <nt2/core/container/details/extent/facade.hpp>

namespace nt2 { namespace container
{
  template<class Dimensions, class Dummy>
  struct  extent
        : facade<tag::extent_,Dimensions,void>::type
  {
    ////////////////////////////////////////////////////////////////////////////
    // Facade predefined types
    ////////////////////////////////////////////////////////////////////////////
    typedef facade<tag::extent_,Dimensions,void>  facade_type;
    typedef typename facade_type::type            parent;
    typedef typename facade_type::data_type       data_type;

    BOOST_STATIC_CONSTANT(std::size_t, static_dimension = Dimensions::dimensions);

    ////////////////////////////////////////////////////////////////////////////
    // Interface types
    ////////////////////////////////////////////////////////////////////////////
    typedef typename data_type::value_type      value_type;
    typedef typename data_type::reference       reference;
    typedef typename data_type::const_reference const_reference;

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor leads to a [0 1 ... 1] extents
    ////////////////////////////////////////////////////////////////////////////
    extent() : parent()
    {
      meta::assign(data(), typename Dimensions::type());
    }

    template<class D>
    extent( extent<D> const& src ) : parent()
    {
      BOOST_STATIC_CONSTANT(std::size_t, lims = extent<D>::dimensions);
      for(std::size_t i = 0; i < lims; ++i )
        data()[i] = src.data()[i];
      for(std::size_t i = lims; i < static_dimension; ++i )
        data()[i] = 1;
    }

    template<std::size_t M, class U>
    extent( boost::array<U,M> const& src ) : parent()
    {
      for(std::size_t i = 0; i < M; ++i )                 data()[i] = src[i];
      for(std::size_t i = M; i < static_dimension; ++i )  data()[i] = 1;
    }

    extent( extent const& src ) : parent() { data() = src.data(); }

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from 1...N Dimensions
    ////////////////////////////////////////////////////////////////////////////
    #define M1(z,n,t) boost::proto::value(*this)[n]= BOOST_PP_CAT(d,n); \
    /**/

    #define M0(z,n,t)                                                             \
    template<class U> inline explicit                                             \
    extent( BOOST_PP_ENUM_PARAMS(n,U d)                                           \
          , typename boost::enable_if_c<boost::is_integral<U>::value>::type* = 0  \
          ) : parent()                                                            \
    {                                                                             \
      boost::proto::value(*this).fill(1);                                         \
      BOOST_PP_REPEAT(n,M1,~)                                                     \
    }                                                                             \
    /**/

    BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

    #undef M0
    #undef M1

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from a fusion sequence of size <= D
    ////////////////////////////////////////////////////////////////////////////
    template<class Seq> explicit
    extent( Seq const& s
          , typename boost::enable_if_c < boost::fusion::
                                          traits::is_sequence<Seq>::value
                                        >::type* = 0
          ) : parent()
    {
      boost::proto::value(*this).fill(1);
      meta::assign(boost::proto::value(*this), s);
    }

    ////////////////////////////////////////////////////////////////////////////
    // Copy constructor
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Assignment from non-AST
    ////////////////////////////////////////////////////////////////////////////
    extent& operator=(extent const& src )
    {
      boost::proto::value(*this) = boost::proto::value(src);
      return *this;
    }

    using parent::operator=;

    ////////////////////////////////////////////////////////////////////////////
    // raw access to the underlying data array
    ////////////////////////////////////////////////////////////////////////////
    data_type&        data()        { return boost::proto::value(*this); }
    data_type const&  data()  const { return boost::proto::value(*this); }

    ////////////////////////////////////////////////////////////////////////////
    // Elementwise access
    ////////////////////////////////////////////////////////////////////////////
    reference operator()(std::size_t i)
    {
      NT2_ASSERT_ACCESS(1, i );
      return boost::proto::value(*this)[i-1];
    }

    const_reference operator()(std::size_t i) const
    {
      NT2_ASSERT_ACCESS(1, i );
      return boost::proto::value(*this)[i-1];
    }

    ////////////////////////////////////////////////////////////////////////////
    // Container API
    ////////////////////////////////////////////////////////////////////////////
    typedef typename data_type::size_type       size_type;
    typedef size_type                           base_type;
    typedef typename data_type::difference_type difference_type;
    typedef typename data_type::iterator        iterator;
    typedef typename data_type::const_iterator  const_iterator;

    inline size_type size()  const
    {
      return boost::proto::value(*this).size();
    }

    inline bool empty() const { return boost::proto::value(*this).empty(); }

    iterator        begin()       { return boost::proto::value(*this).begin();  }
    const_iterator  begin() const { return boost::proto::value(*this).begin();  }

    iterator        end()         { return boost::proto::value(*this).end();    }
    const_iterator  end()   const { return boost::proto::value(*this).end();    }

    ////////////////////////////////////////////////////////////////////////////
    // Size and Bases related accessor
    ////////////////////////////////////////////////////////////////////////////
    inline size_type  size(std::size_t i) const
    {
      return (i<=1) ? static_dimension : 1;
    }

    inline base_type lower(std::size_t i)  const { return 1; }

    inline difference_type  upper(std::size_t i)  const
    {
      return (i==1) ? static_dimension : 1;
    }

    inline std::size_t nDims() const
    {
      std::size_t i = static_dimension-1;
      while(data()[--i] == 1);
      return i ? i+1 : static_dimension;
    }
  };
} }

#endif
