/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_TABLE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_HPP_INCLUDED

#include <nt2/core/container/extent.hpp>
#include <nt2/core/container/forward.hpp>
#include <nt2/core/container/details/table/facade.hpp>
#include <boost/preprocessor/repetition/enum_shifted_binary_params.hpp>

namespace nt2 { namespace container
{
  template< class Type
          , class Settings = nt2::settings()
          , class Dummy    = boost::proto::is_proto_expr
          >
  struct  table
        : facade<tag::table_,Type,Settings>::type
  {
    typedef typename facade<tag::table_,Type,Settings>::type parent;
    typedef typename facade<tag::table_,Type,Settings>::data_type data_type;

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////////////////////
    table() : parent() {}

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from extent
    ////////////////////////////////////////////////////////////////////////////
    template<std::size_t N, class T>
    table( extent<N,T> const& szs ) : parent()
    {
      typename data_type::sizes_type d;
      d.fill(1);
      std::copy(szs.begin(),szs.end(),d.begin());
      boost::proto::value(*this).resize( d );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Assignment from non-AST
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Container API
    ////////////////////////////////////////////////////////////////////////////
    typedef typename data_type::size_type       size_type;
    typedef typename data_type::base_type       base_type;
    typedef typename data_type::difference_type difference_type;

    inline size_type size()  const
    {
      return boost::proto::value(*this).size();
    }

    inline bool empty() const { return boost::proto::value(*this).empty(); }

    ////////////////////////////////////////////////////////////////////////////
    // Size and Bases related accessor
    ////////////////////////////////////////////////////////////////////////////
    inline size_type numel()  const { return this->size();    }

    template<std::size_t N> inline size_type size() const
    {
      return boost::proto::value(*this).template size<N>();
    }

    template<std::size_t N> inline base_type lower() const
    {
      return boost::proto::value(*this).template lower<N>();
    }

    template<std::size_t N> inline difference_type upper() const
    {
      return boost::proto::value(*this).template upper<N>();
    }


/*
  // OLD nt2 interface to bring back
      size_t    length()              const { return mSize.length();   }
      size_t    height()              const { return mSize.height();   }
      size_t    width()               const { return mSize.width();    }
      size_t    depth()               const { return mSize.depth();    }
      size_t    chan()                const { return mSize.chan();     }
      size_t    nDims()               const { return mSize.nDims();    }

      ptrdiff_t dimy()                const { return width();          }
      ptrdiff_t dimx()                const { return height();         }
      ptrdiff_t dimz()                const { return depth();          }
      ptrdiff_t dimv()                const { return chan();           }

 */
    using parent::operator=;
  };
} }

namespace nt2
{
  using container::table;
}

#endif
