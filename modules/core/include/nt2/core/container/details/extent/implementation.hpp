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

#include <nt2/sdk/meta/assign.hpp>
#include <boost/fusion/include/is_sequence.hpp>
#include <nt2/core/container/details/access.hpp>
#include <nt2/core/container/details/extent/facade.hpp>
#include <nt2/core/container/details/extent/evaluation.hpp>

namespace nt2 { namespace containers
{
  //=============================================================================
  /*!
   * \ingroup containershelper
   *
   * \ref extent is a \container representing the dimension set of another
   * container. It acts as a \container of integers where the ith value is the
   * number of element stored by a container along its ith dimensions.
   *
   * \tparam Dimensions Type representing the kind of \ref extent defined.
   * \ref extent can be defined using:
   *  - \ref _2D, ..., \ref _4D to define a dynamic \ref extent where values
   *  can be modified.
   *  - \ref of_size_ to define a static \ref extent where values are specified
   *  as compile time integral constants.
   *
   * \par Rationale:
   *
   * In \matlab, size of a container is itself a \matlab container. Due to the
   * lack of notion of constructors for matrix in \matlab, no ambiguity arises
   * from this fact. In \nt2 however, if we want to have both containers being
   * constructed from a size (or \ref extent) or another \container, we need to
   * have a dedicated type to represent size of a \container.
   * \ref extent represents such a type and is designed to fulfill \container
   * concept requirement and be discriminated in other \container constructors
   * call.
   *
   * \par Models:
   *
   * \container
   *
   * \see
   *
   * of_size_
   */
  //============================================================================
  template<class Dimensions>
  struct  extent : ext::facade<tag::extent_,Dimensions,void>::type
  {
    typedef ext::facade<tag::extent_,Dimensions,void> facade_type;
    typedef typename facade_type::type                parent;
    typedef typename facade_type::data_type           data_type;
    typedef tag::extent_                              fusion_tag;

    //==========================================================================
    // Container interface
    //==========================================================================
    typedef typename data_type::value_type      value_type;
    typedef typename data_type::reference       reference;
    typedef typename data_type::const_reference const_reference;
    typedef typename data_type::size_type       size_type;
    typedef size_type                           base_type;
    typedef typename data_type::difference_type difference_type;
    typedef typename data_type::iterator        iterator;
    typedef typename data_type::const_iterator  const_iterator;

    //==========================================================================
    /*!
     * \ref extent default constructor build an \ref extent which is :
     *  - filled with the static size it represents if it has been instanciated
     *  from an static size descriptor (see \ref of_size_).
     *  - a representation of an empty \ref extent, ie an \ref extent where
     *  all dimensions are equal to one, except for the first one which is equal
     *  to zero.
     *
     *  \usage
     *
     *  \code
     *  #include <nt2/core/container/extent.hpp>
     *
     *  int main()
     *  {
     *    nt2::container::extent<nt2::_2D> x;
     *    assert( x(1) == 0 && x(2) == 1 );
     *
     *    nt2::container::extent<nt2::of_size_<3,4,5> > y;
     *    assert( y(1) == 3 && y(2) == 4 && y(2) == 4 );
     *  }
     *  \endcode
     */
    //==========================================================================
    inline extent() : parent()
    {
      meta::assign(boost::proto::value(*this), typename Dimensions::type());
    }

    //==========================================================================
    /*!
     * \ref extent copy constructor. If the \ref extent being constructed is a
     * static \ref extent, a static assert is triggered.
     *
     * \param src  \ref extent to be copied
     *
     * \usage
     *
     * \code
     * #include <nt2/core/container/extent.hpp>
     *
     * int main()
     * {
     *   nt2::container::extent<nt2::_2D> x(3,7);
     *   nt2::container::extent<nt2::_2D> y(x);
     *   assert( y(1) == 3 && y(2) == 7 );
     *  }
     *  \endcode
     */
    //==========================================================================
    inline extent( extent const& src ) : parent()
    {
      boost::proto::value(*this) = src.data();
    }

