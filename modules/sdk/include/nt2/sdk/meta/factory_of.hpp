//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_FACTORY_OF_HPP_INCLUDED
#define NT2_SDK_META_FACTORY_OF_HPP_INCLUDED

/*!
 * \file
 * \brief Defines and implements the nt2::meta::factory_of meta-functions
 */

#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/meta/hierarchy_of.hpp>
#include <nt2/sdk/meta/is_unspecified.hpp>
#include <nt2/sdk/error/static_assert.hpp>

namespace nt2 { namespace meta
{
  //============================================================================
  /*!
   * \ingroup metafunctions
   * For any Hierarchizable type, returns a \metalambda which permits the lazy
   * recomposition of any type of the same hierarchy from a set of types.
   *
   * \tparam Hierarchizable type to deconstruct
   *
   * \semantic
   *
   * For any Hierarchizable \c H,
   * \code
   *  typedef nt2::meta::factory_of<T>::type l;
   * \endcode
   *
   * return a \metalambda so that, for any types \c Tn...
   *
   * \code
   *  typedef boost::mpl::apply<l, Tn...>::type r;
   * \endcode
   *
   * returns a type \c r which is a Hierarchizable of the same hierarchy than
   * \c H and an equivalent semantic.
   *
   * \usage
   *
   * \include factory_of.cpp
   */
  //============================================================================
  template<class Hierarchizable> struct factory_of
  {
    NT2_STATIC_ASSERT ( ( !is_unspecified< Hierarchizable >::value )
                      , NT2_UNDEFINED_PRIMITIVE_TYPE
                      , "Factory of a non Hierarchizable type is undefined."
                      );
    typedef boost::mpl::_ type;
  };
} }

#endif
