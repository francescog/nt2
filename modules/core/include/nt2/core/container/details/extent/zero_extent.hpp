//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_ZERO_EXTENT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_ZERO_EXTENT_HPP_INCLUDED

#include <boost/mpl/vector_c.hpp>
#include <boost/fusion/include/tag_of.hpp>
#include <nt2/core/container/details/extent/facade.hpp>

namespace nt2 { namespace containers
{
  //============================================================================
  // 0D specialization for extent. _0D is used to represent extent of scalar
  // values. It still models Container and Collection but acts as an ever empty
  // one. Values returned by various accessors are always 1.
  //============================================================================
  template<> struct  extent<_0D> : public ext::facade<tag::extent_,_0D,void>::type
  {
    typedef ext::facade<tag::extent_,_0D,void>      facade_type;
    typedef tag::extent_                            fusion_tag;
    typedef facade_type::type                       parent;
    typedef boost::mpl::vector_c<std::size_t,1,1>   data_type;
    typedef std::size_t                             size_type;
    typedef size_type                               base_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef void*                                   iterator;
    typedef void*                                   const_iterator;

    extent() : parent() {}
    extent( extent const& ) : parent() {}

    template<class XPR, class D> inline
    explicit extent( container<XPR, tag::extent_,D> const& ) {}

    extent& operator=( extent const& ) { return *this; }

    data_type       data()  const { return data_type();       }
    iterator        begin()       { return iterator(0);       }
    const_iterator  begin() const { return const_iterator(0); }
    iterator        end()         { return iterator(0);       }
    const_iterator  end()   const { return const_iterator(0); }

    inline std::size_t      nDims()               const { return 0;     }
  };
} }

#endif