    //==========================================================================
    /*!
     * \ref extent constructor from a different \ref extent type performs the
     * copy of the smallest common value range and, if needed, fill the remaining
     * with 1. If one attempts to construct and \ref extent from an \ref extent
     * with more dimension or if If the \ref extent being constructed is a
     * static \ref extent, a static assert is triggered.
     *
     * \param src  \ref extent to copy
     *
     * \usage
     *
     * \code
     * #include <nt2/core/container/extent.hpp>
     *
     * int main()
     * {
     *   nt2::container::extent<nt2::_2D> x(3,7);
     *   nt2::container::extent<nt2::_3D> y(x);
     *   assert( y(1) == 3 && y(2) == 7 && y(3) == 1 );
     *  }
     *  \endcode
     */
    //==========================================================================
    template<class D> inline extent( extent<D> const& src ) : parent()
    {
      BOOST_STATIC_CONSTANT(std::size_t, sdims = extent<D>::static_dimensions );

      NT2_STATIC_ASSERT
      (
        ((sdims <= parent::static_dimensions))
        , EXTENT_COPY_SIZE_MISMATCH
        , "You attempted to construct an extent from an extent of a larger size. "
          "Check the correctness of your code or use compress function before "
          "performing this copy."
       );

      NT2_STATIC_ASSERT
      (
        (!Dimensions::is_static::value)
        , INVALID_STATIC_EXTENT_COPY
        , "Constructor of static extent from non-static extent is disabled."
      );

      for(std::size_t i = 0; i < sdims; ++i )
      boost::proto::value(*this)[i] = src(i);

      for(std::size_t i = sdims; i < parent::static_dimensions; ++i )
      boost::proto::value(*this)[i] = 1;
    }

#if defined(DOXYGEN_ONLY)
    //==========================================================================
    /*!
     * \ref extent constructor from a list of integral values initializes its
     * nth first elements and fill the remaining ones with 1.
     *
     * \param values List of integral values to use for initialization
     *
     * \usage
     *
     * \code
     * #include <nt2/core/container/extent.hpp>
     *
     * int main()
     * {
     *   nt2::container::extent<nt2::_3D> x(3,7,5);
     *   assert( y(1) == 3 && y(2) == 7 && y(3) == 5 );
     *  }
     *  \endcode
     */
    //==========================================================================
    template<class ...U> inline explicit extent( U... const& values );
#endif

#define M1(z,n,t) boost::proto::value(*this)[n]= BOOST_PP_CAT(d,n); \
/**/

#define M0(z,n,t)                                                             \
template<BOOST_PP_ENUM_PARAMS(n,class U)> inline explicit                     \
extent( BOOST_PP_ENUM_BINARY_PARAMS(n,const U, & d)                           \
, typename boost::enable_if_c<boost::is_integral<U0>::value>::type* = 0 \
) : parent()                                                            \
{                                                                             \
boost::proto::value(*this).fill(1);                                         \
BOOST_PP_REPEAT(n,M1,~)                                                     \
}                                                                             \
/**/

      BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

#undef M0
#undef M1

    //==========================================================================
    // Constructor from a expression of extent
    /*!
     * \ref extent constructor from an \ref extent expression evaluates an
     * expression containing extents into the object being built.
     *
     * \param src  \ref extent expression to evaluates
     *
     * \usage
     *
     * \code
     * #include <nt2/core/container/extent.hpp>
     *
     * int main()
     * {
     *   nt2::container::extent<nt2::_2D> x(3,7);
     *   nt2::container::extent<nt2::_2D> y(1+x*2);
     *   assert( y(1) == 7 && y(2) == 15 );
     *  }
     *  \endcode
     */
    //==========================================================================
    template<class XPR, class D> inline
    explicit extent( container<XPR, tag::extent_,D> const& src )
    {
      nt2::evaluate(*this, src);
    }

