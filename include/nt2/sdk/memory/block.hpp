#if !BOOST_PP_IS_ITERATING
/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_BLOCK_HPP_INCLUDED
#define NT2_SDK_MEMORY_BLOCK_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Multidimensional memory block with NRC style allocation
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/memory/slice.hpp>
#include <nt2/sdk/memory/stride.hpp>
#include <nt2/extension/parameters.hpp>
#include <nt2/sdk/error/static_assert.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>

/*
#include <boost/fusion/include/at.hpp>
#include <nt2/sdk/memory/details/make_buffer.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
*/

namespace nt2 { namespace memory
{
  //////////////////////////////////////////////////////////////////////////////
  // block is a multidimensionnal buffer using NRC model and bearing all the
  // related options in its parameters
  //////////////////////////////////////////////////////////////////////////////
  template< class Type
          , std::size_t Dimensions
          , class Bases
          , class Sizes
          , class TargetArch
          , class Padding
          , class Allocator
          >
  class block;
} }

/*
////////////////////////////////////////////////////////////////////////////////
// Macro generating the type of the nth data member
////////////////////////////////////////////////////////////////////////////////
#define NT2_DATA_TYPE(n)  BOOST_PP_CAT(BOOST_PP_CAT(buffer,n),_type)

////////////////////////////////////////////////////////////////////////////////
// Macro generating the name of the nth data member
////////////////////////////////////////////////////////////////////////////////
#define NT2_DATA_MEMBER(n)  BOOST_PP_CAT(BOOST_PP_CAT(data,n),_)

////////////////////////////////////////////////////////////////////////////////
// Macro generating the list of inner buffer types
////////////////////////////////////////////////////////////////////////////////
#define NT2_MAKE_BUFFER_TYPE(z,n,t)                                             \
typedef typename details::make_buffer<n,T,Bases,Sizes,Padding,Allocator>::type  \
NT2_DATA_TYPE(BOOST_PP_DEC(n));                                                 \


////////////////////////////////////////////////////////////////////////////////
// Macro generating the list of inner buffer members
////////////////////////////////////////////////////////////////////////////////
#define NT2_MAKE_DATA_MEMBER(z,n,t)                               \
NT2_DATA_TYPE(BOOST_PP_DEC(n)) NT2_DATA_MEMBER(BOOST_PP_DEC(n));  \


////////////////////////////////////////////////////////////////////////////////
// Macro generating the list of inner buffer members default constructor
////////////////////////////////////////////////////////////////////////////////
#define NT2_MAKE_DEFAULT_CTOR(z,n,t)  NT2_DATA_MEMBER(n)()

////////////////////////////////////////////////////////////////////////////////
// Macro generating the list of inner buffer members constructor
////////////////////////////////////////////////////////////////////////////////
#define NT2_MAKE_CTOR(z,n,t)                                                \
NT2_DATA_MEMBER(BOOST_PP_INC(n))( boost::fusion::at_c<BOOST_PP_INC(n)>(bs)  \
                                , boost::fusion::at_c<BOOST_PP_INC(n)>(ss)  \
                                )                                           \


////////////////////////////////////////////////////////////////////////////////
// Macro generating a ?: chain for dimension access
////////////////////////////////////////////////////////////////////////////////
#define NT2_DIM_SWITCH(z,n,t)                       \
(N==BOOST_PP_INC(n)) ? boost::fusion::at_c<n>(t) :  \


////////////////////////////////////////////////////////////////////////////////
// Macro generating a chain of []
////////////////////////////////////////////////////////////////////////////////
#define NT2_ACCESS(z,n,t)                                   \
[ boost::fusion::at_c<BOOST_PP_SUB(BOOST_PP_DEC(t),n)>(p) ] \


////////////////////////////////////////////////////////////////////////////////
// Macro generating a chain of [] for under-access
////////////////////////////////////////////////////////////////////////////////
#define NT2_OVERACCESS(z,n,t)                                             \
template<class Position> const_reference                                  \
access( Position const& p, boost::mpl::int_<n> const& )                   \
{                                                                         \
  return NT2_DATA_MEMBER(BOOST_PP_DEC(n))BOOST_PP_REPEAT(n,NT2_ACCESS,n); \
}                                                                         \
template<class Position> const_reference                                  \
access( Position const& p, boost::mpl::int_<n> const& ) const             \
{                                                                         \
  return NT2_DATA_MEMBER(BOOST_PP_DEC(n))BOOST_PP_REPEAT(n,NT2_ACCESS,n); \
}                                                                         \


////////////////////////////////////////////////////////////////////////////////
// Macro generating a chain of resize
////////////////////////////////////////////////////////////////////////////////
#define NT2_RESIZE(z,n,t)                                 \
NT2_DATA_MEMBER(n).resize ( boost::fusion::at_c<n>(base_) \
                          , boost::fusion::at_c<n>(size_) \
                          );                              \


////////////////////////////////////////////////////////////////////////////////
// Macro generating a chain of link between NRC levels
////////////////////////////////////////////////////////////////////////////////
#define NT2_LINK(z,n,t)                                                     \
void link( boost::mpl::int_<n> const&, size_type prev = 1)                  \
{                                                                           \
  size_type       sz = NT2_DATA_MEMBER(BOOST_PP_DEC(n)).size()*prev;        \
  NT2_DATA_MEMBER(BOOST_PP_DEC(n)).origin()[0]                              \
                              = NT2_DATA_MEMBER(BOOST_PP_SUB(n,2)).begin(); \
  for(size_type i=1;i<sz;++i)                                               \
  {                                                                         \
    NT2_DATA_MEMBER(BOOST_PP_DEC(n)).origin()[i]                            \
          = NT2_DATA_MEMBER(BOOST_PP_DEC(n)).origin()[i-1]                  \
          + boost::fusion::at_c<BOOST_PP_SUB(n,2)>(size_);                  \
  }                                                                         \
  link( boost::mpl::int_<n-1>(), sz);                                       \
}                                                                           \

////////////////////////////////////////////////////////////////////////////////
// Macro generating a chain of assignment
////////////////////////////////////////////////////////////////////////////////
#define NT2_ASSIGN(z,n,t) NT2_DATA_MEMBER(n) = src.NT2_DATA_MEMBER(n);
*/
#define  BOOST_PP_FILENAME_1        "nt2/sdk/memory/block.hpp"
#define  BOOST_PP_ITERATION_LIMITS  (1, NT2_MAX_ARITY)
#include BOOST_PP_ITERATE()
/*
#undef NT2_MAKE_BUFFER_TYPE
#undef NT2_MAKE_DATA_MEMBER
#undef NT2_MAKE_DEFAULT_CTOR
#undef NT2_MAKE_CTOR
#undef NT2_DATA_TYPE
#undef NT2_DATA_MEMBER
#undef NT2_DIM_SWITCH
#undef NT2_OVERACCESS
#undef NT2_ACCESS
#undef NT2_RESIZE
#undef NT2_LINK
#undef NT2_ASSIGN
*/
#endif

