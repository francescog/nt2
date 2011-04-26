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

#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/zip_view.hpp>
#include <boost/fusion/include/for_each.hpp>

namespace nt2 { namespace details
{
  struct fusion_assign
  {
    template<class T> inline void operator()(T const& e) const
    {
      boost::fusion::at_c<0>(e) = boost::fusion::at_c<1>(e);
    }
  };
} }

namespace nt2 { namespace meta
{
  template<class Sequence1, class Sequence2>
  void assign( Sequence1& dst, Sequence2 const& src )
  {
    typedef boost::fusion::vector<Sequence1&, Sequence2 const&> sequences;
    boost::fusion::zip_view<sequences> zv(sequences(dst,src));
    boost::fusion::for_each( zv, details::fusion_assign() );
  }

} }

#endif

