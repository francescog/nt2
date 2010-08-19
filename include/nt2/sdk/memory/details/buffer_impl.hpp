/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_DETAILS_BUFFER_IMPL_HPP_INCLUDED
#define NT2_SDK_MEMORY_DETAILS_BUFFER_IMPL_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Raw structure to handle exception safe buffer allocation
////////////////////////////////////////////////////////////////////////////////
#include <boost/swap.hpp>
#include <nt2/sdk/memory/align_on.hpp>

namespace nt2 { namespace details
{
  ////////////////////////////////////////////////////////////////////////////
  // Implementation structure
  ////////////////////////////////////////////////////////////////////////////
  template<class Type, class Allocator>
  struct buffer_impl : Allocator
  {
    typedef Allocator                       base;
    typedef typename base::pointer          pointer;
    typedef typename base::difference_type  difference_type;
    typedef typename base::size_type        size_type;

    pointer origin_, capacity_, begin_, end_;

    buffer_impl(base const& a)  : base(a)
    {
      origin_ = capacity_ = begin_ = end_ = 0;
    }

    void allocate(difference_type b, size_type s)
    {
      size_type asz = memory::align_on(s);
      origin_       = base::allocate(asz);
      scale(asz, s, b);
    }

    void resize(difference_type b, size_type s)
    {
      size_type asz = memory::align_on(s);
      size_type osz = capacity_ - origin_;
      origin_       = base::resize(origin_,asz,osz);
      scale(asz, s, b);
    }

    void scale(size_type capa, size_type size, difference_type lower)
    {
      capacity_     = origin_ + capa;
      begin_        = origin_ - lower;
      end_          = begin_  + size;
    }

    void swap(buffer_impl& src)
    {
      boost::swap(origin_     , src.origin_     );
      boost::swap(capacity_   , src.capacity_   );
      boost::swap(begin_      , src.begin_      );
      boost::swap(end_        , src.end_        );
      boost::swap(allocator() , src.allocator() );
    }

    base& allocator() { return static_cast<base&>(*this); }
  };
} }

#endif