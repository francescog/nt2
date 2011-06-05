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
    template<>
    struct is_sequence_impl<nt2::tag::extent_> : boost::mpl::true_ {};

    template<>
    struct is_view_impl<nt2::tag::extent_> : boost::mpl::false_ {};

    template<>
    struct category_of_impl<nt2::tag::extent_>
    {
      template<typename Sequence> struct apply
      {
        typedef random_access_traversal_tag type;
      };
    };

    template<>
    struct size_impl<nt2::tag::extent_>
    {
      template<typename Sequence>
      struct apply : mpl::int_<Sequence::static_dimensions> {};
     };
  }
} }

#endif
