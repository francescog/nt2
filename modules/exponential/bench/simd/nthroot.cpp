//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 exponential toolbox - nthroot/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of exponential components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/exponential/include/nthroot.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<nthroot_> from exponential
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::nthroot_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,T(0),T(10)))(RS(viT,iT(-10),iT(10))))
}
namespace n2 {
  typedef double T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,T(0),T(10)))(RS(viT,iT(-10),iT(10))))
}
namespace n3 {
  typedef nt2::int32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,-100,100))(RS(viT,-100,100)))
}
namespace n4 {
  typedef nt2::int64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,-100,100))(RS(viT,-100,100)))
}
namespace n5 {
  typedef nt2::uint32_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,0,100))(RS(viT,0,100)))
}
namespace n6 {
  typedef nt2::uint64_t T;
  typedef nt2::meta::as_integer<T>::type iT;
  typedef nt2::simd::native<T,ext_t> vT;
  typedef nt2::simd::native<iT,ext_t> viT;
  NT2_TIMING(nthroot_,(RS(vT,0,100))(RS(viT,0,100)))
}

#undef RS
