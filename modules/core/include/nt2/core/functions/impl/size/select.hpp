////////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
////////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_IMPL_SIZE_SELECT_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_IMPL_SIZE_SELECT_HPP_INCLUDED

#include <boost/mpl/if.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <boost/fusion/include/fold.hpp>

namespace nt2 { namespace details
{
  //////////////////////////////////////////////////////////////////////////////
  // Selects between two extents the smallest, non null one
  //////////////////////////////////////////////////////////////////////////////
  struct smallest_non_null
  {
    template<class Sig> struct result;

    template<class This, class State, class Element>
    struct result<This(State,Element)>
    {
      typedef typename nt2::meta::strip<State>::type                    state_;
      typedef typename nt2::meta::call<nt2::tag::size_(Element)>::type  esize_;
      typedef typename nt2::meta::strip<esize_>::type                   elem_;

      typedef typename
      boost::mpl::if_c<   (elem_::static_dimension <= state_::static_dimension)
                      ||  !state_::static_dimension
                      , esize_
                      , State
                      >::type type;
    };

    template<class State,class Element> inline
    typename result<smallest_non_null(State const&,Element const&)>::type
    operator()(State const& s,Element const& e) const
    {
      typedef typename nt2::meta::call<nt2::tag::size_(Element)>::type  esize_;
      typedef typename nt2::meta::strip<esize_>::type                   elem_;

      return eval ( s
                  , nt2::size(e)
                  , boost::mpl::bool_ < (   elem_::static_dimension
                                        <=  State::static_dimension
                                        )
                                        || !State::static_dimension
                                      >()
                  );
    }

    template<class S,class E> inline E const&
    eval(S const& ,E const& e, boost::mpl::true_ const&) const { return e; }
    template<class S,class E> inline S const&
    eval(S const& s,E const&, boost::mpl::false_ const&) const { return s; }
  };

  //////////////////////////////////////////////////////////////////////////////
  // Recursively explore an expression to return the smallest, non null size
  //////////////////////////////////////////////////////////////////////////////
  struct select_size : boost::proto::callable
  {
    template<class Sig> struct result;

    template<class This,class Expr>
    struct result<This(Expr)>
    {
      typedef typename boost::fusion::result_of::
              fold< typename nt2::meta::strip<Expr>::type const
                  , nt2::container::extent<0> const
                  , smallest_non_null
                  >::type                               type;
    };

    template<class Expr> inline
    typename result<select_size(Expr const)>::type
    operator()(Expr const& xpr) const
    {
      return boost::fusion::fold(xpr,of_size(),smallest_non_null());
    }
  };
} }

#endif
