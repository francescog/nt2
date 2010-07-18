/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_FUNCTOR_DETAILS_IF_ELSE_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_DETAILS_IF_ELSE_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// if_else operators implementation
////////////////////////////////////////////////////////////////////////////////
#include <boost/typeof/typeof.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>

namespace nt2 { namespace functors
{
  template<class Category, class Info>
  struct validate<if_else_,Category, Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct  result<This(A0,A1,A2)> : boost::is_convertible<A0,bool> {};
  };

  template<class Category, class Info>
  struct call<if_else_,Category, Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)>
    {
      static A0& a0;  static A1& a1;  static A2& a2;
      BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested,a0 ? a1 : a2)
      typedef typename nested::type type;
    };

    NT2_FUNCTOR_CALL(3) { return a0 ? a1 : a2; }
  };
} }

#endif