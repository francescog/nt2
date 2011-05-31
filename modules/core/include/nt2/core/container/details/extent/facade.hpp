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

#include <cstddef>
#include <boost/array.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <nt2/core/container/dsl/container.hpp>
#include <nt2/core/container/details/extent/domain.hpp>

namespace nt2 { namespace containers
{
  //////////////////////////////////////////////////////////////////////////////
  // extent facade
  //////////////////////////////////////////////////////////////////////////////
  template<class Dimensions,class S>
  struct facade<tag::extent_,Dimensions, S>
  {
    typedef boost::array<std::size_t,Dimensions::dimensions>  data_type;
    typedef container < typename boost::proto::nullary_expr < tag::extent_
                                                            , data_type
                                                            >::type
                      , tag::extent_
                      , boost::mpl::size_t<2>
                      >                                       type;
  };
} }

#endif
