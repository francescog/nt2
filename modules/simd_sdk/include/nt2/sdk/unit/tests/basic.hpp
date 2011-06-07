/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_UNIT_TESTS_BASIC_HPP_INCLUDED
#define NT2_SDK_UNIT_TESTS_BASIC_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Basic tests
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/unit/details/stats.hpp>

////////////////////////////////////////////////////////////////////////////////
// Evaluates an expression and checks if it evaluates to true or not
////////////////////////////////////////////////////////////////////////////////
#define NT2_TEST(X)                                                         \
( ::boost::simd::details::test_count()++                                    \
, (X) ? ::boost::simd::details::pass(#X)                                    \
      : ::boost::simd::details::fail(#X, __LINE__, BOOST_CURRENT_FUNCTION)  \
)                                                                           \
/**/

////////////////////////////////////////////////////////////////////////////////
// Emit a strong error message
////////////////////////////////////////////////////////////////////////////////
#define NT2_TEST_ERROR(X)                                           \
::boost::simd::details::error(X, __LINE__, BOOST_CURRENT_FUNCTION)  \
/**/

#endif
