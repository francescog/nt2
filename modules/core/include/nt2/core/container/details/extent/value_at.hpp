//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_HPP_INCLUDED

#include <nt2/sdk/dsl/compute.hpp>
#include <boost/fusion/include/front.hpp>
#include <nt2/core/functions/value_at.hpp>

//==============================================================================
// Implementation when type A0 is an extent expression and A1 a sequence
//==============================================================================
NT2_REGISTER_DISPATCH ( tag::value_at_, tag::cpu_
                      , (A0)(D0)(Sema0)(Tag0)(A1)
                      , ((expr_ < A0
                                , domain_<containers::domain<tag::extent_,D0> >
                                , Tag0, Sema0
                                >
                        ))
                        (fusion_sequence_<A1>)
                      )

namespace nt2 { namespace ext
{
  //============================================================================
  // Const expression case
  //============================================================================
  template<class D, class Tag,  class Sema, class Dummy>
  struct call < tag::value_at_
                ( tag::expr_< containers::domain < tag::extent_, D >
                            , Tag, Sema
                            >
                , tag::fusion_sequence_
                )
              , tag::cpu_, Dummy
              > : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct  result<This(A0,A1)>
          : boost::result_of
            < meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >
              (A0,meta::as_<void>,int)
            >
    {};

    NT2_FUNCTOR_CALL(2)
    {
      meta::as_<void>                                           target;
      meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >  callee;

      typedef boost::mpl::size<A1> sz_;
      nt2::int32_t idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return callee(a0,target,idx);
    }
  };

  //============================================================================
  // terminal case
  //============================================================================
  template<class D, class Sema, class Dummy>
  struct call < tag::value_at_
                ( tag::expr_< containers::domain < tag::extent_, D >
                            , tag::extent_, Sema
                            >
                , tag::fusion_sequence_
                )
              , tag::cpu_, Dummy
              > : callable
  {
    template<class Sig> struct result;

    template<class This,class A0,class A1>
    struct  result<This(A0,A1)>
    {
      typedef typename boost::remove_reference<A0>::type base;
      typedef typename boost::mpl::if_< boost::is_const<base>
                                      , std::size_t
                                      , std::size_t&
                                      >::type type;
    };

    template<class A0,class A1> inline
    typename result<call(A0&,A1 const&)>::type
    operator()(A0& a0, A1 const& a1) const
    {
      typedef boost::mpl::size<A1> sz_;
      std::size_t idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return boost::proto::value(a0)[ idx ];
    }

    NT2_FUNCTOR_CALL(2)
    {
      typedef boost::mpl::size<A1> sz_;
      std::size_t idx = boost::fusion::at_c<(sz_::value < 2 ? 0 : 1)>(a1) - 1;
      return boost::proto::value(a0)[ idx ];
    }
  };
} }

#endif
