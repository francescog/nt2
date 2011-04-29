/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_FACADE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_FACADE_HPP_INCLUDED

#include <nt2/core/container/forward.hpp>
#include <nt2/core/container/details/extent/domain.hpp>
#include <nt2/core/container/dsl/expression.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // extent facade
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class S> struct facade<tag::extent_,T,S>
  {
    // Extent are just wrapper around boost::array of proper size and type
    typedef boost::array<T,S::value>  data_type;

    // Here is the proto expressionr eady to be used
    typedef expression< typename boost::proto::nullary_expr < tag::extent_
                                                            , data_type
                                                            >::type
                      , tag::extent_
                      , boost::mpl::size_t<2>
                      >                                             type;
  };
} }

#endif
