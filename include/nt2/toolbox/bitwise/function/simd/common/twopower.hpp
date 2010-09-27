//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_TWOPOWER_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_COMMON_TWOPOWER_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/constant/properties.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/shli.hpp>
#include <nt2/include/functions/toint.hpp>
#include <nt2/include/functions/fast_ldexp.hpp>
#include <nt2/sdk/meta/adapted_traits.hpp>

namespace nt2 { namespace functors
{
  template<class Extension, class Info>
  struct validate<twopower_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> :
     meta::is_integral<A0>{};  
  };


  /////////////////////////////////////////////////////////////////////////////
  // Compute twopower(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<twopower_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (3, (int32_, uint64_t, real_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,       int32_)
    {
      typedef typename meta::scalar_of<A0>::type                      s_type;
      typedef typename meta::as_real<A0>::type                        f_type;
      typedef typename meta::scalar_of<f_type>::type                 sf_type;
      return simd::native_cast<A0>(
		  toint(simd::native_cast<f_type>(
			       simd::native_cast<A0>(Two<f_type>())
			       +shli(minusone(a0),
				     Nbmantissabits<sf_type>()
				     )
			       )
			)
		  ); 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1,       int64_)
    {
      return Zero<A0>(); 
    }

  };
} }

      
#endif