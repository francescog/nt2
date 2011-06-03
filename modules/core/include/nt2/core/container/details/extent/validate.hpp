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

#include <boost/typeof/typeof.hpp>
#include <nt2/sdk/dsl/litteral.hpp>
#include <nt2/sdk/dsl/validate.hpp>

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
            // Other node are valid if they are all of same dimensions
            // or any is of dimension 0
          , boost::proto::when
            < boost::proto::nary_expr < boost::proto::_
                                      , boost::proto::vararg<boost::proto::_>
                                      >
            , details::valid_extent(boost::proto::_)
            >
          >
  {};
} }

namespace nt2 { namespace details
{
  struct valid_extent : boost::proto::callable
  {
    template<class Base>
    struct same_dim_
    {
      template<class Sig> struct result;

      template<class This, class State, class Element>
      struct result<This(State,Element)>
      {
        typedef typename meta::strip<State>::type                   st;
        typedef typename meta::strip<Element>::type                   base;
        typedef typename meta::call<tag::size_(base)>::type curr;
        typedef typename boost::mpl::bool_<   Base::static_dimensions
                                          ==  curr::static_dimensions
                                          >                               val;
        typedef boost::mpl::and_<st,val> type;
      };
    };

    struct some0
    {
      template<class Sig> struct result;

      template<class This, class State, class Element>
      struct result<This(State,Element)>
      {
        typedef typename meta::strip<State>::type                     st;
        typedef typename meta::strip<Element>::type                   base;
        typedef typename meta::call<tag::size_(base)>::type           curr;
        typedef typename boost::mpl::bool_<!curr::static_dimensions>  val;
        typedef boost::mpl::or_<st,val>                               type;
      };
    };

    template<class T> static same_dim_<T> same_dim(T const&);

    template<class Sig> struct result;

    template<class This, class Seq>
    struct result<This(Seq)>
    {
      static typename meta::strip<Seq>::type const& seq;

      BOOST_TYPEOF_NESTED_TYPEDEF_TPL
      ( alls
      , boost::fusion::fold ( seq
                            , boost::mpl::true_()
                            , same_dim(nt2::size(boost::fusion::at_c<0>(seq)))
                            )
      );

      BOOST_TYPEOF_NESTED_TYPEDEF_TPL
      ( anys
      , boost::fusion::fold ( seq
                            , boost::mpl::false_()
                            , some0()
                            )
      );

      typedef boost::mpl::or_<typename alls::type, typename anys::type> type;
    };

    template<class Seq> inline
    typename result<valid_extent(Seq const&)>::type
    operator()(Seq const& ) const
    {
      typename result<valid_extent(Seq const&)>::type that;
      return that;
    }
  };
} }

#endif
