#if !BOOST_PP_IS_ITERATING
//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

/*!
 * \file
 * \brief Define a macro-file to generate operator() overloads in Containers
 */

#include <nt2/extension/parameters.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

#define BOOST_PP_FILENAME_1 "nt2/core/container/details/access.hpp"
#define BOOST_PP_ITERATION_LIMITS (1, NT2_MAX_DIMENSIONS)
#include BOOST_PP_ITERATE()

#else

  #define N BOOST_PP_ITERATION()

  template<BOOST_PP_ENUM_PARAMS(N,typename I)> inline
  typename boost::
  lazy_disable_if < boost::fusion::traits::is_sequence<I0>
                  , meta::
                    call< tag::
                          value_at_ ( self_type&
                                    , BOOST_PP_ENUM_BINARY_PARAMS
                                      ( N, I, const& BOOST_PP_INTERCEPT )
                                    )
                        >
                  >::type
  operator()( BOOST_PP_ENUM_BINARY_PARAMS(N,I,const& i) )
  {
    nt2::functor<nt2::tag::value_at_> callee;
    return callee( *this, BOOST_PP_ENUM_PARAMS(N,i) );
  }

  template<BOOST_PP_ENUM_PARAMS(N,typename I)> inline
  typename boost::
  lazy_disable_if < boost::fusion::traits::is_sequence<I0>
                  , meta::
                    call< tag::
                          value_at_ ( self_type const&
                                    , BOOST_PP_ENUM_BINARY_PARAMS
                                      ( N, I, const& BOOST_PP_INTERCEPT )
                                    )
                        >
                  >::type
  operator()( BOOST_PP_ENUM_BINARY_PARAMS(N,I,const& i) ) const
  {
    nt2::functor<nt2::tag::value_at_> callee;
    return callee( *this, BOOST_PP_ENUM_PARAMS(N,i) );
  }
//  #endif

  #undef N

#endif
