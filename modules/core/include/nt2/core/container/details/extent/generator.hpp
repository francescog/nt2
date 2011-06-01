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
      typedef bool result_type;

      template<class Left, class Right>
      inline bool operator()(Left const& l, Right const& r) const
      {
        const std::size_t ls = nt2::size(l).size();
        const std::size_t rs = nt2::size(r).size();
        return (ls == rs) || !ls || !rs;
      }
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
    operator()(Expr const &xpr) const
    {
      //std::cout << "check is : " << check_size()(xpr) << "\n";
      typename result<generator(Expr)>::type const that(xpr);
      return that;
    }
  };
} }

#endif
