/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_UNIT_TESTS_RELATION_HPP_INCLUDED
#define BOOST_SIMD_SDK_UNIT_TESTS_RELATION_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Comparison tests
////////////////////////////////////////////////////////////////////////////////
#include <nt2/simd_sdk/unit/details/suite.hpp>
#include <nt2/simd_sdk/unit/details/test_func.hpp>

////////////////////////////////////////////////////////////////////////////////
// Predicate based tests
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_TEST_EQUAL(A,B)           \
  /*r1 =  A;  r2 =  B;*/            \
  ( ::boost::simd::details::test_eq(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) ) \
/**/

#define BOOST_SIMD_TEST_NOT_EQUAL(A,B)                                               \
( ::boost::simd::details::test_neq(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) ) \
/**/

#define BOOST_SIMD_TEST_LESSER(A,B)                                                  \
( ::boost::simd::details::test_lt(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) )  \
/**/

#define BOOST_SIMD_TEST_GREATER(A,B)                                                 \
( ::boost:simd::details::test_gt(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) )  \
/**/

#define BOOST_SIMD_TEST_LESSER_EQUAL(A,B)                                           \
( ::boost::simd::details::test_le(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) ) \
/**/

#define BOOST_SIMD_TEST_GREATER_EQUAL(A,B)                                           \
( ::boost::simd::details::test_ge(#A, #B , __LINE__, BOOST_CURRENT_FUNCTION, A, B) )  \
/**/

#endif
