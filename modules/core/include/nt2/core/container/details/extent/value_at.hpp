//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_SCALAR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_VALUE_AT_SCALAR_HPP_INCLUDED

#include <nt2/sdk/dsl/compute.hpp>
#include <boost/fusion/include/at.hpp>
#include <nt2/core/functions/value_at.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is an extent expression
/////////////////////////////////////////////////////////////////////////////
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

      int32_t idx = boost::fusion::at_c<0>(a1) - 1;
      return callee(a0,target,idx);
    }
  };
} }

#endif
