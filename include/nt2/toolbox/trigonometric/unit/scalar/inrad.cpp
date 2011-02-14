//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - inrad/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
/// modified by jt the 14/02/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/trigonometric/include/inrad.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/trigonometric/include/constants.hpp>

NT2_TEST_CASE_TPL ( inrad_real__1,  NT2_REAL_TYPES)
{
  using nt2::inrad;
  using nt2::tag::inrad_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<inrad_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  inrad(-nt2::_180<T>()), -nt2::Pi<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(-nt2::_45<T>()), -nt2::Pi<r_t>()/4, 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(-nt2::_90<T>()), -nt2::Pio_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Inf<T>()), nt2::Inf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Minf<T>()), nt2::Minf<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Nan<T>()), nt2::Nan<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_180<T>()), nt2::Pi<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_45<T>()), nt2::Pi<r_t>()/4, 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_90<T>()), nt2::Pio_2<r_t>(), 0.5);
  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_SCALAR_BUFFER(a0,T, NR, T(-2000), T(2000));
    double ulp0 = 0.0, ulpd = 0.0;
    for (int j =0; j < NR; ++j )
      {
        std::cout << "for param "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::inrad(a0),a0*nt2::Pi<T>()/nt2::_180<T>(),1.0);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for real_

NT2_TEST_CASE_TPL ( inrad_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::inrad;
  using nt2::tag::inrad_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<inrad_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_180<T>()), nt2::Pi<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_45<T>()), nt2::Pi<r_t>()/4, 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_90<T>()), nt2::Pio_2<r_t>(), 0.5);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( inrad_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::inrad;
  using nt2::tag::inrad_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<inrad_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;


  // specific values tests
  NT2_TEST_ULP_EQUAL(  inrad(-nt2::_45<T>()), -nt2::Pi<r_t>()/4, 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(-nt2::_90<T>()), -nt2::Pio_2<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::Zero<T>()), nt2::Zero<r_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_45<T>()), nt2::Pi<r_t>()/4, 0.5);
  NT2_TEST_ULP_EQUAL(  inrad(nt2::_90<T>()), nt2::Pio_2<r_t>(), 0.5);
} // end of test for signed_int_