    //==========================================================================
    // This overload is there to catch invalid expression of extent_ that fell
    // into the table domain and prevent their evaluation into a extent_;
    //==========================================================================
    template<class X> inline
    explicit extent( container<X, tag::table_,boost::mpl::size_t<2> > const& )
    {
      NT2_STATIC_ASSERT
      (
       (sizeof(X) == 0)
       , NT2_SIZE_MISMATCH_IN_EXTENT_CONSTRUCTION
       , "Invalid expression of extent is being constructed"
       );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Assignment operator
    ////////////////////////////////////////////////////////////////////////////
    extent& operator=(extent const& src )
    {
      boost::proto::value(*this) = boost::proto::value(src);
      return *this;
    }

    //==========================================================================
    // Assignment from a expression
    //==========================================================================
    template<class XPR, class D> inline
    extent& operator=( container<XPR, tag::extent_,D> const& src )
    {
      nt2::evaluate(*this, src);
      return *this;
    }

    //==========================================================================
    /*!
     * Returns a constant reference to the underlying Fusion Sequence containing the
     * \ref extent values.
     */
    //==========================================================================
    data_type const&  data()  const { return boost::proto::value(*this); }
    data_type&        data()        { return boost::proto::value(*this); }

    //==========================================================================
    /*!
     * Non-constant elementwise access to \ref extent value. For any index i
     * which values is greater or equal than \ref lower(1) and lesser or equal
     * to \ref upper(1), returns a non-constant reference to the ith element of
     * the \ref extent. This access is disabled for static \ref extent.
     *
     * \param i Index of the value to access
     */
    //==========================================================================
    #define NT2_ACCESS_NON_CONST
    //#include <nt2/core/container/details/access.hpp>
/*
    template<class Position> inline
    typename boost::enable_if_c
    <     ( !Dimensions::is_static::value )
      &&  ( boost::fusion::traits::is_sequence<Position>::value )
    , reference
    >::type
    operator()(Position const& p)
    {
      return boost::proto::value(*this)[boost::fusion::front(p)-1];
    }
*/
    //==========================================================================
    /*!
     * Constant elementwise access to \ref extent value. For any index i
     * which values is greater or equal than \ref lower(1) and lesser or equal
     * to \ref upper(1), returns a constant reference to the ith element of
     * the \ref extent.
     *
     * \param i Index of the value to access
     */
    //==========================================================================
    const_reference operator()(difference_type i) const
    {
      return boost::proto::value(*this)[i-1];
    }

    reference operator()(difference_type i)
    {
      return boost::proto::value(*this)[i-1];
    }

    //==========================================================================
    /*!
     * Return an iterator pointing to the first element stored in current
     * \ref extent
     */
    //==========================================================================
    inline iterator begin() { return boost::proto::value(*this).begin();  }

    //==========================================================================
    /*!
     * Return a constant iterator pointing to the first element stored in current
     * \ref extent.
     */
    //==========================================================================
    inline const_iterator begin() const { return boost::proto::value(*this).begin(); }

    //==========================================================================
    /*!
     * Return an iterator pointing after the last element stored in current
     * \ref extent.
     */
    //==========================================================================
    inline iterator end() { return boost::proto::value(*this).end(); }

    //==========================================================================
    /*!
     * Return a constant iterator pointing after the last element stored in
     * current \ref extent.
     */
    //==========================================================================
    inline const_iterator end() const { return boost::proto::value(*this).end(); }

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
      return (i<=1) ? parent::static_dimensions : 1;
    }

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
    inline difference_type  upper(std::size_t i)  const
    {
      return (i==1) ? parent::static_dimensions : 1;
    }

    //==========================================================================
    // to be moved to a free function
    //==========================================================================
    inline std::size_t nDims() const
    {
      std::size_t i = parent::static_dimensions-1;
      while(boost::proto::value(*this)[--i] == 1);
      return i<0 ? i+1 : parent::static_dimensions;
    }
  };
} }

#endif