////////////////////////////////////////////////////////////////////////////////
// Preprocessed Code
////////////////////////////////////////////////////////////////////////////////
#else
////////////////////////////////////////////////////////////////////////////////
// Current specialization being compiled
////////////////////////////////////////////////////////////////////////////////
#define CURRENT_DIM  BOOST_PP_ITERATION()

namespace nt2 { namespace memory
{
  template< class T
          , class Bases, class Sizes
          , class TargetArch
          , class Padding, class Allocator
          >
  class block<T,CURRENT_DIM,Bases,Sizes,TargetArch,Padding,Allocator>
  {
    public:

    ////////////////////////////////////////////////////////////////////////////
    // Check that we don't pass incorrect Base/Size containers
    ////////////////////////////////////////////////////////////////////////////
    NT2_STATIC_ASSERT ( (boost::mpl::size<Bases>::value == CURRENT_DIM)
                      , BOOST_PP_CAT(BASES_EXTENT_IS_NOT_,CURRENT_DIM)
                      , (Bases)
                      );

    NT2_STATIC_ASSERT ( (boost::mpl::size<Sizes>::value == CURRENT_DIM)
                      , BOOST_PP_CAT(SIZES_EXTENT_IS_NOT_,CURRENT_DIM)
                      , (Sizes)
                      );

    NT2_STATIC_ASSERT ( (   boost::mpl::size<Bases>::value
                        ==  boost::mpl::size<Sizes>::value
                        )
                      , BASES_AND_SIZES_EXTENTS_MISMATCH
                      , (Bases,Sizes)
                      );

    ////////////////////////////////////////////////////////////////////////////
    // Public types
    ////////////////////////////////////////////////////////////////////////////
    typedef boost::mpl::int_<CURRENT_DIM> dimension_value_type;
/*
    BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(CURRENT_DIM),NT2_MAKE_BUFFER_TYPE,~)

    typedef typename buffer0_type::reference        reference;
    typedef typename buffer0_type::const_reference  const_reference;
    typedef typename buffer0_type::size_type        size_type;
    typedef typename buffer0_type::difference_type  difference_type;
*/

