//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 exponential toolbox - nthroot/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// $testcat$ test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
/// modified by jt the 05/06/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/exponential/include/nthroot.hpp>
// specific includes for arity 2 tests
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/abs.hpp>

NT2_TEST_CASE_TPL ( nthroot_real__2_0,  NT2_REAL_TYPES)
{
  
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(10));
    NT2_CREATE_BUF(tab_a1,iT, NR, iT(-10), iT(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    iT a1;
    for (uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::nthroot(a0*nt2::sqr(a0),3),T(a0),1);
        ulp0=nt2::max(ulpd,ulp0);
        NT2_TEST_ULP_EQUAL( nt2::nthroot(nt2::sqr(a0),2),nt2::abs(a0),1);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( nthroot_signed_int__2_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for signed_int_

NT2_TEST_CASE_TPL ( nthroot_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
{
  
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for unsigned_int_