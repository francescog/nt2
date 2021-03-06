//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 exponential toolbox - nthroot/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of exponential components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
/// modified by jt the 07/04/2011
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
#include <nt2/toolbox/exponential/include/nthroot.hpp>

NT2_TEST_CASE_TPL ( nthroot_real__2_0,  NT2_REAL_TYPES)
{
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<nthroot_(vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(256),nt2::splat<ivT>(4))[0], T(4), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(8),nt2::splat<ivT>(3))[0], T(2), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Inf<vT>(),nt2::splat<ivT>(3))[0], nt2::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Inf<vT>(),nt2::splat<ivT>(4))[0], nt2::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Minf<vT>(),nt2::splat<ivT>(3))[0], nt2::Minf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Minf<vT>(),nt2::splat<ivT>(4))[0], nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Mone<vT>(),nt2::splat<ivT>(3))[0], nt2::Mone<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Mone<vT>(),nt2::splat<ivT>(4))[0], nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Nan<vT>(),nt2::splat<ivT>(3))[0], nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Nan<vT>(),nt2::splat<ivT>(4))[0], nt2::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::One<vT>(),nt2::splat<ivT>(3))[0], nt2::One<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::One<vT>(),nt2::splat<ivT>(4))[0], nt2::One<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Zero<vT>(),nt2::splat<ivT>(3))[0], nt2::Zero<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::Zero<vT>(),nt2::splat<ivT>(4))[0], nt2::Zero<sr_t>(), 0);
} // end of test for real_

NT2_TEST_CASE_TPL ( nthroot_sintgt_16__2_0,  (int32_t)(int64_t))
{
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<nthroot_(vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(-8),nt2::splat<ivT>(3))[0], sr_t(-2), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(256),nt2::splat<ivT>(4))[0], sr_t(4), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(8),nt2::splat<ivT>(3))[0], sr_t(2), 0);
} // end of test for sintgt_16_

NT2_TEST_CASE_TPL ( nthroot_uintgt_16__2_0,  (uint32_t)(uint64_t))
{
  using nt2::nthroot;
  using nt2::tag::nthroot_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<nthroot_(vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<nthroot_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(256),nt2::splat<ivT>(4))[0], sr_t(4), 0);
  NT2_TEST_ULP_EQUAL(nthroot(nt2::splat<vT>(8),nt2::splat<ivT>(3))[0], sr_t(2), 0);
} // end of test for uintgt_16_
