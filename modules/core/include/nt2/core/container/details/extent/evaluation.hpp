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
NT2_REGISTER_DISPATCH (  tag::evaluate_,tag::cpu_
                      , (A0)(Sema0)(A1)(Tag)(Sema1)
                      , ((expr_ < A0
                                , domain_ < containers::
                                            domain< tag::extent_
                                                  , boost::mpl::size_t<2>
                                                  >
                                          >
                                , tag::extent_, Sema0
                                >
                        ))
                        ((expr_ < A1
                                , domain_ < containers::
                                            domain< tag::extent_
                                                  , boost::mpl::size_t<2>
                                                  >
                                          >
                                , Tag, Sema1
                                >
                        ))
                          )

namespace nt2 { namespace ext
{
  template<class Tag, class Sema0, class Sema1, class Dummy>
  struct call < tag::evaluate_
                ( tag::expr_<containers::domain < tag::extent_
                                                , boost::mpl::size_t<2>
                                                >
                            , tag::extent_, Sema0
                            >
                , tag::expr_<containers::domain < tag::extent_
                                                , boost::mpl::size_t<2>
                                                >
                            , Tag, Sema1
                            >
                )
              , tag::cpu_, Dummy
              > : callable
  {
    typedef void result_type;

    template<class A0, class A1> inline void
    operator()( A0& a0, A1 const& a1) const
    {
      meta::as_<typename A0::data_type>                         target;
      meta::compile< meta::compute<boost::mpl::_1,tag::cpu_> >  callee;

      // Who's bigger ?
      std::size_t r_size = nt2::size(a1)(1);
      std::size_t l_size = a0.size();

      NT2_ASSERT((l_size >= r_size) && "Size mismatch in extent evaluation");

      // Fill the common part of the extent
      for(std::size_t i=0;i<r_size;++i)
        boost::proto::value(a0)[i] = callee(a1,target,i);

      // Fill the remaining with 1
      for(std::size_t i=r_size;i<l_size;++i)
              boost::proto::value(a0)[i] = 1;
    }
  };
} }
#endif
