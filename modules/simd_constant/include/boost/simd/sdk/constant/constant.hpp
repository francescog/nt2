/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_CONSTANT_CONSTANT_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONSTANT_CONSTANT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Main generic constant class
//* TODO:  Documentation: http://nt2.lri.fr/sdk/constant/entity/constant.html
////////////////////////////////////////////////////////////////////////////////
#include <boost/simd/sdk/functor/functor.hpp>
#include <boost/simd/sdk/meta/as.hpp>

////////////////////////////////////////////////////////////////////////////////
// Generate a constant function as Name<Type>()
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_CONSTANT_IMPLEMENTATION(TAG,NAME)                \
template<class Target> inline                                       \
typename boost::simd::meta::enable_call<TAG(nt2::meta::as_<Target>)>::type \
NAME()                                                              \
{                                                                   \
  typename boost::simd::make_functor<TAG, Target>::type callee;     \
  return callee( boost::simd::meta::as_<Target>() );                \
}                                                                   \
/**/

#endif
