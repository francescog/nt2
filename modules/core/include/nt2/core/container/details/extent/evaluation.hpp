/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_EVALUATION_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_EVALUATION_HPP_INCLUDED

#include <nt2/sdk/dsl/litteral.hpp>
#include <nt2/sdk/dsl/evaluation.hpp>
#include <nt2/core/container/details/extent/call.hpp>

////////////////////////////////////////////////////////////////////////////////
// Evaluation strategy for extent class
////////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH_TPL (  tag::evaluate_,tag::cpu_
                          , (class A0)(std::size_t N)
                            (class A1)(class Tag)(class Sema)
                          , ((array_<arithmetic_<A0>,N>))
                            ((expr_ < A1
                                    , domain_ < containers::
                                                domain< tag::extent_
                                                      , boost::mpl::size_t<2>
                                                      >
                                              >
                                    , Tag, Sema
                                    >
                            ))
                          )

namespace nt2 { namespace ext
{
  template<std::size_t N,class Tag, class Sema, class Dummy>
  struct call < tag::evaluate_
                ( tag::array_<tag::arithmetic_,N>
                , tag::expr_<containers::domain < tag::extent_
                                                , boost::mpl::size_t<2>
                                                >
                            , Tag, Sema
                            >
                )
              , tag::cpu_, Dummy
              > : callable
  {
    typedef void result_type;

    template<class A0, class A1> inline void
    operator()( A0& a0, A1 const& a1) const
    {
      meta::as_<A0> target;
      meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> > callee;

      for(std::size_t i=0;i<A0::static_size;++i)
        a0[i] = callee(a1,target,i);
    }
  };
} }
#endif
