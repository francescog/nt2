//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DETAILS_TABLE_VALUE_AT_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_TABLE_VALUE_AT_HPP_INCLUDED

#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/core/functions/value_at.hpp>

//==============================================================================
// Implementation when type A0 is a table expression and A1 a sequence
//==============================================================================
NT2_REGISTER_DISPATCH ( tag::value_at_, tag::cpu_
                      , (A0)(D0)(Sema0)(Tag0)(A1)
                      , ((expr_ < A0
                                , domain_<containers::domain<tag::table_,D0> >
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
                ( tag::expr_< containers::domain < tag::table_, D >
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
              (A0,meta::as_<void>,A1)
            >
    {};

    NT2_FUNCTOR_CALL(2)
    {
      meta::as_<void>                                           target;
      meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >  callee;
      return callee(a0,target,a1);
    }
  };

  //============================================================================
  // terminal case
  //============================================================================
  template<class D, class Sema, class Dummy>
  struct call < tag::value_at_
                ( tag::expr_< containers::domain < tag::table_, D >
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
      typedef typename boost::remove_reference<A0>::type  base;
      typedef typename meta::strip<A0>::type              raw;
      typedef typename boost::mpl::if_< boost::is_const<base>
                                      , typename raw::const_reference
                                      , typename raw::reference
                                      >::type type;
    };

    template<class A0,class A1> inline
    typename result<call(A0&,A1 const&)>::type
    operator()(A0& a0, A1 const& a1) const
    {
      return boost::proto::value(a0)(a1);
    }

    NT2_FUNCTOR_CALL(2) { return boost::proto::value(a0)(a1); }
  };

} }

#endif
