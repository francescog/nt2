//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - fast_sincosd/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
/// modified by jt the 14/02/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/trigonometric/include/fast_sincosd.hpp>

NT2_TEST_CASE_TPL ( fast_sincosd_real_convert__1,  NT2_REAL_CONVERTIBLE_TYPES)
{
  using nt2::fast_sincosd;
  using nt2::tag::fast_sincosd_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename boost::result_of<nt2::meta::floating(T)>::type ftype;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<fast_sincosd_(vT)>::type r_t;
  typedef typename nt2::meta::call<fast_sincosd_(T)>::type sr_t;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename boost::result_of<nt2::meta::floating(T)>::type ftype;
    NT2_CREATE_SIMD_BUFFER(a0,T, NR, T(-45), T(45));
    double ulp0 = 0.0, ulpd = 0.0;
    for(int j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<n_t>(&tab_a0[0],j);
        r_t r = nt2::fast_sincosd(a0);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          sr_t sr =  nt2::fast_sincosd(tab_a0[k]);
          NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<0>(r)[i],
                                    boost::fusion::get<0>(sr), 0.5);
          NT2_TEST_TUPLE_ULP_EQUAL( boost::fusion::get<1>(r)[i],
                                    boost::fusion::get<1>(sr), 0.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl; 
  }
} // end of test for real_convert_