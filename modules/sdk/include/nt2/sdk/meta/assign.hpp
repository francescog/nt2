/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_META_ASSIGN_HPP_INCLUDED
#define NT2_SDK_META_ASSIGN_HPP_INCLUDED

#include <boost/fusion/include/end.hpp>
#include <boost/fusion/include/begin.hpp>
#include <boost/fusion/include/equal_to.hpp>
#include <boost/fusion/include/next.hpp>

namespace nt2 { namespace details
{
  template <typename Seq1, typename Seq2>
  struct sequence_copy
  {
      typedef typename boost::fusion::result_of::end<Seq1>::type end1_type;
      typedef typename boost::fusion::result_of::end<Seq2>::type end2_type;

      template <typename I1, typename I2>
      static void
      call(I1 const&, I2 const&, boost::mpl::true_)
      {
      }

      template <typename I1, typename I2>
      static void
      call(I1 const& dst, I2 const& src, boost::mpl::false_)
      {
        *dst = *src;
        call(boost::fusion::next(dst), boost::fusion::next(src));
      }

      template <typename I1, typename I2>
      static void call(I1 const& dst, I2 const& src)
      {
        typedef
        typename boost::fusion::result_of::equal_to<I1, end1_type>::type eq1_t;

        typedef
        typename boost::fusion::result_of::equal_to<I2, end2_type>::type eq2_t;

        typename boost::mpl::or_<eq1_t,eq2_t>::type eq;

        return call(dst, src, eq);
      }
  };
} }

namespace nt2 { namespace meta
{
  template <typename Seq1, typename Seq2>
  inline void
  assign(Seq1& dst, Seq2 const& src)
  {
    details::sequence_copy<
        Seq1, Seq2 const>::
        call(boost::fusion::begin(dst), boost::fusion::begin(src));
  }
} }

#endif

