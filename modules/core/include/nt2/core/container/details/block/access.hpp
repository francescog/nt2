/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_BLOCK_ACCESS_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_BLOCK_ACCESS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Hoisted class for element access related block member functions
////////////////////////////////////////////////////////////////////////////////
#include <boost/mpl/size.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/nview.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <nt2/core/container/meta/composite.hpp>

namespace nt2 { namespace details
{
  template< class Type
          , class StorageOrder
          , bool IsComposite = meta::is_composite<Type>::value
          >
  struct block_access;

  //////////////////////////////////////////////////////////////////////////////
  // Handle non-composite type access
  //////////////////////////////////////////////////////////////////////////////
  template< class Type
          , class StorageOrder
          >
  struct block_access<Type,StorageOrder,false>
  {
    typedef Type&        reference;
    typedef Type const&  const_reference;

    template<int N, class Dummy=void>
    struct access
    {
      typedef Type&        reference;
      typedef Type const&  const_reference;

      template<class Data, class Position>
      reference operator()(Data& d, Position const& p) const
      {
        access<N-1> callee;
        return callee( d[ boost::fusion::at_c<N-1>(p) ], p );
      }

      template<class Data, class Position>
      const_reference operator()(Data const& d, Position const& p) const
      {
        access<N-1> callee;
        return callee( d[ boost::fusion::at_c<N-1>(p) ], p );
      }
    };

    template<class Dummy>
    struct access<1,Dummy>
    {
      template<class Data, class Position>
      reference operator()(Data& d, Position const& p) const
      {
        return d[ boost::fusion::at_c<0>(p) ];
      }

      template<class Data, class Position>
      const_reference operator()(Data const& d, Position const& p) const
      {
        return d[ boost::fusion::at_c<0>(p) ];
      }
    };

    template<class Position,class Data> inline
    reference at(Position const& pos, Data& data) const
    {
      boost::fusion::nview<Position const,StorageOrder>  p(pos);
      access<boost::mpl::size<Position>::value> callee;
      return callee(data,p);
    }

    template<class Position,class Data> inline
    const_reference at(Position const& pos, Data const& data) const
    {
      boost::fusion::nview<Position const,StorageOrder>  p(pos);
      access<boost::mpl::size<Position>::value> callee;
      return callee(data,p);
    }
  };

  //////////////////////////////////////////////////////////////////////////////
  // Handle composite type access
  //////////////////////////////////////////////////////////////////////////////
  template< class Type
          , class StorageOrder
          >
  struct block_access<Type,StorageOrder,true>
  {
    typedef typename boost::fusion::result_of::as_vector<Type>::type  base_type;
    typedef typename boost::mpl::transform< base_type
                                          , boost::add_const<boost::mpl::_1>
                                          >::type             const_type;
    typedef typename boost::mpl::transform< base_type
                                          , boost::add_reference<boost::mpl::_1>
                                          >::type             reference;
    typedef typename boost::mpl::transform< const_type
                                          , boost::add_reference<boost::mpl::_1>
                                          >::type             const_reference;

    template<int N, class Dummy=void> struct access
    {
        template<class Data, class Position>
        reference operator()(Data& d, Position const& p) const
        {
          access<N-1> callee;
          return callee( d[ boost::fusion::at_c<N-1>(p) ], p );
        }

        template<class Data, class Position>
        const_reference operator()(Data const& d, Position const& p) const
        {
          access<N-1> callee;
          return callee( d[ boost::fusion::at_c<N-1>(p) ], p );
        }
    };

    template<class Dummy> struct access<2,Dummy>
    {
      template<class Data, class Position>
      reference operator()(Data& d, Position const& p) const
      {
       // return d[ boost::fusion::at_c<0>(p) ];
      }

      template<class Data, class Position>
      const_reference operator()(Data const& d, Position const& p) const
      {
       // return d[ boost::fusion::at_c<0>(p) ];
      }
    };

    template<class Position,class Data> inline
    reference at(Position const& pos, Data& data) const
    {
      boost::fusion::nview<Position const,StorageOrder>  p(pos);
      access<boost::mpl::size<Position>::value> callee;
      return callee(data,p);
    }

    template<class Position,class Data> inline
    const_reference at(Position const& pos, Data const& data) const
    {
      boost::fusion::nview<Position const,StorageOrder>  p(pos);
      access<boost::mpl::size<Position>::value> callee;
      return callee(data,p);
    }
  };
} }

#endif
