//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at 
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - muls/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 28/11/2010
/// modified by jt the 26/03/2011
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
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/arithmetic/include/muls.hpp>

NT2_TEST_CASE_TPL ( muls_signed_int__2_0, (int64_t))//NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::muls;
  using nt2::tag::muls_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t; 
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT; 
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<muls_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<muls_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

  // random verifications
  static const uint32_t NR = NT2_NB_RANDOM_TEST; 
  {
    NT2_CREATE_BUF(tab_a0,T, NR, (nt2::Valmin<T>()/400), (nt2::Valmax<T>()/400));
    NT2_CREATE_BUF(tab_a1,T, NR, (nt2::Valmin<T>()/400), (nt2::Valmax<T>()/400));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      { 
        vT a0 = load<vT>(&tab_a0[0],j);   
        vT a1 = load<vT>(&tab_a1[0],j);
        r_t v = muls(a0,a1);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
	  std::cout << int64_t(tab_a0[k]) << " *  " << int64_t(tab_a1[k]) << " =  " << int64_t(v[i]) <<  " =  "
		    << int64_t(nt2::muls(tab_a0[k],tab_a1[k])) << std::endl; 
          NT2_TEST_EQUAL( v[i],ssr_t(nt2::muls(tab_a0[k],tab_a1[k])));
        }
      }   
      
  }
} // end of test for signed_int_  

// NT2_TEST_CASE_TPL ( muls_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
// {
//   using nt2::muls;
//   using nt2::tag::muls_; 
//   using nt2::load; 
//   using nt2::simd::native;
//   using nt2::meta::cardinal_of;
//   typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
//   typedef typename nt2::meta::upgrade<T>::type   u_t;
//   typedef native<T,ext_t>                        n_t;
//   typedef n_t                                     vT;
//   typedef typename nt2::meta::as_integer<T>::type iT;
//   typedef native<iT,ext_t>                       ivT;
//   typedef typename nt2::meta::call<muls_(vT,vT)>::type r_t;
//   typedef typename nt2::meta::call<muls_(T,T)>::type sr_t;
//   typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

//   // random verifications
//   static const uint32_t NR = NT2_NB_RANDOM_TEST;
//   {
//     NT2_CREATE_BUF(tab_a0,T, NR, 3*(nt2::Valmin<T>()/4), 3*(nt2::Valmax<T>()/4));
//     NT2_CREATE_BUF(tab_a1,T, NR, 3*(nt2::Valmin<T>()/4), 3*(nt2::Valmax<T>()/4));
//     double ulp0, ulpd ; ulpd=ulp0=0.0;
//     for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
//       {
//         vT a0 = load<vT>(&tab_a0[0],j);
//         vT a1 = load<vT>(&tab_a1[0],j);
//         r_t v = muls(a0,a1);
//         for(int i = 0; i< cardinal_of<n_t>::value; i++)
//         {
//           int k = i+j*cardinal_of<n_t>::value;
//           NT2_TEST_EQUAL( v[i],ssr_t(nt2::muls(tab_a0[k],tab_a1[k])));
//         }
//       }
    
//   }
// } // end of test for unsigned_int_
