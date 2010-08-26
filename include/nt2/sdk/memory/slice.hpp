/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_SLICE_HPP_INCLUDED
#define NT2_SDK_MEMORY_SLICE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Padding strategies and related functors
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/memory/padding.hpp>
#include <nt2/sdk/functor/functor.hpp>
#include <boost/fusion/include/size.hpp>
#include <nt2/sdk/functor/preprocessor/function.hpp>

////////////////////////////////////////////////////////////////////////////////
// Functor tags
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace functors
{
  struct slice_  {};

  //////////////////////////////////////////////////////////////////////////////
  // slice<Level>(sz,padder) computes the nbr of element between the Level and
  // size(sz)th index level of a dimension sets
  //////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct functor< slice_, Info >
  {
    struct validate { typedef boost::mpl::true_ result_type; };

    template<class Sig> struct result;

    template<class This,class Seq,class N,class S,class Padder>
    struct result<This(Seq,Padder,N,S)>
    {
      typedef call<slice_,tag::fusion_(Padder),Info>                callee;
      typedef typename  std::tr1
                      ::result_of<callee( Seq, Padder, N, S)>::type type;
    };

    template<class A0,class A1,class A2,class A3> inline
    typename meta::enable_call<slice_(A0,A1,A2,A3)>::type
    operator()(A0 const& a0, A1 const& a1, A2 const& a2, A3 const& a3) const
    {
      functors::call<slice_,tag::fusion_(A1),Info>  callee;
      return callee(a0,a1,a2,a3);
    }
  };
} }

namespace nt2
{
  template<int N, class S,class P> inline
  typename  nt2::meta
          ::enable_call<functors::slice_( S
                                        , P
                                        , boost::mpl::long_<N>
                                        , typename  boost::fusion
                                                  ::result_of::size<S>::type
                                        )
                                  >::type
  slice(S const& s, P const& p)
  {
    typedef boost::fusion::result_of::size<S> sz;
    functors::functor< functors::slice_> callee;
    return callee(s,p,boost::mpl::long_<N>(),typename sz::type());
  }
}

#endif