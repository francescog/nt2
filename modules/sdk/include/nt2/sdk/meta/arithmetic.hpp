//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_META_ARITHMETIC_HPP_INCLUDED
#define NT2_SDK_META_ARITHMETIC_HPP_INCLUDED

/*!
 * \file
 * \brief Defines and implements the meta::arithmetic \metafunction
 */

#include <nt2/sdk/meta/strip.hpp>
#include <boost/typeof/typeof.hpp>

#if defined(NT2_DONT_USE_PREPROCESSED_FILES)
#include <nt2/extension/parameters.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#endif

namespace nt2  { namespace meta
{
  //============================================================================
  /*!
   * \ingroup metafunctions
   * For a list of types \c T0,...,Tn, ref arithmetic computes the type able to
   * store a value of type \c decltype(declval<T0>() + ... + declval<Tn>()).
   *
   * \semantic
   *
   * For types \c T0,...,Tn,
   *
   * \code
   * typedef result_of<arithmetic(T0,...,Tn)>::type type
   * \endcode
   *
   * is equivalent to:
   *
   * \code
   * typedef decltype(declval<T0>()+...+declval<Tn>()) type;
   * \endcode
   *
   * \par Example Usage:
   *
   * \include arithmetic.cpp
   */
  //============================================================================
  struct arithmetic
  {
    template<class Sig> struct result;

#if !defined(NT2_DONT_USE_PREPROCESSED_FILES)
#include <nt2/sdk/meta/preprocessed/arithmetic.hpp>
#else
#if defined(__WAVE__) && defined(NT2_CREATE_PREPROCESSED_FILES) && __INCLUDE_LEVEL__ == 0
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/arithmetic.hpp")
#undef BOOST_TYPEOF_NESTED_TYPEDEF_TPL
#endif

    #define M0(z,n,t) static typename meta::strip<BOOST_PP_CAT(A,n)>::type& \
                      BOOST_PP_CAT(a,n);
                      /**/

    #define M1(z,n,t)  + BOOST_PP_CAT(a,n)
    #define M2(z,n,t)                                                           \
    template<class This,BOOST_PP_ENUM_PARAMS(n,class A)>                        \
    struct  result<This(BOOST_PP_ENUM_PARAMS(n,A))>                             \
    {                                                                           \
      BOOST_PP_REPEAT(n,M0,~)                                                   \
      BOOST_TYPEOF_NESTED_TYPEDEF_TPL (  nested                                 \
                                      ,  a0 BOOST_PP_REPEAT_FROM_TO(1,n,M1,~))  \
       typedef typename nested::type   type;                                    \
     };                                                                         \
     /**/

    BOOST_PP_REPEAT_FROM_TO(2,NT2_MAX_ARITY,M2,~)
    
    #undef M2
    #undef M1
    #undef M0
    
#if defined(__WAVE__) && defined(NT2_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif
#endif

    //==========================================================================
    // Force integral promotion by computing arithmetic(A0,A0)
    //==========================================================================
    template<class This,class A0>
    struct result<This(A0)> : result<This(A0,A0)> {};
  };
} }

#endif
