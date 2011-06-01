/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_VALIDATE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_VALIDATE_HPP_INCLUDED

#include <nt2/sdk/dsl/litteral.hpp>
#include <nt2/sdk/dsl/validate.hpp>
#include <nt2/core/container/details/extent/call.hpp>

namespace nt2 { namespace details { struct valid_extent; } }

////////////////////////////////////////////////////////////////////////////////
// Evaluation strategy for extent class
////////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH (  tag::validate_,tag::cpu_
                      , (A0)(Tag)(Sema0)(D0)
                      , ((expr_ < A0
                                , domain_<containers::domain<tag::extent_,D0> >
                                , Tag, Sema0
                                >
                        ))
                      )

namespace nt2 { namespace ext
{
  template<class Tag, class Sema, class D, class Dummy>
  struct  call< tag::validate_
                ( tag::expr_< containers::domain<tag::extent_,D>, Tag, Sema> )
              , tag::cpu_, Dummy
              >
        : callable
        , boost::proto::or_
          <
            // Terminals nodes are always valid
            boost::proto::when
            < boost::proto::nullary_expr<boost::proto::_,boost::proto::_>
            , boost::mpl::true_()
            >
            // Unary nodes are always valid
          , boost::proto::when
            < boost::proto::unary_expr<boost::proto::_,boost::proto::_>
            , boost::mpl::true_()
            >
            // Other node return the size of their children with the smallest
            // non null extent
          , boost::proto::when
            < boost::proto::nary_expr < boost::proto::_
                                      , boost::proto::vararg<boost::proto::_>
                                      >
            , details::valid_extent(boost::proto::functional::flatten(boost::proto::_))
            >
          >
  {};
} }

namespace nt2 { namespace details
{
  struct valid_extent : boost::proto::callable
  {
    typedef boost::mpl::true_ result_type;

    template<class Seq> inline
    result_type operator()(Seq const& s) const
    {
      result_type that;
      return that;
    }
  };
} }

#endif
