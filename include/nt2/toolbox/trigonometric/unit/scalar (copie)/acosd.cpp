//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - unit/scalar Mode"

#include <nt2/sdk/functor/meta/call.hpp> 
#include <boost/type_traits/is_same.hpp>
#include <nt2/toolbox/trigonometric/include/acosd.hpp> 
#include <nt2/sdk/unit/tests.hpp> 
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <iostream>
 
//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components using NT2_TEST_CASE
//////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL ( acosd, (double) 
		    (float) 
		    ) 
{
  using nt2::acosd;
  using nt2::functors::acosd_;
  const int N = 1; 
  NT2_TEST( (boost::is_same < typename nt2::meta::call<acosd_(T)>::type
	     , T
 	     >::value)
    );
  typedef typename boost::result_of<nt2::meta::floating(T)>::type r_t; 
  NT2_TEST_EQUAL(  acosd( T(0) )  , 90 );
  NT2_TEST_EQUAL(  acosd( T(1) )  , 0 );
  NT2_TEST_EQUAL(  acosd( T(-1) )  , 180 );
  NT2_TEST_LESSER(  nt2::ulpdist(acosd( T(0.5) ), 60), 1); 
  NT2_TEST_LESSER( nt2::ulpdist(acosd( T(-0.5) ), 120), 1); 

}

