/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_BLOCK_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_BLOCK_HPP_INCLUDED

#include <nt2/core/container/details/block_data.hpp>
#include <nt2/core/container/details/block_access.hpp>

namespace nt2 { namespace container
{
  //////////////////////////////////////////////////////////////////////////////
  // Defines a block of memory to be used stored on the CPU heap
  //////////////////////////////////////////////////////////////////////////////
  template< class Type, class Extend
          , class Bases, class Sizes, class StorageOrder
          , class Allocator, class Padding
          >
  struct  block<Type,Extend,Bases,Sizes,StorageOrder,heap_(Allocator),Padding>
        : details::block_extent<Bases,Sizes>
        , details::block_data<Type,heap_(Allocator),Extend>
        , details::block_access<Type, StorageOrder>
  {
    ////////////////////////////////////////////////////////////////////////////
    // block parent types
    ////////////////////////////////////////////////////////////////////////////
    typedef details::block_extent<Bases,Sizes>                extent_parent;
    typedef details::block_data<Type,heap_(Allocator),Extend> data_parent;
    typedef details::block_access<Type, StorageOrder>         access_parent;

    ////////////////////////////////////////////////////////////////////////////
    // block hierarchy
    ////////////////////////////////////////////////////////////////////////////
    //typedef xxx nt2_hierarchy_tag;

    ////////////////////////////////////////////////////////////////////////////
    // block is a RandonAccessSequence
    ////////////////////////////////////////////////////////////////////////////
    typedef Type       value_type;
//    typedef typename buffer_type::pointer          iterator;
//    typedef typename buffer_type::const_pointer    const_iterator;
    typedef typename access_parent::reference        reference;
    typedef typename access_parent::const_reference  const_reference;
    typedef typename extent_parent::size_type        size_type;
    typedef typename extent_parent::difference_type  difference_type;
    typedef typename extent_parent::difference_type  index_type;

    ////////////////////////////////////////////////////////////////////////////
    // Constructors and stuff
    ////////////////////////////////////////////////////////////////////////////
    block(Bases const& bs, Sizes const& sz, Allocator const& a = Allocator())
          : extent_parent(bs,sz)
    {
      init();
      link();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Data access
    ////////////////////////////////////////////////////////////////////////////
    template<class Position>
    reference operator()(Position const& p)
    {
      return access_parent::
              at( p
                , data_parent::template data<Extend::value>()
                );
    }

    template<class Position>
    const_reference operator()(Position const& p) const
    {
      return access_parent::
              at( p
                , data_parent::template data<Extend::value>()
                );
    }

    protected:
    ////////////////////////////////////////////////////////////////////////////
    // Initialize a NRC block
    ////////////////////////////////////////////////////////////////////////////
    void init()
    {
      boost::fusion::nview<Sizes const,StorageOrder>  sz(extent_parent::mSize);
      boost::fusion::nview<Bases const,StorageOrder>  bz(extent_parent::mBase);
      data_parent::init ( Extend(), bz, sz, Padding()
                        , typename meta::is_composite<Type>::type()
                        );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Link indexes and data, NRC style and recursively
    ////////////////////////////////////////////////////////////////////////////
    void link()
    {
      boost::fusion::nview<Sizes const,StorageOrder>  sz(extent_parent::mSize);
      data_parent::link ( Extend(), sz, Padding()
                        , typename meta::is_composite<Type>::type()
                        );
    }
  };
} }

#endif
