/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_UNIT_MODULE_HPP_INCLUDED
#define BOOST_SIMD_SDK_UNIT_MODULE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Unit test framework
// Documentation: http://nt2.lri.fr/sdk/unit/module.html
////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <boost/preprocessor/cat.hpp>
#include <nt2/simd_sdk/unit/details/suite.hpp>
#include <nt2/simd_sdk/unit/details/stats.hpp>
#include <nt2/simd_sdk/details/preprocessor.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

////////////////////////////////////////////////////////////////////////////////
// Embedded main for testing purpose
////////////////////////////////////////////////////////////////////////////////
int main(int,char const**)
{
  boost::simd::details::main_suite.process();
  return boost::simd::details::error_count() ? -1: 0;
}

////////////////////////////////////////////////////////////////////////////////
// Macro for starting a test module
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_TEST_CASE(FUNC)                                            \
void BOOST_PP_CAT(test,FUNC)();                                               \
boost::simd::details::test const                                              \
BOOST_PP_CAT(FUNC,test) = { BOOST_PP_CAT(test,FUNC)                           \
                          , BOOST_PP_STRINGIZE(BOOST_PP_CAT(FUNC,_test))      \
                          , boost::simd::details                              \
                               ::main_suite.link(&BOOST_PP_CAT(FUNC,test)) }; \
void BOOST_PP_CAT(test,FUNC)()                                                \
/**/

////////////////////////////////////////////////////////////////////////////////
// Generate a test case using template type list
////////////////////////////////////////////////////////////////////////////////
#define BOOST_SIMD_PP_TPL_CASES(r,name,type)                                  \
printf("With T =[%s]\n",boost::simd::type_id<BOOST_SIMD_PP_STRIP(type)>().c_str());  \
BOOST_PP_CAT(tpl_test,name)<BOOST_SIMD_PP_STRIP(type)>();                     \
/**/

#define BOOST_SIMD_TEST_CASE_TPL(Name, Types)                                 \
template<class T> void BOOST_PP_CAT(tpl_test,Name)();                         \
void BOOST_PP_CAT(test,Name)();                                               \
boost::simd::details::test const                                              \
BOOST_PP_CAT(Name,test) = { BOOST_PP_CAT(test,Name)                           \
                          , BOOST_PP_STRINGIZE(BOOST_PP_CAT(Name,_test))      \
                          , boost::simd::details                              \
                               ::main_suite.link(&BOOST_PP_CAT(Name,test)) }; \
void BOOST_PP_CAT(test,Name)()                                                \
{                                                                             \
  BOOST_PP_SEQ_FOR_EACH(BOOST_SIMD_PP_TPL_CASES,Name,Types);                  \
}                                                                             \
template<class T> void BOOST_PP_CAT(tpl_test,Name)()                          \
/**/

#endif
