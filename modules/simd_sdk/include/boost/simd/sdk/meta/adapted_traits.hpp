//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_META_ADAPTED_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_SDK_META_ADAPTED_TRAITS_HPP_INCLUDED

/*!
 * \file
 * \brief Provides adaptation of some boost type traits for BOOST_SIMD types
 */


/*!
 * \ingroup meta
 * \defgroup metafunctions Meta-Functions
 * This module gathers \metafunction required by \nt2 internal.
 */

#include <boost/simd/sdk/meta/strip.hpp>
#include <boost/simd/sdk/meta/behave_as.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_floating_point.hpp>


//==============================================================================
/*!
 * \namespace boost::meta
 * Namespace containing all BOOST_SIMD meta-functions and meta-function classes
 */
//==============================================================================
namespace boost { namespace simd { namespace meta
{
  //============================================================================
  /*!
   * \ingroup metafunctions
   * For any type \c T, checks if its primitive type is a floating-point type.
   *
   * \tparam T Any type
   *
   * \par Models:
   * \metafunction
   *
   * \par Semantic:
   * For any type \c T,
   *
   * \code
   * typedef is_floating<T>::type type;
   * \endcode
   *
   * is equivalent to
   *
   * \code
   * typedef behave_as<boost::is_floating_point<boost::mpl::_>
   *                  , strip<T>::type
   *                  > type;
   * \endcode
   */
  //============================================================================
  template<class T>
  struct  is_floating_point
        : behave_as  < boost::is_floating_point<boost::mpl::_>
                    , typename strip<T>::type
                    > {};

  //============================================================================
  /*!
   * \ingroup metafunctions
   * For any type \c T, checks if its primitive type is a integral type.
   *
   * \tparam T Any type
   *
   * \par Models:
   * \metafunction
   *
   * \par Semantic:
   * For any type \c T,
   *
   * \code
   * typedef is_integral<T>::type type;
   * \endcode
   *
   * is equivalent to
   *
   * \code
   * typedef behave_as<boost::is_integral<boost::mpl::_>
   *                  , strip<T>::type
   *                  > type;
   * \endcode
   */
  //============================================================================
  template<class T>
  struct  is_integral
        : behave_as< boost::is_integral<boost::mpl::_>
                    , typename strip<T>::type
                    > {};
} } }

#endif
