/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_BLOCK_SIZE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_BLOCK_SIZE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Hoisted class for size related block member functions
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>
#include <boost/mpl/size_t.hpp>
#include <nt2/sdk/memory/slice.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/adapted/mpl.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/memory/no_padding.hpp>
#include <boost/fusion/adapted/array.hpp>
#include <boost/fusion/include/value_at.hpp>

namespace nt2 { namespace details
{
  template<class Sizes> struct block_size
  {
    block_size(Sizes const& sz) : mSize(sz) {}

    ////////////////////////////////////////////////////////////////////////////
    // size_type is the type holding the reuslt of the std like size() function
    ////////////////////////////////////////////////////////////////////////////
    typedef
    typename boost::fusion::result_of::value_at_c<Sizes const,0>::type  size_type;

    ////////////////////////////////////////////////////////////////////////////
    // Return the total number of effective elements in a block
    ////////////////////////////////////////////////////////////////////////////
    inline size_type size()  const
    {
      return slice<1>(mSize,memory::no_padding());
    }

    ////////////////////////////////////////////////////////////////////////////
    // Return if a block is empty
    ////////////////////////////////////////////////////////////////////////////
    bool empty() const { return this->size() != 0; }

    ////////////////////////////////////////////////////////////////////////////
    // Return the number of element on the Nth dimension
    ////////////////////////////////////////////////////////////////////////////
    template<std::size_t N>
    typename boost::enable_if_c < (N<=boost::mpl::size<Sizes>::value)
                                , size_type
                                >::type
    size() const
    {
      return boost::fusion::at_c<N-1>(mSize);
    }

    template<std::size_t N>
    typename boost::disable_if_c< (N<=boost::mpl::size<Sizes>::value)
                                , size_type
                                >::type
    size() const
    {
      return 1;
    }

    void resize(Sizes const& sz)
    {
      mSize = sz;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Stored size informations - we can't rely on retrieving them from the
    // data block sequence as each buffer contains its fully required space.
    ////////////////////////////////////////////////////////////////////////////
    Sizes mSize;
  };
} }

#endif
