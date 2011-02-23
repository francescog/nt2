//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 elliptic toolbox - ellipke/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of elliptic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 21/02/2011
/// modified by jt the 21/02/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/elliptic/include/ellipke.hpp>
#include <boost/fusion/tuple.hpp>
// specific includes for arity 1 tests
extern "C" {long double cephes_ellikl(long double,long double);}
#include <nt2/toolbox/trigonometric/include/constants.hpp>
#include <boost/fusion/tuple.hpp>
// specific includes for arity 2 tests
extern "C" {long double cephes_ellikl(long double,long double);}
#include <nt2/toolbox/trigonometric/include/constants.hpp>

NT2_TEST_CASE_TPL ( ellipke_real__1,  NT2_REAL_TYPES)
{
  using nt2::ellipke;
  using nt2::tag::ellipke_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<ellipke_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
  typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
  {
    r_t res = ellipke(nt2::One<T>());
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(res), nt2::One<r_t0>(), 0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(res), nt2::One<r_t1>(), 0);
  }
  {
    r_t res = ellipke(nt2::Zero<T>());
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(res), nt2::Zero<r_t0>(), 0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(res), nt2::Zero<r_t1>(), 0);
  }
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(1));
    double ulp0 = 0.0, ulpd = 0.0;
    T a0;
    for (int j =0; j < NR; ++j ) 
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        r_t r = nt2::ellipke(a0);  
       typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
        r_t0 r0 = boost::fusion::get<0>(r);
        r_t1 r1 = boost::fusion::get<1>(r);
	  std::cout << a0 << "         " << std::endl; 
	  std::cout << r0 << "         " << r1 << std::endl; 
         NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(r), boost::fusion::get<0>(r), 1.0);
        NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(r), boost::fusion::get<1>(r), 1.0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( ellipke_real__2,  NT2_REAL_TYPES)
{
  using nt2::ellipke;
  using nt2::tag::ellipke_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<ellipke_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
  typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
  {
    r_t res = ellipke(nt2::One<T>(),0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(res), nt2::One<r_t0>(), 0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(res), nt2::One<r_t1>(), 0);
  }
  {
    r_t res = ellipke(nt2::Zero<T>(),0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(res), nt2::Zero<r_t0>(), 0);
    NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(res), nt2::Zero<r_t1>(), 0);
  }
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(1));
    NT2_CREATE_BUF(tab_a1,T, NR, T(0), T(0.01));
    double ulp0 = 0.0, ulpd = 0.0;
    T a0,a1;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        r_t r = nt2::ellipke(a0,a1);
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,0>::type>::type r_t0;
        typedef typename nt2::meta::strip<typename boost::fusion::result_of::at_c<r_t,1>::type>::type r_t1;
        r_t0 r0 = boost::fusion::get<0>(r);
        r_t1 r1 = boost::fusion::get<1>(r);
	  std::cout << a0 << "         " << a1 << std::endl; 
	  std::cout << r0 << "         " << r1 << std::endl; 
        NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(r),  boost::fusion::get<0>(r), 1.0);
        NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(r),  boost::fusion::get<1>(r), 1.0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_