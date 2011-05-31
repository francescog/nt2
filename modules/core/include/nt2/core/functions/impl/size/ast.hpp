////////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
////////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_IMPL_SIZE_AST_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_SIZE_AST_HPP_INCLUDED

#include <nt2/sdk/dsl/category.hpp>
#include <nt2/core/settings/size.hpp>
#include <nt2/core/functions/impl/size/select.hpp>

////////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is an expression
///////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH ( tag::size_, tag::cpu_
                      , (A0)(Dom)(Tag)(Sema)
                      , ((expr_<A0,Dom,Tag,Sema>))
                      )

namespace nt2 { namespace ext
{
  template<class Dom, class Tag, class Sema, class Dummy>
  struct  call< tag::size_(tag::expr_<Dom,Tag,Sema>)
              , tag::cpu_, Dummy
              >
        : callable
        , boost::proto::or_
          <
          // Terminals node has same size than their value
            boost::proto::when
            < boost::proto::nullary_expr<boost::proto::_,boost::proto::_>
            , boost::proto::call< functor<tag::size_> >(boost::proto::_value)
            >
            // Unary node has same size than their child
          , boost::proto::when
            < boost::proto::unary_expr<boost::proto::_,boost::proto::_>
            , boost::proto::call< functor<tag::size_> >(boost::proto::_child0)
            >
            // Other node return the size of their children with the smallest
            // non null extent
          , boost::proto::when
            < boost::proto::nary_expr < boost::proto::_
                                      , boost::proto::vararg<boost::proto::_>
                                      >
            , details::select_size(boost::proto::_)
            >
          >
  {};
} }

#endif
