/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_BLOCK_HEAP_BLOCK_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_BLOCK_HEAP_BLOCK_HPP_INCLUDED

#include <nt2/sdk/meta/assign.hpp>
#include <nt2/sdk/memory/slice.hpp>
#include <nt2/sdk/memory/no_padding.hpp>
#include <nt2/core/container/extent.hpp>
#include <nt2/core/container/details/block/data.hpp>
#include <nt2/core/container/details/block/access.hpp>

namespace nt2 { namespace containers
{
  //////////////////////////////////////////////////////////////////////////////
  // Defines a block of memory to be used stored on the CPU heap
  //////////////////////////////////////////////////////////////////////////////
  template< class Type
          , class Dimensions
          , class StorageOrder
          , class Allocator
          , class Padding
          >
  struct  block < Type, Dimensions  , StorageOrder
                , heap_(Allocator)  , Padding
                >
        : details::block_data<Type,heap_(Allocator)
                              ,boost::mpl::size_t<Dimensions::static_dimension>
                              >
        , details::block_access<Type, StorageOrder>
  {
    ////////////////////////////////////////////////////////////////////////////
    // heap block stores his size and base index per dimension in a local
    // Collection
    ////////////////////////////////////////////////////////////////////////////
    typedef Dimensions                                            sizes_type;
    typedef boost::array<int,Dimensions::static_dimension>        bases_type;
    typedef details::block_access<Type, StorageOrder>             access_type;
    typedef boost::mpl::size_t<Dimensions::static_dimension> dimensions_type;
    typedef details::block_data<Type,heap_(Allocator),dimensions_type> nrc_type;

    ////////////////////////////////////////////////////////////////////////////
    // Block hierarchy is made of its base type and its settings
    ////////////////////////////////////////////////////////////////////////////
    typedef meta::block_< typename meta::hierarchy_of<Type>::type
                        , heap_
                        >                                   nt2_hierarchy_tag;

    ////////////////////////////////////////////////////////////////////////////
    // RandonAccessContainer interface
    ////////////////////////////////////////////////////////////////////////////
    typedef Type                                  value_type;
//    typedef typename access_type::pointer          iterator;
//    typedef typename access_type::const_pointer    const_iterator;
    typedef typename access_type::reference        reference;
    typedef typename access_type::const_reference  const_reference;
    typedef typename sizes_type::value_type       size_type;
    typedef typename bases_type::difference_type  difference_type;

    ////////////////////////////////////////////////////////////////////////////
    // Constructors
    ////////////////////////////////////////////////////////////////////////////
    block() : mSizes(), mBases() {}

    template<class Sizes, class Bases> block(Bases const& bs, Sizes const& sz)
    {
      meta::assign(mSizes.data(), sz);
      meta::assign(mBases, bs);
      init();
      link();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return the total number of effective elements in a block
    ////////////////////////////////////////////////////////////////////////////
    inline size_type size()  const
    {
      return slice<1>(mSizes.data(),memory::no_padding());
    }

    inline sizes_type const& sizes() const { return mSizes; }

    ////////////////////////////////////////////////////////////////////////////
    // Return if a block is empty
    ////////////////////////////////////////////////////////////////////////////
    bool empty() const { return this->size() == 0; }

    ////////////////////////////////////////////////////////////////////////////
    // Return the number of element on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    inline size_type size(std::size_t i) const
    {
      return  (i != 0) ?
              ((i <= Dimensions::static_dimension) ? mSizes(i) : 1)
            : size();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return the starting index on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    inline difference_type lower(std::size_t i) const
    {
      return (i <= Dimensions::static_dimension) ? mBases[i-1] : 1;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return the ending index on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    inline difference_type upper(std::size_t i) const
    {
      return (i <= Dimensions::static_dimension) ? (size(i) + lower(i) - 1) : 1;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Data access
    ////////////////////////////////////////////////////////////////////////////
    template<class Position>
    reference operator()(Position const& p)
    {
      return access_type::at( p
                            , access_type::template
                              data<Dimensions::static_dimension>()
                            );
    }

    template<class Position>
    const_reference operator()(Position const& p) const
    {
      return access_type::at( p
                            , access_type::template
                              data<Dimensions::static_dimension>()
                            );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Resize current block
    ////////////////////////////////////////////////////////////////////////////
    template<class Sizes> inline void resize(Sizes const& sz)
    {
      meta::assign(mSizes.data(), sz.data());
      init();
      link();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Reindex current block
    ////////////////////////////////////////////////////////////////////////////
    template<class Bases> inline void reindex(Bases const& bs)
    {
      meta::assign(mBases, bs);
      init();
      link();
    }

    ////////////////////////////////////////////////////////////////////////////
    // Restructure current block
    ////////////////////////////////////////////////////////////////////////////
    template<class Sizes, class Bases> inline
    void restructure(Bases const& bs, Sizes const& sz)
    {
      mSizes = sz;
      meta::assign(mBases, bs);
      init();
      link();
    }

    protected:
    ////////////////////////////////////////////////////////////////////////////
    // Size and bases storage
    ////////////////////////////////////////////////////////////////////////////
    sizes_type mSizes;
    bases_type mBases;

    ////////////////////////////////////////////////////////////////////////////
    // Initialize a NRC block
    ////////////////////////////////////////////////////////////////////////////
    void init()
    {
      using boost::fusion::nview;
      typedef typename sizes_type::data_type data_type;

      nrc_type::init( dimensions_type()
                    , nview<bases_type const,StorageOrder>(mBases)
                    , nview<data_type const,StorageOrder>(mSizes.data())
                    , Padding()
                    , typename meta::is_composite<Type>::type()
                    );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Link indexes and data, NRC style and recursively
    ////////////////////////////////////////////////////////////////////////////
    void link()
    {
      using boost::fusion::nview;
      typedef typename sizes_type::data_type data_type;

      nrc_type::link( dimensions_type()
                    , nview<data_type const,StorageOrder>(mSizes.data())
                    , Padding()
                    , typename meta::is_composite<Type>::type()
                    );
    }
  };
} }

#endif
