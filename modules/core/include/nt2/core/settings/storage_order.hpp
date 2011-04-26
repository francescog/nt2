/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_SETTINGS_STORAGE_ORDER_HPP_INCLUDED
#define NT2_CORE_SETTINGS_STORAGE_ORDER_HPP_INCLUDED

#include <cstddef>
#include <boost/mpl/vector_c.hpp>
#include <nt2/extension/parameters.hpp>
#include <nt2/sdk/details/preprocessor.hpp>
#include <nt2/core/settings/meta/option.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

////////////////////////////////////////////////////////////////////////////////
// Defines storage order options
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace options
{
  struct storage_order_ { typedef void nt2_is_option_type; };
} }

////////////////////////////////////////////////////////////////////////////////
// Helper macros
////////////////////////////////////////////////////////////////////////////////
#define M0(z,n,t) std::size_t BOOST_PP_CAT(I,n) = -1

////////////////////////////////////////////////////////////////////////////////
// storage_order<I0,..,In> represents a storage dimension permutation. As this
// permutation is dependant on the dimension of the underlying container, this
// struct is in fact a meta-function class that takes the dimension as parameter
// and return the proper static sequence of indexes.
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  template< BOOST_PP_ENUM(NT2_MAX_DIMENSIONS,M0,~) >
  struct  storage_order_
  {
    template<class Dim, class Dummy=void> struct apply;

    #define M1(z,n,t)                                                   \
    template<class Dummy> struct apply< boost::mpl::size_t<n>, Dummy >  \
    {                                                                   \
      typedef BOOST_PP_CAT(BOOST_PP_CAT(boost::mpl::vector,n),_c)       \
              < std::size_t                                             \
              , BOOST_PP_ENUM_BINARY_PARAMS(n,I,-1 BOOST_PP_INTERCEPT)  \
              > type;                                                   \
    };                                                                  \
    /**/

    BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M1,~)

    #undef M0
    #undef M1
  };
}

////////////////////////////////////////////////////////////////////////////////
// Register storage_order_ has a valid options::storage_order_ type
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace meta
{
  template< BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,std::ptrdiff_t I)
          , class Default
          >
  struct option < storage_order_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,I)>
                , options::storage_order_
                , Default
                , void
                >
  {
    typedef storage_order_<BOOST_PP_ENUM_PARAMS(NT2_MAX_DIMENSIONS,I)> type;
  };
} }

////////////////////////////////////////////////////////////////////////////////
// Defines some usual short-cut for row and column major storage order
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  typedef storage_order_<NT2_PP_IOTA(1,NT2_MAX_DIMENSIONS)>         column_major_;
  typedef storage_order_<NT2_PP_REVERSE_IOTA(1,NT2_MAX_DIMENSIONS)> row_major_;
}

#endif
