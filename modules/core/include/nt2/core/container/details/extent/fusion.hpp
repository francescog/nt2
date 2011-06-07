//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_FUSION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_FUSION_HPP_INCLUDED

#include <boost/fusion/support/is_view.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/support/category_of.hpp>

//==============================================================================
// Extension fo boost::fusion to support extent as a fusion sequence
//==============================================================================
namespace boost { namespace fusion
{
  namespace extension
  {
    //==========================================================================
    // Register extent_ and extent_ expression as random access sequence
    //==========================================================================
    template<> struct is_sequence_impl<nt2::tag::extent_>
    {
      template<typename Seq> struct apply : mpl::true_ {};
    };

    template<> struct is_view_impl<nt2::tag::extent_>
    {
      template<typename Seq> struct apply : mpl::false_ {};
    };

    template<> struct category_of_impl<nt2::tag::extent_>
    {
      typedef random_access_traversal_tag type;
    };

    //==========================================================================
    // Size of extent_ expression is given by its Dimensions
    //==========================================================================
    template<> struct size_impl<nt2::tag::extent_>
    {
      template<typename Sequence>
      struct apply : mpl::int_<Sequence::static_dimensions> {};
     };

    //==========================================================================
    // at_c value of extent_ is given by its operator() for both const/non-const
    //==========================================================================
    template<> struct at_impl<nt2::tag::extent_>
    {
      template<typename Sequence, typename Index>
      struct apply
      {
        typedef typename mpl::if_ < is_const<Sequence>
                                  , typename Sequence::const_reference
                                  , typename Sequence::reference
                                  >::type                                 type;

        static type call(Sequence& seq) { return seq(Index::value+1); }
      };
    };

    //==========================================================================
    // begin returns the inner data_type begin as it is itself a Fusion Sequence
    //==========================================================================
    template<> struct begin_impl<nt2::tag::extent_>
    {
      template<typename Sequence>
      struct apply
      {
        typedef typename nt2::meta::strip<Sequence>::type             base;
        typedef typename base::data_type                              data;

        typedef typename mpl::if_ < is_const<Sequence>
                                  , boost::fusion::result_of::begin<data const>
                                  , boost::fusion::result_of::begin<data>
                                  >::type::type                       type;

        static type call(Sequence& seq)
        {
          return boost::fusion::begin(seq.data());
        }
      };
    };

    //==========================================================================
    // end returns the inner data_type end as it is itself a Fusion Sequence
    //==========================================================================
    template<> struct end_impl<nt2::tag::extent_>
    {
      template<typename Sequence>
      struct apply
      {
        typedef typename nt2::meta::strip<Sequence>::type             base;
        typedef typename base::data_type                              data;

        typedef typename mpl::if_ < is_const<Sequence>
                                  , boost::fusion::result_of::end<data const>
                                  , boost::fusion::result_of::end<data>
                                  >::type::type                       type;

        static type call(Sequence& seq)
        {
          return boost::fusion::end(seq.data());
        }
      };
    };
  }
} }

#endif
