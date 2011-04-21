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
#include <nt2/core/container/dsl.hpp>
#include <nt2/core/settings/size.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/padding.hpp>
#include <nt2/core/settings/allocator.hpp>
#include <nt2/core/settings/storage_kind.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/container/details/block.hpp>
#include <nt2/core/container/details/table/domain.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // table facade
  //////////////////////////////////////////////////////////////////////////////
  template<class T, class S> struct facade<tag::table_,T,S>
  {
    // Extract the important info from the Settings
    typedef meta::option<S,options::size_         , _4D>                size_;
    typedef meta::option<S,options::index_        , matlab_index_>      index_;
    typedef meta::option<S,options::storage_kind_ , heap_>              kind_;
    typedef meta::option<S,options::allocator_    , default_allocator_> alloc_;
    typedef meta::option<S,options::padding_      , lead_padding_>      padding_;
    typedef meta::option<S,options::id_           , unnamed_ >          id_;
    typedef meta::option<S,options::storage_order_, monotonic_order_>   sto_;

    // Builds the proper blocks
    typedef block < T
                  , typename size_::type::dimensions_type
                  , typename index_::type::type
                  , typename size_::type::type
                  , typename sto_::type::type
                  , typename kind_::type::type( typename alloc_::type::type::
                                                template rebind<T>::other
                                              )
                  , typename padding_::type::type
                  >                                                 data_type;

    // Here is the proto expressionr eady to be used
    typedef expression< typename boost::proto::nullary_expr < tag::table_
                                                            , data_type
                                                            >::type

                      , tag::table_
                      , typename size_::type::dimensions_type
                      >                                             type;
  };
} }

#endif