    ////////////////////////////////////////////////////////////////////////////
    // Default constructor
    ////////////////////////////////////////////////////////////////////////////
/*
    block() : BOOST_PP_ENUM(CURRENT_DIM, NT2_MAKE_DEFAULT_CTOR,~)
            , base_(), size_()
    {
      if(buffer0_type::is_static::value) link(dimension_value_type());
    }

    ////////////////////////////////////////////////////////////////////////////
    // Constructor from {bases,sizes}
    ////////////////////////////////////////////////////////////////////////////
    block ( Bases const& bs, Sizes const& ss )
        : data0_( boost::fusion::at_c<0>(bs), typename Padding::size()(ss) )
        BOOST_PP_COMMA_IF(BOOST_PP_GREATER(CURRENT_DIM,1))
        BOOST_PP_ENUM(BOOST_PP_DEC(CURRENT_DIM), NT2_MAKE_CTOR,~)
        , base_(bs)
        , size_(ss)
    {
      //////////////////////////////////////////////////////////////////////////
      // When the block has more than one dimension, we need to link the data
      // together through the index arrays
      //////////////////////////////////////////////////////////////////////////
      link( boost::mpl::int_<CURRENT_DIM>() );
    }

    ////////////////////////////////////////////////////////////////////////////
    // Destructor
    ////////////////////////////////////////////////////////////////////////////
    ~block() {}

    ////////////////////////////////////////////////////////////////////////////
    // Assignement from same block type
    ////////////////////////////////////////////////////////////////////////////
    block& operator=( block const& src )
    {
      if( this != &src)
      {
        base_ = src.base_;
        size_ = src.size_;
        BOOST_PP_REPEAT(CURRENT_DIM, NT2_ASSIGN, ~ )
        link( boost::mpl::int_<CURRENT_DIM>() );
      }

      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Assignement from different block type
    ////////////////////////////////////////////////////////////////////////////
    template<class U, class B2, class S2, class P2,class A2>
    block& operator=( block<U,CURRENT_DIM,B2,S2,P2,A2> const& src )
    {
      base_ = src.bases();
      size_ = src.sizes();
      if( boost::is_same<Padding,P2>::value )
      {
        // Same padding => copy + resize indexes
        data0_ = src.data();
        BOOST_PP_REPEAT_FROM_TO(1, CURRENT_DIM, NT2_RESIZE, ~ )
        link( boost::mpl::int_<CURRENT_DIM>() );
      }
      else
      {
        // Different padding => resize + elementwise copy
        data0_.resize ( boost::fusion::at_c<0>(base_)
                      , typename Padding::size()(size_)
                      );
        BOOST_PP_REPEAT_FROM_TO(1, CURRENT_DIM, NT2_RESIZE, ~ )

        link( boost::mpl::int_<CURRENT_DIM>() );

        #if (CURRENT_DIM > 1)
        for(difference_type i=lower<2>();i<=upper<2>();++i)
          for(difference_type j=lower<1>();j<=upper<1>();++j)
            (*this)(boost::fusion::make_vector(j,i)) =
                src(boost::fusion::make_vector(j,i));
        #else
        for(size_type i=0;i<data0_.size();++i)
          data0_.origin()[i] = src.data().origin()[i];
        #endif
      }

      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Data accessor - proper case
    ////////////////////////////////////////////////////////////////////////////
    template<class Position>
    typename boost::enable_if_c < (boost::mpl::size<Position>::value >= CURRENT_DIM)
                                , reference
                                >::type
    operator()( Position const& p )
    {
      return  NT2_DATA_MEMBER(BOOST_PP_DEC(CURRENT_DIM))
              BOOST_PP_REPEAT(CURRENT_DIM,NT2_ACCESS,CURRENT_DIM);
    }

    template<class Position>
    typename boost::enable_if_c < (boost::mpl::size<Position>::value >= CURRENT_DIM)
                                , const_reference
                                >::type
    operator()( Position const& p ) const
    {
      return  NT2_DATA_MEMBER(BOOST_PP_DEC(CURRENT_DIM))
              BOOST_PP_REPEAT(CURRENT_DIM,NT2_ACCESS,CURRENT_DIM);
    }

    ////////////////////////////////////////////////////////////////////////////
    // Data accessor : smaller case
    ////////////////////////////////////////////////////////////////////////////
    #if (CURRENT_DIM > 1)
    template<class Position>
    typename boost::enable_if_c < (boost::mpl::size<Position>::value < CURRENT_DIM)
                                , reference
                                >::type
    operator()( Position const& p )
    {
      return access(p, boost::mpl::int_<boost::mpl::size<Position>::value>());
    }

    template<class Position>
    typename boost::enable_if_c < (boost::mpl::size<Position>::value < CURRENT_DIM)
                                , const_reference
                                >::type
    operator()( Position const& p ) const
    {
      return access(p, boost::mpl::int_<boost::mpl::size<Position>::value>());
    }
    #endif

    ////////////////////////////////////////////////////////////////////////////
    // Access to base buffer
    ////////////////////////////////////////////////////////////////////////////
    buffer0_type const& data()  const { return data0_;  }
*/

