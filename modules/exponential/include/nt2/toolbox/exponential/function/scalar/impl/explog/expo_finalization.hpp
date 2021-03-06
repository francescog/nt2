//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_IMPL_EXPLOG_EXPO_FINALIZATION_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_IMPL_EXPLOG_EXPO_FINALIZATION_HPP_INCLUDED
#include <nt2/core/numeric/function/fast_ldexp.hpp>
#include <nt2/core/numeric/function/fast_toint.hpp>
#include <nt2/core/numeric/function/select.hpp>
#include <nt2/core/numeric/function/is_flint.hpp>
#include <nt2/core/numeric/function/is_gtz.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0, class expo_tag, class speed_tag> struct exp_finalization{};
      
      template < class A0, class speed_tag> struct exp_finalization < A0, natural_tag, speed_tag> 
      {
	static inline A0 finalize(const A0&, const A0& x,
				  const A0& c, const A0 & k, 
				  const A0& hi,const A0& lo)
	{
	  A0 y =   oneminus(((lo-(x*c)/(Two<A0>()-c))-hi));
	  return fast_ldexp(y, fast_toint(k));
	}
      };
      template < class A0 > struct exp_finalization < A0, two_tag, fast_tag> 
      {
	static inline A0 finalize(const A0& a0, const A0& x,
				  const A0& c, const A0 & k, 
				  const A0& ,const A0& )
	{
	  A0 y = oneminus(((-(x*c)/(Two<A0>()-c))-x));
	  return fast_ldexp(y, fast_toint(k));
	}
      };
      template < class A0 > struct exp_finalization < A0, two_tag, accu_tag> 
      {
	static inline A0 finalize(const A0& a0, const A0& x,
				  const A0& c, const A0 & k, 
				  const A0& ,const A0& )
	{
	  A0 y = oneminus(((-(x*c)/(Two<A0>()-c))-x));
	  y = fast_ldexp(y, fast_toint(k));
	  // adjust for 2^n n flint
	  return select(b_and(isgtz(a0), isflint(a0)), round2even(y), y);
	}
      };
      
      template < class A0 > struct exp_finalization < A0, ten_tag, accu_tag> 
      {
	static inline A0 finalize(const A0& a0, const A0&  ,
				  const A0& c , const A0& k, 
				  const A0&   , const A0& )
	{
	  
	  A0 y = fast_ldexp(c, fast_toint(k));
	  //adjust for 10^n n flint
	  return select( b_and(isgtz(a0),  isflint(a0)) , round2even(y), y); 
	}
      }; 
      
    }	
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of expo_finalization.hpp
// /////////////////////////////////////////////////////////////////////////////
