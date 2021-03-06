//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - divs/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 28/11/2010
/// modified by jt the 06/04/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/arithmetic/include/divs.hpp>

NT2_TEST_CASE_TPL ( divs_signed_int__2_0,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::divs;
  using nt2::tag::divs_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<divs_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<divs_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(divs(nt2::Mone<vT>(), nt2::Mone<vT>())[0], nt2::One<T>());
  NT2_TEST_EQUAL(divs(nt2::One<vT>(), nt2::One<vT>())[0], nt2::One<T>());
  NT2_TEST_EQUAL(divs(nt2::Valmax<vT>(),nt2::Mone<vT>())[0], nt2::Valmin<T>()+nt2::One<T>());
  NT2_TEST_EQUAL(divs(nt2::Valmax<vT>(),nt2::One<vT>())[0], nt2::Valmax<T>());
  NT2_TEST_EQUAL(divs(nt2::Valmin<vT>(),nt2::Mone<vT>())[0], nt2::Valmax<T>());
  NT2_TEST_EQUAL(divs(nt2::Zero<vT>(), nt2::Zero<vT>())[0], nt2::Zero<T>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( divs_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
{
  using nt2::divs;
  using nt2::tag::divs_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<divs_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<divs_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(divs(nt2::One<vT>(), nt2::One<vT>())[0], nt2::One<T>());
  NT2_TEST_EQUAL(divs(nt2::Valmax<vT>(),nt2::One<vT>())[0], nt2::Valmax<T>());
  NT2_TEST_EQUAL(divs(nt2::Zero<vT>(), nt2::Zero<vT>())[0], nt2::Zero<T>());
} // end of test for unsigned_int_