    ////////////////////////////////////////////////////////////////////////////
    // Access to bases and sizes
    ////////////////////////////////////////////////////////////////////////////
    Bases bases()  const { return base_;  }
    Sizes sizes()  const { return size_;  }
/*
    ////////////////////////////////////////////////////////////////////////////
    // Size on dimension N
    ////////////////////////////////////////////////////////////////////////////
    template<std::size_t N>
    typename boost::enable_if_c<(N>0 && N<=CURRENT_DIM),size_type>::type
    size() const
    {
      return boost::fusion::at_c<N-1>(size_);
    }

    template<std::size_t N>
    typename boost::disable_if_c<(N>0 && N<=CURRENT_DIM),size_type>::type
    size() const
    {
      return 1;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Lower bound of valid index on dimension N
    ////////////////////////////////////////////////////////////////////////////
    template<std::size_t N>
    typename boost::enable_if_c<(N>0 && N<=CURRENT_DIM),difference_type>::type
    lower() const
    {
      return boost::fusion::at_c<N-1>(base_);
    }

    template<std::size_t N>
    typename boost::disable_if_c<(N>0 && N<=CURRENT_DIM),difference_type>::type
    lower() const
    {
      return 1;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Upper bound of valid index on dimension N
    ////////////////////////////////////////////////////////////////////////////
    template<std::size_t N> difference_type upper() const
    {
      return size<N>()+lower<N>()-1;
    }
*/
/*
    protected:
    ////////////////////////////////////////////////////////////////////////////
    // Access to a block with less index than needed
    ////////////////////////////////////////////////////////////////////////////
    #if (CURRENT_DIM > 1)
    template<class Position> reference
    access( Position const& p, boost::mpl::int_<1> const& )
    {
      typedef typename boost::fusion::result_of::value_at_c<Position,0>::type type;
      type idx = boost::fusion::at_c<0>(p) - boost::fusion::at_c<0>(base_);
      type lead  = idx % boost::fusion::at_c<0>(size_);
      type outer = idx / boost::fusion::at_c<0>(size_);
      return data1_[outer][lead];
    }

    template<class Position> const_reference
    access( Position const& p, boost::mpl::int_<1> const& ) const
    {
      typedef typename boost::fusion::result_of::value_at_c<Position,0>::type type;
      type idx = boost::fusion::at_c<0>(p) - boost::fusion::at_c<0>(base_);
      type lead  = idx % boost::fusion::at_c<0>(size_);
      type outer = idx / boost::fusion::at_c<0>(size_);
      return data1_[outer][lead];
    }

    BOOST_PP_REPEAT_FROM_TO(2,CURRENT_DIM,NT2_OVERACCESS,~)
    #endif

    ////////////////////////////////////////////////////////////////////////////
    // Link indexes and data
    ////////////////////////////////////////////////////////////////////////////
    void link( boost::mpl::int_<1> const& ) {}

    #if (CURRENT_DIM > 1)
    void link( boost::mpl::int_<2> const& )
    {
      data1_.origin()[0] = data0_.begin();
      for(size_type i=1;i<data1_.size();++i)
        data1_.origin()[i]  = data1_.origin()[i-1]
                            + stride<Paddingn,1>(size_);
    }

    BOOST_PP_REPEAT_FROM_TO(3,BOOST_PP_INC(CURRENT_DIM),NT2_LINK,~)
    #endif
*/
    private:
  //  BOOST_PP_REPEAT_FROM_TO(1,BOOST_PP_INC(CURRENT_DIM),NT2_MAKE_DATA_MEMBER,~)

    Bases         base_;
    Sizes         size_;
  };
} }

#endif
