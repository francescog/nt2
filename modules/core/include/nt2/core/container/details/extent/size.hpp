////////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
////////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_CONTAINER_DETAILS_EXTENT_SIZE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DETAILS_EXTENT_SIZE_HPP_INCLUDED

#include <nt2/sdk/meta/fusion.hpp>
#include <nt2/core/functions/size.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is an extent value
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH_TPL ( tag::size_, tag::cpu_
                          , (class A0)(std::size_t N)
                          , ((array_<arithmetic_<A0>,N>))
                          )

namespace nt2 { namespace ext
{
  template<std::size_t N, class Dummy>
  struct  call< tag::size_(tag::array_<tag::arithmetic_,N>)
              , tag::cpu_, Dummy
              >
        : callable
  {
    template<class Sig> struct result;

    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef containers::extent< of_size_<1,(N?N:2)> > type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type that;
      return that;
    }
  };
} }

#endif
