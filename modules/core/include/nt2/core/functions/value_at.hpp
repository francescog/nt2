//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_VALUE_AT_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_VALUE_AT_HPP_INCLUDED

#include <nt2/include/functor.hpp>
#include <boost/preprocessor/repetition/enum_shifted_binary_params.hpp>

#define M0(z,n,t)                                                             \
NT2_FUNCTION_IMPLEMENTATION(tag::value_at_, value_at, BOOST_PP_INC(n))        \
                                                                              \
template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline                \
typename nt2::meta::                                                          \
              enable_call<tag::value_at_( A0&                                 \
                                        , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS \
                                          ( BOOST_PP_INC(n)                   \
                                          , A                                 \
                                          , const & BOOST_PP_INTERCEPT        \
                                          )                                   \
                                        )>::type                              \
value_at( A0& a0                                                              \
        , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(BOOST_PP_INC(n),const A,& a))   \
{                                                                             \
  NT2_FUNCTION_BODY(tag::value_at_,BOOST_PP_INC(n))                           \
}                                                                             \
/**/

namespace nt2
{
  namespace tag { struct value_at_ {}; }

  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)
}

#undef M0

#include <nt2/core/functions/impl/value_at.hpp>

#endif

