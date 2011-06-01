/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_GENERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_GENERATOR_HPP_INCLUDED

#include <nt2/core/functions/size.hpp>
#include <nt2/core/container/details/extent/validate.hpp>

namespace nt2 { namespace containers
{
  //////////////////////////////////////////////////////////////////////////////
  // Container Expression check if their size are compatible before being built
  // Depending on tag and types, a static or runtime assertion can be triggered
  //////////////////////////////////////////////////////////////////////////////
  template<class Dimension>
  struct generator<tag::extent_,Dimension>
  {
    template<class Sig> struct result;
    template<class This, class Expr>
    struct result<This(Expr)>
    {
      typedef container<Expr,tag::extent_,Dimension> type;
    };

    struct check : boost::proto::callable
    {
      template<class Sig> struct result;

      template<class This, class L, class R>
      struct result<This(L,R)>
      {
        typedef typename meta::call<tag::size_(L)>::type LHS;
        typedef typename meta::call<tag::size_(R)>::type RHS;
        typedef boost::mpl::
                bool_<  (LHS::static_dimensions == RHS::static_dimensions)
                      || !LHS::static_dimensions
                      || !RHS::static_dimensions
                      >                                     type;
      };

      template<class This, class A0, class A1, class A2>
      struct result<This(A0,A1,A2)>
      {
        typedef typename meta::call<tag::size_(A0)>::type A0S;
        typedef typename meta::call<tag::size_(A1)>::type A1S;
        typedef typename meta::call<tag::size_(A2)>::type A2S;
        typedef boost::mpl::
                bool_<(   (A0S::static_dimensions == A1S::static_dimensions)
                      &&  (A0S::static_dimensions == A2S::static_dimensions)
                      )
                      || !A0S::static_dimensions
                      || !A1S::static_dimensions
                      || !A2S::static_dimensions
                      >                                     type;
      };
    };

    struct  check_size
          : boost::proto::or_
            < boost::proto::when< boost::proto::
                                  nullary_expr<boost::proto::_,boost::proto::_>
                                , boost::mpl::true_()
                                >
            , boost::proto::when< boost::proto::
                                  unary_expr<boost::proto::_,boost::proto::_>
                                , boost::mpl::true_()
                                >
          , boost::proto::when< boost::proto::
                                binary_expr < boost::proto::_
                                            , boost::proto::_,boost::proto::_
                                            >
                              , check(boost::proto::_left,boost::proto::_right)
                              >
            >
    {};

    template<class Expr>
    typename result<generator(Expr)>::type const
    operator()(Expr const& xpr) const
    {
      typename boost::result_of<check_size(Expr const &)>::type ccc;
      std::cout << "check is : " << ccc << "\n";
      typename result<generator(Expr)>::type const that(xpr);
      std::cout << "check2 is : " << validate(that) << "\n";
      return that;
    }
  };
} }

#endif
