//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_IMPLEMENTATION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_IMPLEMENTATION_HPP_INCLUDED

/*!
 * \file
 * Implements the extent class
 */

#include <boost/array.hpp>
#include <nt2/sdk/meta/assign.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/include/is_sequence.hpp>
#include <nt2/core/container/details/access.hpp>
#include <nt2/core/container/details/extent/facade.hpp>

//=============================================================================
/*!
 * \namespace nt2::container
 * Namespace holding all NT2 container and container related classes
 */
//=============================================================================
namespace nt2 { namespace container
{
  //=============================================================================
  /*!
   * \ref extent is a container reprenting the dimension set of another container.
   * It acts as a Collection of integers where the ith value is the number of
   * element stored by a container along its ith dimensions.
   *
   * \par Models:
   *   \ref Container
   */
  //=============================================================================
  template<class Dimensions>
  struct  extent : facade<tag::extent_,Dimensions,void>::type
  {
    typedef facade<tag::extent_,Dimensions,void>  facade_type;
    typedef typename facade_type::type            parent;
    typedef typename facade_type::data_type       data_type;

    //==========================================================================
    /*!
     * Static value containing the number of dimension stored by the \ref extent
     */
    //==========================================================================
    static const std::size_t static_dimension = Dimensions::dimensions;


    //==========================================================================
    /*!
     * \typedef value_type
     * Type used to represent a value in \ref extent.
     *
     * \typedef reference
     * Type used to represent a reference to a value in \ref extent.
     *
     * \typedef const_reference
     * Type used to represent a reference to a constant value in \ref extent.
     */
    //==========================================================================
    typedef typename data_type::value_type      value_type;
    typedef typename data_type::reference       reference;
    typedef typename data_type::const_reference const_reference;

    //==========================================================================
    /*!
     * \ref extent default constructor build an \ref extent which is :
     *  - filled with the static size it represents if it has been instanciated
     *  from an static size descriptor (see \ref of_size_).
     *  - a representation of an empty \ref extent, ie an \ref extent where
     *  all dimensions are equal to one, except for the first one which is equal
     *  to zero.
     */
    //==========================================================================
    extent() : parent()
    {
      meta::assign(data(), typename Dimensions::type());
    }

    //==========================================================================
    /*!
     * \ref extent copy constructor
     * \param src  \ref extent to be copied
     */
    //==========================================================================
    extent( extent const& src ) : parent() { data() = src.data(); }

    //==========================================================================
    /*!
     * \ref extent constructor from a different \ref extent type performs the
     * copy of the smallest common value range and, if needed, fill the remaining
     * with 1. If one attempts to construct and \ref extent from an \ref extent
     * with more dimension, a static assert is raised.
     *
     * \param src  \ref extent to copy
     *
     * \par Semantic:
     *
     * \par Example Usage:
     *
     */
    //==========================================================================
    template<class D> extent( extent<D> const& src ) : parent()
    {
      NT2_STATIC_ASSERT
      (
        ((extent<D>::static_dimension <= static_dimension))
      , EXTENT_COPY_SIZE_MISMATCH
      , "You attempted to construct an extent from an extent of a larger size. "
        "Check the correctness of your code or use compress function before "
        "performing this copy."
      );

      for(std::size_t i = 0; i < extent<D>::static_dimension; ++i )
        data()[i] = src.data()[i];

      for(std::size_t i = extent<D>::static_dimension; i < static_dimension; ++i )
        data()[i] = 1;
    }

    //==========================================================================
    /*!
     * \ref extent constructor from a boost::array performs the copy of the
     * smallest common value range and, if needed, fill the remaining with 1.
     * If one attempts to construct and \ref extent from a larger boost::array
     * , a static assert is raised.
     *
     * \param src  boost::array to copy
     *
     * \par Semantic:
     *
     * \par Example Usage:
     *
     */
    //==========================================================================
    template<std::size_t M, class U>
    extent( boost::array<U,M> const& src ) : parent()
    {
      NT2_STATIC_ASSERT
      (
        ((M <= static_dimension))
      , EXTENT_COPY_SIZE_MISMATCH
      , "You attempted to construct an extent from an array of a larger size. "
        "Check the correctness of your code or use compress function before "
        "performing this copy."
      );

      for(std::size_t i = 0; i < M; ++i )                 data()[i] = src[i];
      for(std::size_t i = M; i < static_dimension; ++i )  data()[i] = 1;
    }

    //==========================================================================
    // Constructor from 1...N Dimensions
    //==========================================================================
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

    #if defined(DOXYGEN_ONLY)
    //==========================================================================
    /*!
     * banana
     */
    //==========================================================================
    template<class U> inline explicit
    extent( U const& d0, ..., U const& dn );
    #endif

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
      return i<0 ? i+1 : static_dimension;
    }
  };
} }

#endif
