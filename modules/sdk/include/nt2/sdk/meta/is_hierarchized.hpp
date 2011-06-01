/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_META_IS_HIERARCHIZED_HPP_INCLUDED
#define NT2_SDK_META_IS_HIERARCHIZED_HPP_INCLUDED

#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/meta/hierarchy_of.hpp>

namespace nt2 { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // Does T has a non-unspecified_ hierarchy type ?
  //////////////////////////////////////////////////////////////////////////////
  template<class T>
  struct  is_hierarchized
        : boost::mpl::
          not_< boost::is_same< typename meta::hierarchy_of<T>::type
                              , meta::unspecified_<T>
                              >
              >
  {};
} }

#endif

