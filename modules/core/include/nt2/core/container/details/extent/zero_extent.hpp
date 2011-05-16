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

#include <boost/fusion/include/single_view.hpp>
#include <nt2/core/container/details/extent/facade.hpp>

namespace nt2 { namespace container
{
  //============================================================================
  // 0D specialization for extent. _0D is used to represent extent of scalar
  // values. It still models Container and Collection but acts as an ever empty
  // one. Values returned by various accessors are always 1.
  //============================================================================
  template<> struct  extent<_0D> : facade<tag::extent_,_0D,void>::type
  {
    typedef facade<tag::extent_,_0D,void>           facade_type;
    typedef facade_type::type                       parent;
    typedef boost::fusion::single_view<std::size_t> data_type;
    typedef std::size_t                             value_type;
    typedef std::size_t                             const_reference;
    typedef std::size_t                             size_type;
    typedef size_type                               base_type;
    typedef std::ptrdiff_t                          difference_type;
    typedef void*                                   iterator;
    typedef void*                                   const_iterator;

    static const std::size_t static_dimension = 0;

    extent() : parent() {}
    extent( extent const& ) : parent() {}
    extent& operator=( extent const& ) { return *this; }

    data_type       data()                    const { return data_type(1);  }
    const_reference operator()(std::size_t i) const { return 1;             }

    iterator        begin()       { return iterator(0);       }
    const_iterator  begin() const { return const_iterator(0); }
    iterator        end()         { return iterator(0);       }
    const_iterator  end()   const { return const_iterator(0); }

    inline size_type        size()                const { return 1;     }
    inline bool             empty()               const { return false; }
    inline size_type        size(std::size_t i)   const { return 1;     }
    inline base_type        lower(std::size_t i)  const { return 1;     }
    inline difference_type  upper(std::size_t i)  const { return 1;     }
    inline std::size_t      nDims()               const { return 0;     }
  };
} }

#endif
