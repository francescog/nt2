//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_CORRECT_FMA_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_CORRECT_FMA_HPP_INCLUDED
#include <nt2/include/functions/two_prod.hpp>
#include <nt2/include/functions/two_add.hpp>



/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::correct_fma_, tag::cpu_,
                             (A0)(A1)(A2),
                             (arithmetic_<A0>)(arithmetic_<A1>)(arithmetic_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::correct_fma_(tag::arithmetic_,tag::arithmetic_,tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> :
      meta::result_of<meta::arithmetic(A0,A1,A2)>{};

    NT2_FUNCTOR_CALL(3)
    {
       return a0*a1+a2;
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::correct_fma_, tag::cpu_,
                             (A0)(A1)(A2),
                             (real_<A0>)(real_<A1>)(real_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::correct_fma_(tag::real_,tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> :
      meta::result_of<meta::arithmetic(A0,A1,A2)>{};

    NT2_FUNCTOR_CALL(3)
    {
        A0 p, rp, s, rs;
        boost::fusion::tie(p, rp) = two_prod(a0, a1);
        boost::fusion::tie(s, rs) = two_add(p, a2);
        return s+(rp+rs);
	//         return ::fma(a0, a1, a2);
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::correct_fma_, tag::cpu_,
                             (A0)(A1)(A2),
                             (float_<A0>)(float_<A1>)(float_<A2>)
                            )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::correct_fma_(tag::float_,tag::float_,tag::float_),
              tag::cpu_, Dummy> : callable
  {
    typedef float result_type; 

    NT2_FUNCTOR_CALL(3)
    {
      return float(double(a0)*a1+a2); 
    }
  };
} }

#endif
// modified by jt the 26/12/2010
