//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_AST_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_VALUE_AT_AST_HPP_INCLUDED

#include <nt2/sdk/dsl/call.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is an ast and rest is w/e
/////////////////////////////////////////////////////////////////////////////
/*
#define M0(z,n,t) (BOOST_PP_CAT(A,n))
#define M1(z,n,t) (unspecified_<BOOST_PP_CAT(A,n)>)
#define M3(z,n,t)                                                       \
NT2_REGISTER_DISPATCH_TO( tag::value_at_, tag::cpu_                     \
                      , BOOST_PP_REPEAT(BOOST_PP_INC(n),M0,~)           \
                      , (tag::value_at_(tag::ast_,tag::unspecified_))   \
                      , (ast_<A0>)                                      \
                        BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(n),M1,~) \
                      )                                                 \
/**/
/*
BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M2,~)

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call < tag::value_at_(tag::ast_,tag::unspecified_)
              , tag::cpu_, Dummy
              > : callable
  {
    template<class Sig> struct result;

  #define M3(z,n,t) \
  template<class This,BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)>        \
  struct result<This(BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),A))>              \
  { typedef A0 type; };                                                     \
                                                                            \
  template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline A0&        \
  operator()( A0& a0                                                        \
            , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                  , const A                 \
                                                  , & BOOST_PP_INTERCEPT    \
                                                  )                         \
            ) const                                                         \
  {                                                                         \
    return a0;                                                              \
  }                                                                         \
                                                                            \
  template<BOOST_PP_ENUM_PARAMS(BOOST_PP_INC(n),class A)> inline A0 const&  \
  operator()( A0 const& a0                                                  \
            , BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS ( BOOST_PP_INC(n)         \
                                                  , const A                 \
                                                  , & BOOST_PP_INTERCEPT    \
                                                  )                         \
            ) const                                                         \
  {                                                                         \
    return a0;                                                              \
  }                                                                         \
  /**/
/*
  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M3,~)

  #undef M3
  #undef M2
  #undef M1
  #undef M0
  };
} }
*/
#endif
