//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_SIZE_HPP_INCLUDED
#define NT2_CORE_SETTINGS_SIZE_HPP_INCLUDED

/*!
 * \file
 * Defines size related setting classes.
 */

#include <cstddef>
#include <boost/array.hpp>
#include <boost/mpl/vector_c.hpp>
#include <nt2/extension/parameters.hpp>
#include <nt2/sdk/details/preprocessor.hpp>
#include <nt2/core/settings/meta/option.hpp>

//==============================================================================
// Defines size options
//==============================================================================
namespace nt2 { namespace options
{
  struct size_ { typedef void nt2_is_option_type; };
} }

//==============================================================================
// Helper macro
//==============================================================================
#define M0(z,n,t)                                                 \
template< BOOST_PP_ENUM_PARAMS(n, std::ptrdiff_t D) >             \
struct  of_size_<BOOST_PP_ENUM_PARAMS(n,D)>                       \
{                                                                 \
  static const std::size_t dimensions = n;                        \
  typedef boost::mpl::true_    is_static;                         \
  typedef BOOST_PP_CAT(BOOST_PP_CAT(boost::mpl::vector,n),_c)     \
          <std::ptrdiff_t, BOOST_PP_ENUM_PARAMS(n,D)>             \
          type;                                                   \
};                                                                \
                                                                  \
template<> struct of_size_<NT2_PP_ENUM_VALUE(n,-1)>               \
{                                                                 \
  static const std::size_t      dimensions = n;                   \
  typedef boost::mpl::false_    is_static;                        \
  typedef BOOST_PP_CAT(BOOST_PP_CAT(boost::mpl::vector,n),_c)     \
      <std::ptrdiff_t, 0, BOOST_PP_ENUM_SHIFTED(n,NT2_PP_TEXT,1)> \
      type;                                                       \
};                                                                \
/**/

#if defined(DOXYGEN_ONLY)
namespace nt2
{
  //============================================================================
  /*!
   * banana
   */
  //============================================================================
  template< std::ptrdiff_t... Dimensions> struct  of_size_ {};
}
#endif
namespace nt2
{
  template< BOOST_PP_ENUM_BINARY_PARAMS ( NT2_MAX_DIMENSIONS
                                        , std::ptrdiff_t D
                                        , = -2 BOOST_PP_INTERCEPT
                                        )
          >
  struct  of_size_
  {
    static const std::size_t dimensions = NT2_MAX_DIMENSIONS;
    typedef boost::mpl::true_    is_static;
    typedef BOOST_PP_CAT(BOOST_PP_CAT(boost::mpl::vector,NT2_MAX_DIMENSIONS),_c)
            <std::ptrdiff_t, BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,D)>
            type;
  };

  template<>
  struct of_size_<NT2_PP_ENUM_VALUE(NT2_MAX_DIMENSIONS,-1)>
  {
    static const std::size_t  dimensions = NT2_MAX_DIMENSIONS;
    typedef boost::mpl::false_    is_static;
    typedef BOOST_PP_CAT(BOOST_PP_CAT(boost::mpl::vector,NT2_MAX_DIMENSIONS),_c)
        <std::ptrdiff_t,0,BOOST_PP_ENUM_SHIFTED(NT2_MAX_DIMENSIONS,NT2_PP_TEXT,1)>
        type;
  };

  template< std::ptrdiff_t D >
  struct  of_size_<D>
  {
    static const std::size_t dimensions = 1;
    typedef boost::mpl::true_    is_static;
    typedef boost::mpl::vector1_c<std::ptrdiff_t, D> type;
  };

  template<> struct of_size_<-1>
  {
    static const std::size_t  dimensions = 1;
    typedef boost::mpl::false_    is_static;
    typedef boost::mpl::vector1_c<std::ptrdiff_t, 0> type;
  };

  //////////////////////////////////////////////////////////////////////////////
  // Total specialization for 0D elements
  //////////////////////////////////////////////////////////////////////////////
  template<>
  struct  of_size_<NT2_PP_ENUM_VALUE(NT2_MAX_DIMENSIONS,-2)>
  {
    static const std::size_t                      dimensions = 0;
    typedef boost::mpl::true_    is_static;
    typedef boost::mpl::vector0_c<std::ptrdiff_t> type;
  };

  //////////////////////////////////////////////////////////////////////////////
  // Other dimensions of_size_
  //////////////////////////////////////////////////////////////////////////////
  BOOST_PP_REPEAT_FROM_TO(2,NT2_MAX_DIMENSIONS,M0,~)
}

////////////////////////////////////////////////////////////////////////////////
// Register of_size has a valid options::size_ type
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template< BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS, std::ptrdiff_t D)
          , class Default
          >
  struct option < of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,D)>
                , options::size_
                , Default
                , void
                >
  {
    typedef of_size_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,D)> type;
  };
} }

//==============================================================================
// Defines some usual short-cut for runtime of_size_
//==============================================================================
#define M1(z,n,t)                                                             \
typedef of_size_<NT2_PP_ENUM_VALUE(n,-1)> BOOST_PP_CAT(BOOST_PP_CAT(_,n),D);  \
/**/

#if defined(DOXYGEN_ONLY)
namespace nt2
{
  //============================================================================
  /*!
   * \typedef _0D
   * banana 1
   * \typedef _1D
   * banana 2
   * \typedef _2D
   * banana 3
   * \typedef _3D
   * banana 4
   * \typedef _4D
   * banana 5
   */
  //============================================================================
  typedef of_size_<>            _0D;
  typedef of_size_<-1>          _1D;
  typedef of_size_<-1,-1>       _2D;
  typedef of_size_<-1,-1,-1>    _3D;
  typedef of_size_<-1,-1,-1,-1> _4D;
}
#endif

namespace nt2
{
  BOOST_PP_REPEAT_FROM_TO(0,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M1,~)
}

////////////////////////////////////////////////////////////////////////////////
// Macro clean-up
////////////////////////////////////////////////////////////////////////////////
#undef M0
#undef M1

#endif
