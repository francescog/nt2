/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_FACADE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_FACADE_HPP_INCLUDED

#include <nt2/core/settings/id.hpp>
#include <nt2/core/settings/size.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/container/extent.hpp>
#include <nt2/core/settings/padding.hpp>
#include <nt2/core/settings/allocator.hpp>
#include <nt2/core/settings/storage_kind.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/container/details/block.hpp>
#include <nt2/core/container/details/table/domain.hpp>
#include <nt2/core/container/dsl/expression.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // table facade
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class S> struct facade<tag::table_,T,S>
  {
    ////////////////////////////////////////////////////////////////////////////
    // Find out Size informations
    ////////////////////////////////////////////////////////////////////////////
    typedef typename meta::option<S,options::size_, _4D>::type  size_;
    typedef extent<size_>                                       extent_type;

    typedef boost::mpl::size_t<extent_type::static_dimension> dimensions_type;

    ////////////////////////////////////////////////////////////////////////////
    // Find out Storage Order informations
    ////////////////////////////////////////////////////////////////////////////
    typedef typename
    meta::option<S,options::storage_order_,column_major_>::type     storage_;
    typedef typename
    boost::mpl::apply<storage_,dimensions_type>::type               order_type;

    ////////////////////////////////////////////////////////////////////////////
    // Find out Memory Allocation informations
    ////////////////////////////////////////////////////////////////////////////
    typedef typename
    meta::option<S,options::allocator_, default_allocator_>::type   alloc_;
    typedef typename
    meta::option<S,options::storage_kind_ , heap_>::type            kind_;
    typedef typename kind_::type (storage_kind_type)( typename alloc_::type );

    typedef typename meta::option<S,options::index_ , matlab_index_>::type      index_;
    typedef meta::option<S,options::padding_      , lead_padding_>      padding_;
//    typedef meta::option<S,options::id_           , unnamed_ >          id_;

    // Builds the proper blocks
    typedef block < T
                  , extent_type
                  , order_type
                  , storage_kind_type
                  , typename padding_::type::type
                  >                                                 data_type;

    // Here is the proto expression ready to be used
    typedef expression< typename boost::proto::nullary_expr < tag::table_
                                                            , data_type
                                                            >::type

                      , tag::table_
                      , dimensions_type
                      >                                             type;
  };
} }

#endif
