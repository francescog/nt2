//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_INFINITE_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SCALAR_IS_NOT_INFINITE_HPP_INCLUDED
#include <nt2/include/constants/infinites.hpp>
#include <nt2/sdk/details/ignore_unused.hpp>

#include <nt2/include/functions/abs.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_infinite_, tag::cpu_,
                                 (A0),
                                 (arithmetic_<A0>)
                                )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_infinite_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
      ignore_unused(a0);
      return true;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::is_not_infinite_, tag::cpu_,
                                 (A0),
                                 (real_<A0>)
                                )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::is_not_infinite_(tag::real_),
              tag::cpu_, Dummy> : callable
  {
    typedef bool result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return  nt2::abs(a0) != Inf<A0>();
    }
  };
} }

#endif
// modified by jt the 26/12/2010