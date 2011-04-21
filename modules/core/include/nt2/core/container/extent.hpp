/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_EXTENT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_EXTENT_HPP_INCLUDED

#include <boost/mpl/sizeof.hpp>
#include <nt2/core/container/forward.hpp>
#include <nt2/core/container/details/extent/facade.hpp>

namespace nt2 { namespace container
{
  template< std::size_t D
          , class T     = std::size_t
          , class Dummy = boost::proto::is_proto_expr
          >
  struct  extent
        : facade< tag::extent_,T,boost::mpl::size_t<D> >::type
  {
    typedef typename
            facade< tag::extent_,T,boost::mpl::size_t<D> >::type      parent;
    typedef typename
            facade< tag::extent_,T,boost::mpl::size_t<D> >::data_type data_type;

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor leads to a [0 1 ... 1] extents
    ////////////////////////////////////////////////////////////////////////////
    extent() : parent()
    {
      boost::proto::value(*this).fill(1);
      boost::proto::value(*this)[0] = 0;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from 1...N Dimensions
    ////////////////////////////////////////////////////////////////////////////
    #define M1(z,n,t) boost::proto::value(*this)[n]= BOOST_PP_CAT(d,n); \
    /**/

    #define M0(z,n,t)                                                   \
    template<class U>                                                   \
    extent( BOOST_PP_ENUM_PARAMS(n,U d)                                 \
          , typename boost::enable_if_c<  (n<=D)                        \
                                       && boost::mpl::sizeof_<U>::value \
                                       >::type* = 0                     \
          ) : parent()                                                  \
    {                                                                   \
      boost::proto::value(*this).fill(1);                               \
      BOOST_PP_REPEAT(n,M1,~)                                           \
    }                                                                   \
    /**/

    BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(NT2_MAX_DIMENSIONS),M0,~)

    #undef M0
    #undef M1

    ////////////////////////////////////////////////////////////////////////////
    // Assignment from non-AST
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    // Elementwise access
    ////////////////////////////////////////////////////////////////////////////
    T& operator()(std::size_t i)
    {
      return boost::proto::value(*this)[i-1];
    }

    T const& operator()(std::size_t i) const
    {
      return boost::proto::value(*this)[i-1];
    }

    ////////////////////////////////////////////////////////////////////////////
    // Container API
    ////////////////////////////////////////////////////////////////////////////
    typedef typename data_type::size_type       size_type;
    typedef size_type                           base_type;
    typedef typename data_type::difference_type difference_type;

    inline size_type size()  const
    {
      return boost::proto::value(*this).size();
    }

    inline bool empty() const { return boost::proto::value(*this).empty(); }

    typedef typename data_type::iterator        iterator;
    typedef typename data_type::const_iterator  const_iterator;

    iterator begin()  { return boost::proto::value(*this).begin();  }
        iterator end()    { return boost::proto::value(*this).end();    }

    const_iterator begin()  const { return boost::proto::value(*this).begin();  }
    const_iterator end()    const { return boost::proto::value(*this).end();    }

    ////////////////////////////////////////////////////////////////////////////
    // Size and Bases related accessor
    ////////////////////////////////////////////////////////////////////////////
    inline size_type numel()  const { return D; }

    template<std::size_t N> inline size_type size() const
    {
      return (N==1) ? D : 1;
    }

    template<std::size_t N> inline base_type lower() const
    {
      return 1;
    }

    template<std::size_t N> inline difference_type upper() const
    {
      return (N==1) ? D : 1;
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
  using container::extent;
}

#endif
