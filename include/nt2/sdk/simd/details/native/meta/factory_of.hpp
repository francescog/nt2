/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_DETAILS_NATIVE_META_FACTORY_OF_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_NATIVE_META_FACTORY_OF_HPP_INCLUDED

#include <boost/mpl/placeholders.hpp>
#include <nt2/sdk/meta/factory_of.hpp>

namespace nt2 { namespace meta
{
  template<class Type,class Extension>
  struct factory_of< simd::native<Type,Extension> >
  {
    typedef simd::native<boost::mpl::_,Extension> type;
  };
} }

#endif
