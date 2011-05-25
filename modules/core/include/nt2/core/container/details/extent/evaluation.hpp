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

#include <nt2/sdk/meta/as.hpp>
#include <nt2/sdk/dsl/compute.hpp>
#include <nt2/sdk/dsl/category.hpp>
#include <nt2/sdk/dsl/litteral.hpp>
#include <nt2/sdk/dsl/evaluation.hpp>

namespace nt2 { namespace meta
{
  template<class Target>
  struct  compute<tag::extent_,Target>
        : boost::proto::
          call< functor < tag::extent_
                        , Target
                        > ( boost::proto::_value
                          , boost::proto::_state
                          , boost::proto::_data
                          )
              >
  {};
}}

////////////////////////////////////////////////////////////////////////////////
// Register terminal handlers for SIMD expression - emulated case
////////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH_TPL (  tag::extent_,tag::cpu_
                          , (class A0)(class A1)(class A2)(std::size_t N)
                          , ((array_<arithmetic_<A0>,N>))
                            ((target_<array_<arithmetic_<A1>,N> >))
                            (integer_<A2>)
                          )

namespace nt2 { namespace ext
{
  template<class Dummy,std::size_t N>
  struct call<tag::extent_( tag::array_<tag::arithmetic_,N>
                          , tag::target_< tag::array_<tag::arithmetic_,N> >
                          , tag::integer_
                          ),tag::cpu_,Dummy>
  : callable
  {
    template<class Sig> struct result;

    template<class This, class Value, class State, class Data>
    struct result<This(Value,State,Data)>
    {
      typedef typename meta::strip<Value>::type::value_type  type;
    };

    template<class Value, class State, class Data> inline
    typename result<call(Value,State,Data)>::type
    operator()( Value& v, State& , Data& pos) const
    {
      return v[pos];
    }
  };
} }

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
